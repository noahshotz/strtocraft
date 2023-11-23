# strtocraft

## Overview
strtocraft is a specialized tool designed for generating possible combinations for CS:GO/CS2 sticker crafts using a string input. It's an innovative solution for gamers and enthusiasts looking to explore crafting options in Counter-Strike: Global Offensive and Counter-Strike 2.

## Features
String Input Conversion: Convert any given string input into potential sticker craft combinations. CS:GO and CS2 Compatibility: Tailored specifically for use with Counter-Strike: Global Offensive and Counter-Strike 2. If multiple combinations are possible, the output will be sorted, starting with the shortest. Since the currently existing weapons in the game with 5 sticker slots (G3SG1 and R8 Revolver) are not really suitable for sticker crafts anyway, they are ignored in this context. If you want to change the 4 sticker limit you can do so in `find_combinations.cpp` by modifying the `max_elements` value.

## Installation
- Clone the project: `git clone https://github.com/noahshotz/strtocraft.git`
- Navigate into the project; `cd stringtocraft`
- Create build folder: `mkdir build`
- Navigate into the build folder: `cd build`
- Configure the project `cmake ..`

## Usage
- Make sure you're in the build folder: `strtocraft/build`
- Build into executable: `make`
- Run the program: `./strtocraft`
- Enter your input you want to convert :)

## Contributing
Have an idea? Send me a pull request or contact me at info@digitalbando.com

## License
Licensed under CC BY-NC 4.0 DEED. For commercial use contact info@digitalbando.com
