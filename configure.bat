@echo off

echo.
echo This batch is going to clone and build whitedrop dependencies,
echo such as OGRE and its deps, io.js, Bullet...
echo.
echo This may take a long time, from 30 min to several hours
echo according to your hardware and network
echo.

if %* == "" (
	echo No build tool was specified. Please enter one directly with the bat.
	echo Example: configure "Visual Studio 12 2013"
	echo.
	echo Configure failed. Exiting...
	goto end
)
echo Selected build tool is %*.
pause

mkdir third_party
cd third_party

hg clone https://bitbucket.org/cabalistic/ogredeps

cd ogredeps

cmake -G %* -D CMAKE_INSTALL_PREFIX=%~dp0/third_party/ogredeps/install ./

cmake --build ./ --target ALL_BUILD
cmake --build ./ --target INSTALL

cd ../

hg clone http://bitbucket.org/sinbad/ogre/ -u v1-9

cd ogre
cmake -G %* -D OGRE_DEPENDENCIES_DIR=%~dp0/third_party/ogredeps/install -D CMAKE_INSTALL_PREFIX=%~dp0/third_party/ogre/dist ./

cmake --build ./ --target ALL_BUILD
cmake --build ./ --target INSTALL

cd ../

git clone https://github.com/whitedrop/io.js.git

cd io.js

git pull
git checkout working
git pull

vcbuild debug nosign
@rem cd ../

@rem call svn co http://svn.boost.org/svn/boost/tags/release/Boost_1_55_0 boost

@rem cd boost
@rem @rem call .\bootstrap.bat --with-libraries=program_options,system
@rem call .\b2

cd ../../

:end