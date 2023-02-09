//
// Created by DELL on 2/2/2023.
//

#include "PacketAnalyzer.h"
#include "ECPRIFrame.h"
#include "RawFrame.h"
#include "FrameObjectFactory.h"

using namespace std;

void PacketAnalyzer::analyzePackets(vector<string> &packets)
{

    for (size_t i = 0; i < packets.size(); i++)
    {
        Frame *frame = parseFrame(packets[i]);
        this->frames.push_back(frame);
    }
}

Frame *PacketAnalyzer::parseFrame(string &frame_string)
{
    Frame *frame = nullptr;
    int stringPointerIndex = 0;

    string preamble = extractPreamble(frame_string, stringPointerIndex, Frame::getPreambleFieldLength());

    string destAddress = extractDestinationAddress(frame_string, stringPointerIndex, Frame::getDestFieldLength());

    string sourceAddress = extractSourceAddress(frame_string, stringPointerIndex, Frame::getSrcFieldLength());

    Frame_Type frameType = extractFrameTypeFromHEX(frame_string, stringPointerIndex);

    string frameTypeCode = getStringType(frameType);

    string crc = extractCRC(frame_string, Frame::getCrcFieldLength());

    frame = FrameObjectFactory::createFrameObject(frameType, frameTypeCode);

    frame->setPreamble(preamble);
    frame->setDestinationAddress(destAddress);
    frame->setSourceAddress(sourceAddress);
    frame->setCrc(crc);

    if (frameType == ECPRI)
    {
        extractFramePayload(*dynamic_cast<ECPRIFrame *>(frame), frame_string, stringPointerIndex);
    }
    else
    {
        extractFramePayload(*dynamic_cast<RawFrame *>(frame), frame_string, stringPointerIndex);
    }

    return frame;
}

void PacketAnalyzer::extractFramePayload(ECPRIFrame &frame, string &frame_string, int &stringPointerIndex)
{

    frame.setProtocolVersion(frame_string.substr(stringPointerIndex, frame.getProtocolVerFieldLength()));
    stringPointerIndex += frame.getProtocolVerFieldLength();

    frame.setConcatenationIndicator(
        frame_string.substr(stringPointerIndex, frame.getConcIndicatorFieldLength()));
    stringPointerIndex += frame.getConcIndicatorFieldLength();

    frame.setMessageType(frame_string.substr(stringPointerIndex, frame.getMessageTypeFieldLength()));
    stringPointerIndex += frame.getMessageTypeFieldLength();

    frame.setPayloadSize(frame_string.substr(stringPointerIndex, frame.getPayloadSizeFieldLength()));
    stringPointerIndex += frame.getPayloadSizeFieldLength();

    frame.setRtcId(frame_string.substr(stringPointerIndex, frame.getRtcIdFieldLength()));
    stringPointerIndex += frame.getRtcIdFieldLength();

    frame.setSequenceId(frame_string.substr(stringPointerIndex, frame.getSeqIdFieldLength()));
}

string PacketAnalyzer::extractCRC(string &frame_string, int SIZE)
{
    string crc = frame_string.substr(frame_string.length() - SIZE, SIZE);
    return crc;
}

string PacketAnalyzer::extractSourceAddress(string &frame_string, int &stringPointerIndex, int SIZE)
{
    string sourceAddress = frame_string.substr(stringPointerIndex, SIZE);
    stringPointerIndex += SIZE;
    return sourceAddress;
}

string PacketAnalyzer::extractDestinationAddress(string &frame_string, int &stringPointerIndex, int SIZE)
{
    string destAddress = frame_string.substr(stringPointerIndex, SIZE);
    stringPointerIndex += SIZE;
    return destAddress;
}

string PacketAnalyzer::extractPreamble(string &frame_string, int &stringPointerIndex, int SIZE)
{
    string preamble = frame_string.substr(stringPointerIndex, SIZE);
    stringPointerIndex += SIZE;
    return preamble;
}

Frame_Type PacketAnalyzer::extractFrameTypeFromHEX(string &frame_string, int &stringPointerIndex)
{
    const int SIZE = (2 * 8) / 4;

    string frame_type_code = frame_string.substr(stringPointerIndex, SIZE);
    stringPointerIndex += SIZE;
    if (frame_type_code == "AEFE")
    {
        return ECPRI;
    }
    else if (frame_type_code == "88F7")
    {
        return RAW;
    }
}

string PacketAnalyzer::getStringType(Frame_Type eType)
{
    if (eType == ECPRI)
    {
        return "AEFE";
    }
    else if (eType == RAW)
    {
        return "88F7";
    }
}

Frame_Type PacketAnalyzer::convertStringTypeToEnum(string type)
{
    if (type == "AEFE")
    {
        return ECPRI;
    }
    else if (type == "88F7")
    {
        return RAW;
    }
}

void PacketAnalyzer::extractFramePayload(RawFrame &frame, string &frame_string, int &stringPointerIndex)
{
    // No Parsing to do for raw frame.
}

void PacketAnalyzer::writePacketData(const std::string &file_name)
{
    ofstream output_file;
    output_file.open(file_name);
    for (Frame *frame : this->frames)
    {
        frame->writeToFile(output_file);
    }
    output_file.close();
}
