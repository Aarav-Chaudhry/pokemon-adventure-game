# Pokemon Adventure Game

A text-based RPG featuring a 5x5 grid map, turn-based combat, and Pokemon capture mechanics. Built in C++ to demonstrate algorithm design, data structures, and game development fundamentals.

## 🎮 Features

- **Grid-Based Exploration**: Navigate a 5x5 map with 25 unique rooms
- **Turn-Based Combat**: Strategic attack/defend system with random damage variance
- **Pokemon Capture**: Probability-based catching with rarity tiers (Common/Rare/Legendary)
- **Progressive Difficulty**: Stat modifications and item pickups throughout the journey
- **Boss Battle**: Final encounter with legendary Mewtwo

## 🛠️ Technical Highlights

- **Data Structures**: Custom structs for rooms, characters, and Pokemon with relationship management
- **State Management**: Tracks visited rooms, caught/defeated Pokemon, and player progression
- **Algorithm Design**: Grid pathfinding, combat resolution, and RNG-based mechanics
- **Object-Oriented Design**: Encapsulated game entities with proper data organization
- **Game Loop Architecture**: Event-driven main loop handling user input and state transitions

## 📊 Game Statistics

- 7 unique Pokemon with varying stats and abilities
- 25 distinct rooms across 4 room types
- 3 rarity tiers affecting catch rates (70%/50%/30%)
- 769 lines of C++ code

## 🚀 How to Run

**Requirements:**
- C++ compiler with C++11 support (g++, clang++)

**Compilation:**
```bash
g++ -std=c++11 pokemon.cpp -o pokemon_game
```

**Run:**
```bash
./pokemon_game
```

## 🎯 Gameplay

**Room Types:**
- **Explore**: Safe rooms for traversal
- **Encounter**: Wild Pokemon battles with fight/catch/run options
- **Event**: Stat modifications and item pickups
- **Goal**: Final boss battle

**Combat Mechanics:**
- Choose to Attack or Defend each turn
- Defending reduces incoming damage by 50%
- Random damage variance keeps battles dynamic
- Victory grants TMs (Technical Machines) and stat boosts

**Objective:** Navigate the map, build your strength, and defeat Mewtwo to become Pokemon Master!

## 🧠 Skills Demonstrated

- C++ Programming (STL, vectors, structs, references)
- Algorithm Design (pathfinding, state machines)
- Data Structure Implementation
- Random Number Generation
- Game Loop Architecture
- Input Validation and Error Handling

## 📈 Future Enhancements

- Save/load game state functionality
- Expanded map with procedural generation
- Pokemon evolution mechanics
- Inventory system for items and potions
- Enhanced boss battle mechanics
- Color-coded terminal output
