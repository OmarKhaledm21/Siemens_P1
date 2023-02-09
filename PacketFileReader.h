#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class PacketFileReader
{
    vector<string> packetStrings;

public:
    bool readPacketsFromFile(string &filename);
    vector<string> &getPacketStrings();
};