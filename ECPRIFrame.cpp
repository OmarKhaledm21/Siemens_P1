//
// Created by DELL on 2/2/2023.
//

#include "ECPRIFrame.h"
#include "PacketFileWriter.h"

const std::string &ECPRIFrame::getConcatenationIndicator() const {
    return concatenationIndicator;
}

const std::string &ECPRIFrame::getMessageType() const {
    return messageType;
}

const std::string &ECPRIFrame::getPayloadSize() const {
    return payloadSize;
}

const std::string &ECPRIFrame::getProtocolVersion() const {
    return protocolVersion;
}

const std::string &ECPRIFrame::getRtcId() const {
    return rtcId;
}

const std::string &ECPRIFrame::getSequenceId() const {
    return sequenceId;
}

void ECPRIFrame::setConcatenationIndicator(const std::string &concatenationIndicator) {
    ECPRIFrame::concatenationIndicator = concatenationIndicator;
}

void ECPRIFrame::setMessageType(const std::string &messageType) {
    ECPRIFrame::messageType = messageType;
}

void ECPRIFrame::setPayloadSize(const std::string &payloadSize) {
    ECPRIFrame::payloadSize = payloadSize;
}

void ECPRIFrame::setProtocolVersion(const std::string &protocolVersion) {
    ECPRIFrame::protocolVersion = protocolVersion;
}

void ECPRIFrame::setRtcId(const std::string &rtcId) {
    ECPRIFrame::rtcId = rtcId;
}

void ECPRIFrame::setSequenceId(const std::string &sequenceId) {
    ECPRIFrame::sequenceId = sequenceId;
}

ECPRIFrame::ECPRIFrame(std::string &type) {
    this->setType(type);
}

const int ECPRIFrame::getMessageTypeFieldLength() const {
    return MESSAGE_TYPE_FIELD_LENGTH;
}

const int ECPRIFrame::getConcIndicatorFieldLength() const {
    return CONC_INDICATOR_FIELD_LENGTH;
}

const int ECPRIFrame::getProtocolVerFieldLength() const {
    return PROTOCOL_VER_FIELD_LENGTH;
}

const int ECPRIFrame::getPayloadSizeFieldLength() const {
    return PAYLOAD_SIZE_FIELD_LENGTH;
}

const int ECPRIFrame::getRtcIdFieldLength() const {
    return RTC_ID_FIELD_LENGTH;
}

const int ECPRIFrame::getSeqIdFieldLength() const {
    return SEQ_ID_FIELD_LENGTH;
}

void ECPRIFrame::writeToFile(std::ofstream &file) {
    PacketFileWriter pfw;
    pfw.writeECPRIFrame(file,*this);
}


