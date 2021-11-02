#ifndef LEKACONTROLLER_H
#define LEKACONTROLLER_H

#include <iostream>
#include <vector>

#define HEADER "2A 2B 2C 2D"
#define RPARAM uint8_t
#define RCOMMANDFRAME string

using namespace std;

class LekaController
{
public:
    // Constructor
    LekaController();

    // Main methods 

    void checksumBSD(); // Compute checksum from imput command
    RCOMMANDFRAME generateCommandFrame(); // Return the command frame string from the command and checksum

    // Getter and setter
    void setCommandGroup(vector<RPARAM> command_group);
    void setChecksum(RPARAM checksum);
    vector<RPARAM> getCommandGroup();
    RPARAM getChecksum();

    // Destructor
    ~LekaController();

private:
    // Attributes
    vector<RPARAM> command_group; // 
    uint8_t checksum; 
};

#endif