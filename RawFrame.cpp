//
// Created by DELL on 2/2/2023.
//

#include "RawFrame.h"
#include "PacketFileWriter.h"

RawFrame::RawFrame(std::string &type) {
    this->setType(type);
}

void RawFrame::writeToFile(std::ofstream &file) {
    PacketFileWriter pfw;
    pfw.writeRawFrame(file, *this);
}


