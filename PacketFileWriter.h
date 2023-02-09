//
// Created by DELL on 2/5/2023.
//

#ifndef A1_PACKETFILEWRITER_H
#define A1_PACKETFILEWRITER_H

#include <fstream>
#include "ECPRIFrame.h"
#include "RawFrame.h"

class PacketFileWriter {
    static int counter;
public:
    void writeECPRIFrame(std::ofstream &file, ECPRIFrame &ecpriFrame);

    void writeRawFrame(std::ofstream &file, RawFrame &rawFrame);
};


#endif //A1_PACKETFILEWRITER_H
