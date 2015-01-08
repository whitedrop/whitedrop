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

        std::map<int, string_couple>::const_iterator pos = mLODs.find(i);
        if (pos == mLODs.end()) {
            return(std::make_pair<std::string, std::string>("",""));
        } else {
             string_couple value = pos->second;

             return value;
        }

        // return mLODs.find(i)->second;

    }
    string_couple ObjectData::operator [](int i) const {
        return mLODs.find(i)->second;
    }
}
