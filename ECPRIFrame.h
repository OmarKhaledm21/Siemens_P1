//
// Created by DELL on 2/2/2023.
//

#ifndef A1_ECPRIFRAME_H
#define A1_ECPRIFRAME_H

#include "Frame.h"

class ECPRIFrame : public Frame {
    const int MESSAGE_TYPE_FIELD_LENGTH = 2;
    const int CONC_INDICATOR_FIELD_LENGTH = 1;
    const int PROTOCOL_VER_FIELD_LENGTH = 1;
    const int PAYLOAD_SIZE_FIELD_LENGTH = 4;
    const int RTC_ID_FIELD_LENGTH = 4;
    const int SEQ_ID_FIELD_LENGTH = 4;

    std::string concatenationIndicator;
    std::string messageType;
    std::string payloadSize;
    std::string protocolVersion;
    std::string rtcId;
    std::string sequenceId;

public:


    const int getMessageTypeFieldLength() const;

    const int getConcIndicatorFieldLength() const;

    const int getProtocolVerFieldLength() const;

    const int getPayloadSizeFieldLength() const;

    const int getRtcIdFieldLength() const;

    const int getSeqIdFieldLength() const;

    ECPRIFrame(std::string &type);


    const std::string &getConcatenationIndicator() const;

    const std::string &getMessageType() const;

    const std::string &getPayloadSize() const;

    const std::string &getProtocolVersion() const;

    const std::string &getRtcId() const;

    const std::string &getSequenceId() const;

    void setConcatenationIndicator(const std::string &concatenationIndicator);

    void setMessageType(const std::string &messageType);

    void setPayloadSize(const std::string &payloadSize);

    void setProtocolVersion(const std::string &protocolVersion);

    void setRtcId(const std::string &rtcId);

    void setSequenceId(const std::string &sequenceId);
    void writeToFile(std::ofstream &file) override;

};


#endif //A1_ECPRIFRAME_H
