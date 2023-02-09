//
// Created by DELL on 2/2/2023.
//

#ifndef A1_FRAME_H
#define A1_FRAME_H

#include <iostream>
#include <fstream>

enum Frame_Type {
    ECPRI, RAW,
};


class Frame {
private:
    static const int PREAMBLE_FIELD_LENGTH = 16;
    static const int DEST_FIELD_LENGTH = 12;
    static const int SRC_FIELD_LENGTH = 12;
    static const int TYPE_FIELD_LENGTH = 4;
    static const int CRC_FIELD_LENGTH = 8;

    std::string preamble;
    std::string destinationAddress;
    std::string sourceAddress;
    std::string type;
    std::string crc;

public:

    static const int getPreambleFieldLength();

    static const int getDestFieldLength();

    static const int getSrcFieldLength();

    const int getTypeFieldLength();

    static const int getCrcFieldLength();

    const std::string &getPreamble() const;

    const std::string &getDestinationAddress() const;

    const std::string &getSourceAddress() const;

    const std::string &getType() const;

    const std::string &getCrc() const;

    void setPreamble(const std::string &preamble);

    void setDestinationAddress(const std::string &destinationAddress);

    void setSourceAddress(const std::string &sourceAddress);

    void setType(const std::string &type);

    void setCrc(const std::string &crc);

    virtual void writeToFile(std::ofstream &file) = 0;
};


#endif //A1_FRAME_H
