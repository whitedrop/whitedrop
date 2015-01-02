#include "../include/ObjectData.h"

namespace Whitedrop {
    ObjectData::ObjectData()
    {

    }

    ObjectData::ObjectData(std::map<int, string_couple> lods)
    {
    	mLODs = lods;

    }

	ObjectData::~ObjectData()
	{

	}

    string_couple ObjectData::get(int i) {
        return mLODs.find(i)->second;
    }
    string_couple ObjectData::operator [](int i) const {
        return mLODs.find(i)->second;
    }
}
