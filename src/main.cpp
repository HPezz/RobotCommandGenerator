#include <iostream>
#include "LekaController.hpp"
#include "../include/CLI.hpp"

using namespace std;

int main(int argc, char **argv)
{
    CLI::App app{"Leka controller"};

    LekaController lkctrl;

    string lkpart;
    app.add_option("lkpart", lkpart, "Controller type [led or motor]");

    vector<RPARAM> ear;
    app.add_option("-e,--ear", ear, "LED ear control options \nExpected : _all : 0x11 + [R G B] (decimal or hex)\n           _left : 0x12  + [R G B]\n           _right : 0x13 + [R G B]");

    vector<RPARAM> belt;
    app.add_option("-b,--belt", belt, "LED belt control options \nExpected : _all : 0x14 + [R G B] (decimal or hex)\n           _range : 0x15 + [first_led_id last_led_id](hex) + [R G B]\n           _single : [led_id](hex) + [R G B]");

    vector<RPARAM> motor;
    app.add_option("motor", motor, "Motor control options \nExpected : _all : 0x21 + [direction (0 or 1)] + [speed (0-255)]\n           _duo : 0x22 + [spin1] + [speed1] + [spin2] + [speed2]\n           _left : 0x23 + [spin] + [speed]\n           _right : 24 + [spin] + [speed]");

    CLI11_PARSE(app, argc, argv);

    if (ear != vector<RPARAM>({}))
    {
        lkctrl.setCommandGroup(ear);
    }
    else if (belt != vector<RPARAM>({}))
    {
        lkctrl.setCommandGroup(belt);
    }
    else if (motor != vector<RPARAM>({}))
    {
        lkctrl.setCommandGroup(motor);
    }
    else 
    {
        cerr << "Error generating command frame : wrong inputs." << endl;
    }
    
    lkctrl.checksumBSD();

    cout << lkctrl.generateCommandFrame() << endl;
    
    return 0;
}


