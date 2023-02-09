//
// Created by DELL on 2/5/2023.
//

#include "PacketFileWriter.h"

int PacketFileWriter::counter = 0;

void PacketFileWriter::writeECPRIFrame(std::ofstream &file, ECPRIFrame &ecpriFrame) {
    file
            << "**************************************************************************************************************************************************************************************************************************************\n";
    file << "Packet #" << counter << "\n";
    file << "Type: " << ecpriFrame.getType() << "\n";
    file << "CRC: " << ecpriFrame.getCrc() << "\n";
    file << "Concatenation Indicator: " << ecpriFrame.getConcatenationIndicator() << "\n";
    file << "Destination Address: " << ecpriFrame.getDestinationAddress() << "\n";
    file << "Source Address: " << ecpriFrame.getSourceAddress() << "\n";
    file << "Protocol Version: " << ecpriFrame.getProtocolVersion() << "\n";
    file << "Message Type: " << ecpriFrame.getMessageType() << "\n";
    file << "Payload Size: " << ecpriFrame.getPayloadSize() << "\n";
    file << "RTC ID: " << ecpriFrame.getRtcId() << "\n";
    file << "Sequence ID: " << ecpriFrame.getSequenceId() << "\n";
    counter++;
}

void PacketFileWriter::writeRawFrame(std::ofstream &file, RawFrame &rawFrame) {
    file
            << "**************************************************************************************************************************************************************************************************************************************\n";
    file << "Packet #" << counter << "\n";
    file << "Type: " << rawFrame.getType() << "\n";
    file << "CRC: " << rawFrame.getCrc() << "\n";
    file << "Destination Address: " << rawFrame.getDestinationAddress() << "\n";
    file << "Source Address: " << rawFrame.getSourceAddress() << "\n";
    counter++;
}
