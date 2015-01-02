#include "../include/LOD.h"


namespace Whitedrop {
	LevelOfDetail::LevelOfDetail()
	{
		mLOD = 0;
	}
	LevelOfDetail::LevelOfDetail(LODDistance dist)
	{
		int level = round(10 - exp(dist.distance * getLODFactor()));
		if( level < 0 )
			level = 0;
		if( level > 10 )
			level = 10;
		mLOD = level;
	}
	LevelOfDetail::LevelOfDetail(LODIndex index)
	{
		int level = round(index.index);
		if( level < 0 )
			level = 0;
		if( level > 10 )
			level = 10;
		mLOD = level;
	}
	LevelOfDetail::~LevelOfDetail()
	{
	}

	int LevelOfDetail::getIndex()
	{
		return mLOD;
	}

	bool LevelOfDetail::operator< (const LevelOfDetail& b) const
	{
		return mLOD < b.mLOD;
	}

	bool LevelOfDetail::operator<= (const LevelOfDetail& b) const
	{
		return mLOD <= b.mLOD;
	}

	bool LevelOfDetail::operator> (const LevelOfDetail& b) const
	{
		return mLOD > b.mLOD;
	}

	bool LevelOfDetail::operator>= (const LevelOfDetail& b) const
	{
		return mLOD >= b.mLOD;
	}

	bool LevelOfDetail::operator== (const LevelOfDetail& b) const
	{
		return mLOD == b.mLOD;
	}

	bool LevelOfDetail::operator!= (const LevelOfDetail& b) const
	{
		return mLOD != b.mLOD;
	}


}