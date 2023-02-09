//
// Created by DELL on 2/2/2023.
//

#ifndef A1_PACKETANALYZER_H
#define A1_PACKETANALYZER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Frame.h"
#include "RawFrame.h"
#include "ECPRIFrame.h"

using namespace std;

class PacketAnalyzer
{
private:
    vector<Frame *> frames;

public:
    PacketAnalyzer() {}

    void analyzePackets(vector<string> &packets);

    Frame_Type extractFrameTypeFromHEX(string &frame_string, int &stringPointerIndex);

    string extractPreamble(string &frame_string, int &stringPointerIndex, int SIZE);

    string extractDestinationAddress(string &frame_string, int &stringPointerIndex, int SIZE);

    string extractSourceAddress(string &frame_string, int &stringPointerIndex, int SIZE);

    string extractCRC(string &frame_string, int SIZE);

    void extractFramePayload(RawFrame &frame, string &frame_string, int &stringPointerIndex);

    void extractFramePayload(ECPRIFrame &frame, string &frame_string, int &stringPointerIndex);

    string getStringType(Frame_Type eType);
    Frame_Type convertStringTypeToEnum(string type);

    Frame *parseFrame(string &frame_string);

    void writePacketData(const string &file_name);
};

#endif // A1_PACKETANALYZER_H
