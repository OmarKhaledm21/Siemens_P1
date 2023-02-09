#include "PacketFileReader.h"
bool PacketFileReader::readPacketsFromFile(string &filename)
{
    try
    {
        fstream file;
        file.open(filename, ios::in);

        string line;
        while (getline(file, line))
        {
            this->packetStrings.push_back(line);
        }
        file.close();
        return true;
    }
    catch (...)
    {
        return false;
    }
}

vector<string> &PacketFileReader::getPacketStrings()
{
    return this->packetStrings;
}