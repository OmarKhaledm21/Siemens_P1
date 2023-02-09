#include <iostream>
#include <fstream>
#include "PacketAnalyzer.h"
#include "PacketFileReader.h"
using namespace std;

void StartPacketAnalyzer(string &input_file_name, string &output_file_name)
{
    bool data_extracted = false;
    PacketFileReader packetFileReader;
    PacketAnalyzer packetAnalyzer;

    if (!packetFileReader.readPacketsFromFile(input_file_name))
    {
        cout << "No such file or directory!" << endl;
    }
    else
    {
        packetAnalyzer.analyzePackets(packetFileReader.getPacketStrings());
        data_extracted = true;
    }
    if (data_extracted)
    {
        packetAnalyzer.writePacketData(output_file_name);
    }
}

int main()
{
    string input_file_name = "input_packets.txt";
    string output_file_name = "output_packets.txt";
    StartPacketAnalyzer(input_file_name, output_file_name);

    return 0;
}
