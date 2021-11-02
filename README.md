# RobotCommandGenerator
Simple tool to generate robot commands 

# Technologies 
* C++ 17
* Google Test
* CLI11

# Generation

Build the project and then launch ```./leka_controller``` in your bin folder, followed by an instruction to generate the formatted command frame.

The instructions must respect the LK Alpha Com Specs https://github.com/leka/LKAlphaComSpecs, detailed in the helper ```./leka_controller -h (--helper)```.

# Exemple 

To switch on the left ear in red, enter ```./leka_controller led --ear 0x12 0xFF 0x00 0x00 (or 255 0 0)```. 

It will return ```2A 2B 2C 2D 4 12 FF 0 0 11```

