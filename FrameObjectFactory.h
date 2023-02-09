//
// Created by DELL on 2/3/2023.
//

#ifndef A1_FRAMEOBJECTFACTORY_H
#define A1_FRAMEOBJECTFACTORY_H

#include "ECPRIFrame.h"
#include "RawFrame.h"

class FrameObjectFactory {
public:
    static Frame *createFrameObject(Frame_Type frameType,std::string frameTypeCode);
};


#endif //A1_FRAMEOBJECTFACTORY_H
