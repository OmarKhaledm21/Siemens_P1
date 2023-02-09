//
// Created by DELL on 2/3/2023.
//

#include "FrameObjectFactory.h"

Frame *FrameObjectFactory::createFrameObject(Frame_Type frameType, std::string frameTypeCode) {
    if (frameType == ECPRI) {
        return new ECPRIFrame(frameTypeCode);
    } else if (frameType == RAW) {
        return new RawFrame(frameTypeCode);
    }
    return nullptr;
}
