# Seven Seas Console RPG

![BuildCheck](https://img.shields.io/badge/build-passing-green)
![GitHubLicense](https://img.shields.io/github/license/debasish-dutta/seven-seas-console-RPG?style=plastic&color=blueviolet)

This is a simple console game made with C++ with the sole purpose of practicing with classes and OOP.
This game now has the basic functionalities but is multi-player and will continue down the line with more features. 
This app doesn't contains any libraries and everything was done in C++.
___

## To Build the project

### Requirements

Compiler: ```gcc``` or ```clang```

Version Control: ```Git```

Build system: ```GNU make```

```bash
#Clone the project
git clone https://github.com/debasish-dutta/seven-seas-console-RPG.git
#Build 
cd seven-seas-console-RPG
make
# Run the game
./bin/ss_runner
```
For the compiler, just change the compiler in the `makefile`.
___

## Game Screengrabs

![Initialization](game_images/game init.png)

![Game start](game_images/Game start.png)

![Player char sheet](game_images/Player character sheet.png)
___

## TODO for future expansion

0. Implement the use item event
1. Add Boss:
    * Make monsters into super and sub classes with addition of different monsters and a Boss class.
2. Implement Shop
3. Add Rooms:
    * Add 7 rooms/grids each with increasing size. 
4. Add rescue event
5. Add a tear and repair system for weapons.
6. Add random items
