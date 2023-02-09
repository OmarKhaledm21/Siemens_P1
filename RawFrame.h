//
// Created by DELL on 2/2/2023.
//

#ifndef A1_RAWFRAME_H
#define A1_RAWFRAME_H
#include "Frame.h"

class RawFrame : public Frame{
public:
    RawFrame(std::string& type);

    void writeToFile(std::ofstream &file) override;
};


#endif //A1_RAWFRAME_H
