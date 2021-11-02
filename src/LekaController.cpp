#include "LekaController.hpp"
#include <cmath>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

LekaController::LekaController() 
{
    vector<RPARAM> command_group;
    setCommandGroup(command_group);

    RPARAM checksum;
    setChecksum(checksum);
}

void LekaController::checksumBSD()
{
    RPARAM cksm = 0;
    for (RPARAM c : getCommandGroup())
    {
        cksm = (c + cksm) % 256;
    }
    setChecksum(cksm);
}

/* From the input command group and the calculate checksum,
 we generate the command frame by first adding the header 
 and the command group length, then converting and adding 
 command group and checksum 
*/
RCOMMANDFRAME LekaController::generateCommandFrame()
{
    RCOMMANDFRAME cmdframe = HEADER;
    stringstream strstream;
    vector<RPARAM> cmdgroup = getCommandGroup();
    strstream << " " << hex << +cmdgroup.size();
    for (RPARAM c : cmdgroup)
    {
        strstream << " " << hex << +c;
    }
    strstream << " " << hex << +getChecksum() << endl;
    cmdframe += strstream.str();
    return cmdframe;
}

void LekaController::setCommandGroup(vector<RPARAM> command_group)
{
    this->command_group = command_group;
}

void LekaController::setChecksum(RPARAM checksum)
{
    this->checksum = checksum;
}

vector<RPARAM> LekaController::getCommandGroup()
{
    return this->command_group;
}

RPARAM LekaController::getChecksum()
{
    return this->checksum;
}

LekaController::~LekaController()
{
    // Delete command_group allocation
}
