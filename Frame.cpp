//
// Created by DELL on 2/2/2023.
//

#include "Frame.h"

const std::string &Frame::getPreamble() const {
    return preamble;
}

const std::string &Frame::getDestinationAddress() const {
    return destinationAddress;
}

const std::string &Frame::getSourceAddress() const {
    return sourceAddress;
}

const std::string &Frame::getType() const {
    return type;
}

const std::string &Frame::getCrc() const {
    return crc;
}

void Frame::setPreamble(const std::string &preamble) {
    Frame::preamble = preamble;
}

void Frame::setDestinationAddress(const std::string &destinationAddress) {
    Frame::destinationAddress = destinationAddress;
}

void Frame::setSourceAddress(const std::string &sourceAddress) {
    Frame::sourceAddress = sourceAddress;
}

void Frame::setType(const std::string &type) {
    Frame::type = type;
}

void Frame::setCrc(const std::string &crc) {
    Frame::crc = crc;
}

const int Frame::getPreambleFieldLength()  {
    return PREAMBLE_FIELD_LENGTH;
}

const int Frame::getDestFieldLength()  {
    return DEST_FIELD_LENGTH;
}

const int Frame::getSrcFieldLength()  {
    return SRC_FIELD_LENGTH;
}

const int Frame::getTypeFieldLength()  {
    return TYPE_FIELD_LENGTH;
}

const int Frame::getCrcFieldLength()  {
    return CRC_FIELD_LENGTH;
}

