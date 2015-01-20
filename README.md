
Whitedrop Engine
===============

The Whitedrop engine is an open source 3D Game engine based on, for the official release, **OGRE** and **PhysX**. It aims at providing  a complete API for thos who want to create game with javascript (usingV8), Lua (LuaJIT) and C# (Mono).

- [Whitedrop structure](#whitedrop-structure)
- [Getting the documentation](#getting-the-documentation)
- [Frequently Asked Question](#frequently-asked-question)
    - [It's not the first attempt. How should it succeed when others failed?](#its-not-the-first-attempt-how-should-it-succeed-when-others-failed)
    - [When will this get finished?](#when-will-this-get-finished)
- [Implemented/not implemented](#implementednot-implemented)
    - [Fully Implemented features](#fully-implemented-features)
    - [Partially implemented](#partially-implemented)
    - [Not implemented yet](#not-implemented-yet)
- [License and Copyright](#license-and-copyright)
- [Contact](#contact)

## Whitedrop structure

 - The Core Engine. The part that stands between OGRE and the rest. Located at `engine`. namespace `WhitedropEngine`
 - *Quantum Engine. The physic engine, it's a wrapper so we don't rely on one third-party physic engine and we avoid coupling.*
 - Scribe Engine.  The scripting engine the "talks" with V8, Mono or LuaJIT. Namespace `Scribe`
 - *Adaggio Engine. The sound engine*
 - *Quark Engine. The particule engine*

*Not implemented*

## Getting the documentation

You can use Doxygen to automatically generate docs. I'll add the Dox file soon

## Frequently Asked Question

### It's not the first attempt. How should it succeed when others failed?

To answer this question, I'm going to list the common reason of failures:

 - Lack of good resources to learn
 - Lack of good game that shows the engine's possibilities

What made the success of other engines?

 - Good documentation
 - Highly-used engine with a lot of big and great games
 - Support of C# in Unity for instance

At first the engine was created to solve a problem: I wanted to makje an pen-source game but first I needed an engine, and UE or Unity's Licenses did not permit this. So I'll try to make my game - which wil help dev.

### When will this get finished?

Never I hope :D. The main point of open source is that the game and its engine should improve over time and keep up to date. So if you want to know when will 1.0.0 release will be on, I'll answer: don't be n a hurry ;)

## Implemented/not implemented
### Fully Implemented features

### Partially implemented

 - Terrain management
 - Map support
 - Static entites
 - Shaders

### Not implemented yet

 - Dynamic entites using PhysX
 - Input Management
 - Mesh animations
 - Scripting
 - Volumetric fogs
 - Dynamic shadows

##  License and Copyright

See LICENSE

## Contact

Use our mail whitedropengine[at]gmail[dot]com
Or you can contact the author at vinz243[at]gmail[dot]com
