#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
const int COMMON = 1;
const int COMMON_CATCH_CHANCE = 70;
const int RARE_CATCH_CHANCE = 50;
const int LEGENDARY_CATCH_CHANCE = 30;
const int RARE = 2;
const int LEGENDARY = 3;
const int BOSS = 4;
const int SPACING = 3;
const int CHAR_LENGTH = 1;
const int HEALTH_DEAD = 0;

struct Room
{
    int xCoord;
    int yCoord;
    string type;
    string description;
    int atkIncrease; // Attack increase/decrease for event or encounter effects
    string pokemon;  // Pokémon available in encounter rooms
    int rarity;
    bool beenHere;
};
struct Character
{
    int xCoord;
    int yCoord;
    int prevXCoord;
    int prevYCoord;
    int health;
    int atk;
};
struct Pokemon
{
    string name;
    int health;
    int atk;
    int rarity;
    bool wasCaught;
    bool wasDefeated;
    string TM;
};

Character createCharacter(){
    return{
        .xCoord = 0,
        .yCoord = 0,
        .prevXCoord = 0,
        .prevYCoord = 0,
        .health = 100,
        .atk = 10,
    };
}
// Function to create the pokemon
vector<Pokemon> createPokemon()
{
    return {
        {
            .name = "Pikachu",
            .health = 50,
            .atk = 10,
            .rarity = COMMON,
            .wasCaught = false,
            .wasDefeated = false,
            .TM = "Thunderbolt",
        },
        {
            .name = "Charmander",
            .health = 60,
            .atk = 12,
            .rarity = COMMON,
            .wasCaught = false,
            .wasDefeated = false,
            .TM = "Flamethrower",
        },
        {
            .name = "Eevee",
            .health = 40,
            .atk = 8,
            .rarity = RARE,
            .wasCaught = false,
            .wasDefeated = false,
            .TM = "Quick Attack",
        },
        {
            .name = "Snorlax",
            .health = 125,
            .atk = 20,
            .rarity = LEGENDARY,
            .wasCaught = false,
            .wasDefeated = false,
            .TM = "Earthquake",
        },
        {
            .name = "Golem",
            .health = 100,
            .atk = 15,
            .rarity = LEGENDARY,
            .wasCaught = false,
            .wasDefeated = false,
            .TM = "Rock Slide",
        },
        {
            .name = "Jigglypuff",
            .health = 30,
            .atk = 5,
            .rarity = COMMON,
            .wasCaught = false,
            .wasDefeated = false,
            .TM = "Perish Song",
        },
        {
            .name = "MewTwo",
            .health = 150,
            .atk = 20,
            .rarity = BOSS,
            .wasCaught = false,
            .wasDefeated = false,
            .TM = "Shadow Ball",
        }};
}
// Function to create the Pokémon-themed map
vector<Room> createRooms()
{
    return {
        // Row 1 (y = 0)
        {
            .xCoord = 0,
            .yCoord = 0,
            .type = "ROOM_EXPLORE",
            .description = "you wake up in a sunny field with wild Pokémon like Pidgey and Rattata.",
            .atkIncrease = 0,
            .pokemon = "",
            .rarity = 0,
            .beenHere = false,
        },
        {
            .xCoord = 1,
            .yCoord = 0,
            .type = "ROOM_ENCOUNTER",
            .description = "A wild Pikachu appears, ready for a battle!",
            .atkIncrease = 5,
            .pokemon = "Pikachu",
            .rarity = COMMON,
            .beenHere = false,
        },
        {
            .xCoord = 2,
            .yCoord = 0,
            .type = "ROOM_EVENT",
            .description = "You find a hidden TM that boosts your Pokémon's attack!",
            .atkIncrease = 3,
            .pokemon = "",
            .rarity = 0,
            .beenHere = false,
        },
        {
            .xCoord = 3,
            .yCoord = 0,
            .type = "ROOM_EXPLORE",
            .description = "A dense forest with Caterpie and Weedle scurrying about.",
            .atkIncrease = 0,
            .pokemon = "",
            .rarity = 0,
            .beenHere = false,
        },
        {
            .xCoord = 4,
            .yCoord = 0,
            .type = "ROOM_EXPLORE",
            .description = "A sandy path leading towards a mountain.",
            .atkIncrease = 0,
            .pokemon = "",
            .rarity = 0,
            .beenHere = false,
        },

        // Row 2 (y = 1)
        {
            .xCoord = 0,
            .yCoord = 1,
            .type = "ROOM_ENCOUNTER",
            .description = "A wild Charmander blocks the path!",
            .atkIncrease = 10,
            .pokemon = "Charmander",
            .rarity = COMMON,
            .beenHere = false,
        },
        {
            .xCoord = 1,
            .yCoord = 1,
            .type = "ROOM_EVENT",
            .description = "A mysterious fog saps your strength.",
            .atkIncrease = -3,
            .pokemon = "",
            .rarity = 0,
            .beenHere = false,
        },
        {
            .xCoord = 2,
            .yCoord = 1,
            .type = "ROOM_ENCOUNTER",
            .description = "A strong Eevee appears, looking to fight!",
            .atkIncrease = 5,
            .pokemon = "Eevee",
            .rarity = RARE,
            .beenHere = false,
        },
        {
            .xCoord = 3,
            .yCoord = 1,
            .type = "ROOM_EXPLORE",
            .description = "A quiet clearing with some wild Butterfree.",
            .atkIncrease = 0,
            .pokemon = "",
            .rarity = 0,
            .beenHere = false,
        },
        {
            .xCoord = 4,
            .yCoord = 1,
            .type = "ROOM_EVENT",
            .description = "A wild Beedrill ambushes you",
            .atkIncrease = -4,
            .pokemon = "",
            .rarity = 0,
            .beenHere = false,
        },

        // Row 3 (y = 2)
        {
            .xCoord = 0,
            .yCoord = 2,
            .type = "ROOM_EXPLORE",
            .description = "A quiet meadow with Butterfree and Beautifly.",
            .atkIncrease = 0,
            .pokemon = "",
            .rarity = 0,
            .beenHere = false,
        },
        {
            .xCoord = 1,
            .yCoord = 2,
            .type = "ROOM_EVENT",
            .description = "A mysterious old man offers you a Rare Candy.",
            .atkIncrease = 2,
            .pokemon = "",
            .rarity = 0,
            .beenHere = false,
        },
        {
            .xCoord = 2,
            .yCoord = 2,
            .type = "ROOM_EXPLORE",
            .description = "A rocky area where Geodude can be seen resting.",
            .atkIncrease = 0,
            .pokemon = "",
            .rarity = 0,
            .beenHere = false,
        },
        {
            .xCoord = 3,
            .yCoord = 2,
            .type = "ROOM_ENCOUNTER",
            .description = "A wild Snorlax blocks the road! A tough battle awaits.",
            .atkIncrease = 15,
            .pokemon = "Snorlax",
            .rarity = LEGENDARY,
            .beenHere = false,
        },
        {
            .xCoord = 4,
            .yCoord = 2,
            .type = "ROOM_EXPLORE",
            .description = "You see the light revealing the end of the forest",
            .atkIncrease = 0,
            .pokemon = "",
            .rarity = 0,
            .beenHere = false,
        },

        // Row 4 (y = 3)
        {
            .xCoord = 0,
            .yCoord = 3,
            .type = "ROOM_FIGHT",
            .description = "You come across a an evolution stone and take it with you",
            .atkIncrease = 5,
            .pokemon = "",
            .rarity = 0,
            .beenHere = false,
        },
        {
            .xCoord = 1,
            .yCoord = 3,
            .type = "ROOM_EXPLORE",
            .description = "A narrow path with Pidgey flying overhead.",
            .atkIncrease = 0,
            .pokemon = "",
            .rarity = 0,
            .beenHere = false,
        },
        {
            .xCoord = 2,
            .yCoord = 3,
            .type = "ROOM_EVENT",
            .description = "You find a hidden stash of Pokéballs, replenishing your supplies.",
            .atkIncrease = 0,
            .pokemon = "",
            .rarity = 0,
            .beenHere = false,
        },
        {
            .xCoord = 3,
            .yCoord = 3,
            .type = "ROOM_ENCOUNTER",
            .description = "A wild Jigglypuff starts singing a lullaby",
            .atkIncrease = 3,
            .pokemon = "Jigglypuff",
            .rarity = COMMON,
            .beenHere = false,
        },
        {
            .xCoord = 4,
            .yCoord = 3,
            .type = "ROOM_EXPLORE",
            .description = "A serene lake contains mystic water that you take",
            .atkIncrease = 3,
            .pokemon = "",
            .rarity = 0,
            .beenHere = false,
        },

        // Row 5 (y = 4)
        {
            .xCoord = 0,
            .yCoord = 4,
            .type = "ROOM_EVENT",
            .description = "A Caterpie brings a berry for you",
            .atkIncrease = 5,
            .pokemon = "",
            .rarity = 0,
            .beenHere = false,
        },
        {
            .xCoord = 1,
            .yCoord = 4,
            .type = "ROOM_ENCOUNTER",
            .description = "A wild Golem appears, prepared for a tough battle.",
            .atkIncrease = 15,
            .pokemon = "Golem",
            .rarity = LEGENDARY,
            .beenHere = false,
        },
        {
            .xCoord = 2,
            .yCoord = 4,
            .type = "ROOM_EXPLORE",
            .description = "A cool, shaded forest where wild Bulbasaur are spotted.",
            .atkIncrease = 0,
            .pokemon = "",
            .rarity = 0,
            .beenHere = false,
        },
        {
            .xCoord = 3,
            .yCoord = 4,
            .type = "ROOM_EVENT",
            .description = "You find a full heal potion",
            .atkIncrease = 5,
            .pokemon = "",
            .rarity = 0,
            .beenHere = false,
        },
        {
            .xCoord = 4,
            .yCoord = 4,
            .type = "ROOM_GOAL",
            .description = "The Legendary Pokémon Mewtwo stands in the center, radiating immense power.",
            .atkIncrease = 0,
            .pokemon = "MewTwo",
            .rarity = BOSS,
            .beenHere = false,
        },
    };
}
//shows the ehnacements (TMs are CDs that hold pokemon moves)
void displayTM(vector<Pokemon> &pokemon)
{
    int count;
    cout << "=========================================" << endl;
    cout << "TM's collected:";
    for (auto pkmn : pokemon)
    {
        if (pkmn.wasCaught == true || pkmn.wasDefeated == true)
        {
            if (count % SPACING == 0) //move one line down after three TMS are written (formatting)
            {
                cout << endl; 
            }
            count++;
            cout << pkmn.TM << ", ";
        }
    }
    cout << "\n=========================================" << endl;
}
//show how you progressed in the game after its over
void printCaughtandDefeatedPokemon(vector<Pokemon> &pokemon)
{
    cout << "\nThroughout your journey:\n";

    for (auto pkmn : pokemon)
    {
        if (pkmn.wasCaught == true) // if you caught a pokemon
        {
            cout << "You caught " << pkmn.name << endl;
        }
        else if (pkmn.wasDefeated == true) //if you fought a pokemon and won
        {
            cout << "You defeated " << pkmn.name << endl;
        }
    }
}
// checks for a room in each direction
bool isThereARoom(int x, int y, const vector<Room> &rooms)
{
    for (const Room &room : rooms)
    {
        if (room.xCoord == x && room.yCoord == y) //if there is a room in the direction
        {
            return true;
        }
    }
    return false;
}
// outputs the potential movement options and moves player
void movementOptions(Character &player, const vector<Room> &rooms)
{
    string choice;
    //check for a room in each direction
    bool isNorth = isThereARoom(player.xCoord, player.yCoord + 1, rooms);
    bool isSouth = isThereARoom(player.xCoord, player.yCoord - 1, rooms);
    bool isEast = isThereARoom(player.xCoord + 1, player.yCoord, rooms);
    bool isWest = isThereARoom(player.xCoord - 1, player.yCoord, rooms);

    while (true)
    {
        // Output potential moves with proper formatting
        cout << "\n=========================================" << endl;
        cout << "Where would you like to move?" << endl;
        if (isNorth)
            cout << "(N)orth, ";
        if (isSouth)
            cout << "(S)outh, ";
        if (isEast)
            cout << "(E)ast, ";
        if (isWest)
            cout << "(W)est";
        cout << "\nPlease enter your choice: ";
        cout << "\n=========================================" << endl;

        cin >> choice;

        if (choice.length() > CHAR_LENGTH)
        {
            cout << "\nInvalid move! Please choose a valid direction (N/S/E/W).\n";
        }
        else if ((choice == "N" || choice == "n") && isNorth)
        {
            player.prevXCoord = player.xCoord;
            player.prevYCoord = player.yCoord;
            player.yCoord += 1; // Move north
            cout << "--------------------------------------------------------------------------------------------" << endl;
            break;
        }
        else if ((choice == "S" || choice == "s") && isSouth)
        {
            player.prevXCoord = player.xCoord;
            player.prevYCoord = player.yCoord;
            player.yCoord -= 1; // Move south
            cout << "--------------------------------------------------------------------------------------------" << endl;
            break;
        }
        else if ((choice == "E" || choice == "e") && isEast)
        {
            player.prevXCoord = player.xCoord;
            player.prevYCoord = player.yCoord;
            player.xCoord += 1; // Move east
            cout << "--------------------------------------------------------------------------------------------" << endl;
            break;
        }
        else if ((choice == "W" || choice == "w") && isWest)
        {
            player.prevXCoord = player.xCoord;
            player.prevYCoord = player.yCoord;
            player.xCoord -= 1; // Move west
            cout << "--------------------------------------------------------------------------------------------" << endl;
            break;
        }
        else
        {
            cout << "\nInvalid move! Please choose a valid direction (N/S/E/W).\n";
        }
        cout << endl;
    }
}
// Function to simulate catching a Pokémon in encounter rooms
bool tryToCatchPokemon(Pokemon &pokemon, int rarity)
{
    int catchChance = rand() % 100; // Random number between 0 and 99
    int requiredChance = (rarity == COMMON) ? COMMON_CATCH_CHANCE : (rarity == RARE) ? RARE_CATCH_CHANCE: LEGENDARY_CATCH_CHANCE; // Adjust by rarity

    cout << "\n=========================================" << endl;
    cout << "Trying to catch " << pokemon.name << "...\n";
    cout << "=========================================" << endl;

    if (catchChance < requiredChance) // if rand num is less than chance
    {
        cout << "\nSuccess! You caught " << pokemon.name << "!\n";
        cout << pokemon.name << " dropped the TM: " << pokemon.TM << "!" << endl;
        pokemon.wasCaught = true;
        return true;
    }
    else
    {
        cout << "\nFailed to catch " << pokemon.name << ". It ran away!" << endl;
        return false;
    }
}
//simulate battling the pokemon you encounter
void battlePokemon(Character &player, Room &room, Pokemon &pokemon, vector<Pokemon> &pkmn)
{
    // Battle loop
    player.health = 100;
    while (player.health > HEALTH_DEAD && pokemon.health > HEALTH_DEAD)
    {
        // Player's turn
        int playerAtk = player.atk + (rand() % 5); //random atk amount
        // Battle Header
        cout << "\n=========================================" << endl;
        cout << "Your Health: " << player.health << " | " << pokemon.name << " Health: " << pokemon.health << endl;
        cout << "=========================================" << endl;
        string action;

        while (true)
        {
            cout << "Do you want to (A)ttack or (D)efend? " << endl;
            cin >> action;
            if (action == "A" || action == "a")
            {
                cout << "You attack " << pokemon.name << " for " << playerAtk << " damage!" << endl;
                pokemon.health -= playerAtk; // Pokémon loses health
                break;
            }
            else if (action == "D" || action == "d")
            {
                cout << "You defend yourself! You lose less health from the next attack." << endl;
                break;
            }
            else
            {
                cout << "\nInvalid action.\n";
            }
        }
        // Pokémon's turn
        if (pokemon.health > HEALTH_DEAD)
        {
            int damage = pokemon.atk + (rand() % 5); //random atk amount

            if (action == "D" || action == "d")
            {
                cout << pokemon.name << " attacks you for " << (damage / 2) << " damage!" << endl;
                player.health -= (damage / 2); //pokemon atk only does half 
            }
            else
            {
                cout << pokemon.name << " attacks you for " << damage << " damage!" << endl;
                player.health -= damage;
            }
        }

        // If you lose
        if (player.health <= HEALTH_DEAD)
        {
            cout << "\n==========================================\n";
            cout << "You were defeated by " << pokemon.name << "...\n";
            printCaughtandDefeatedPokemon(pkmn);
            exit(EXIT_SUCCESS);
        }
        else if (pokemon.health <= HEALTH_DEAD) //if you win
        {
            cout << "\n==========================================\n";
            cout << "You defeated " << pokemon.name << "!\n";

            pokemon.wasDefeated = true;
            player.atk += room.atkIncrease; // Increase attack after winning the battle
            cout << pokemon.name << " dropped the TM: " << pokemon.TM << "!" << endl;
            cout << "Your attack increased by " << room.atkIncrease << endl;
            cout << "Your atk = " << player.atk << endl;
            displayTM(pkmn);
        }
    }
}
// Function to apply room effects
void applyRoomEffect(Character &character, Room &room, vector<Pokemon> &pokemon, bool &ranAway)
{
    if (room.type == "ROOM_ENCOUNTER" && !room.pokemon.empty())
    {
        char choice;
        cout << "\n=========================================" << endl;
        cout << "What would you like to do?" << endl;
        cout << "(F)ight | (C)atch | (R)un" << endl;
        cout << "=========================================" << endl;
        cin >> choice;

        if (choice == 'F' || choice == 'f')
        {
            for (auto &pkmn : pokemon) //find which pokemon is associated with this room
            {
                if (pkmn.name == room.pokemon)
                {
                    battlePokemon(character, room, pkmn, pokemon); //battle pokemon
                    break;
                }
            }
            room.beenHere = true; // Mark the room as visited
        }
        else if (choice == 'C' || choice == 'c')
        {
            bool caught;
            for (auto &pkmn : pokemon) //find which pokemon is associated with this room
            {
                if (pkmn.name == room.pokemon)
                {
                    caught = tryToCatchPokemon(pkmn, pkmn.rarity); // attempt to catch pokemon
                }
            }
            if (caught)
            {
                character.atk += room.atkIncrease;
                cout << "Your attack increased by " << room.atkIncrease << "!\n";
                cout << "Your atk = " << character.atk << endl;
                displayTM(pokemon); 
            }
            room.beenHere = true; //indicate the player has completed this room event
        }
        else if (choice == 'R' || choice == 'r')
        {
            cout << "You ran away from the wild " << room.pokemon << "!\n"
                 << endl;
            // Restore player's position to the previous room
            character.xCoord = character.prevXCoord;
            character.yCoord = character.prevYCoord;
            ranAway = true; // Indicate that the player ran away
        }
        else
        {
            cout << "Invalid choice. You return to your previous room.\n";
            // Restore player's position to the previous room
            character.xCoord = character.prevXCoord;
            character.yCoord = character.prevYCoord;
            ranAway = true; // Indicate that the player went back
        }
    }
    else if (room.type == "ROOM_EVENT")
    {
        character.atk += room.atkIncrease; //change atk # depending on scenario
        if (room.atkIncrease > 0)
        {
            cout << "Your attack increased by " << room.atkIncrease << "!\n";
            cout << "Your atk = " << character.atk << endl;
            displayTM(pokemon);
        }
        else if (room.atkIncrease < 0)
        {
            cout << "Your attack decreased by " << -room.atkIncrease << "!\n";
            cout << "Your atk = " << character.atk << endl;
            displayTM(pokemon);
        }
        room.beenHere = true; // Mark the room as visited
    }
    else if (room.type == "ROOM_EXPLORE")
    {
        cout << "You explore the area but find nothing significant.\n";
        cout << "Your atk = " << character.atk << endl;
        displayTM(pokemon);
        room.beenHere = true; // Mark the room as visited
    }
    else if (room.type == "ROOM_GOAL")
    {
        for (auto &pkmn : pokemon) //battle mewtwo (final challenge)
        {
            if (pkmn.name == room.pokemon)
            {
                battlePokemon(character, room, pkmn, pokemon);
                cout << "Congratulations! You are now the Pokémon Master!";
                exit(EXIT_SUCCESS);
            }
        }
    }
}
//display beginning information for game
void displayStart()
{
    cout << "--------------------------------------------" << endl;
    cout << "   Welcome to the Pokémon Adventure Game!" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << "   Objective: Find and defeat Mewtwo, hidden somewhere on the 5x5 map." << endl;
    cout << "   Prepare yourself for an epic adventure. Good luck, Trainer!" << endl;
    cout << "-------------------------------------------------------------------------" << endl;
    cout << endl;
}

int main()
{
    srand(time(0)); //seed random generator
    vector<Room> rooms = createRooms(); //create map
    Character player = createCharacter(); //create player for the game
    vector<Pokemon> pokemon = createPokemon(); //create pokemon/enhancements

    displayStart(); //display game title and info
    // loop until dead or win game
    while (true)
    {
        // Find the current room based on player's coordinates
        Room *currentRoom;
        for (Room &room : rooms)
        {
            if (room.xCoord == player.xCoord && room.yCoord == player.yCoord)
            {
                currentRoom = &room;
                break;
            }
        }

        // Display the current room description
        if (!currentRoom->beenHere) //new room
        {
            cout << "You are at (" << player.xCoord << ", " << player.yCoord << "): " << currentRoom->description << endl;
           
            // Apply room effects
            bool ranAway = false;
            applyRoomEffect(player, *currentRoom, pokemon, ranAway);
            if (ranAway)
            {
                // display previous room description
                cout << "You returned to (" << player.xCoord << ", " << player.yCoord << "): ";
                cout << "you have already been here" << endl;
                cout << "atk = " << player.atk << endl;
                displayTM(pokemon);
            }
        }
        else if (currentRoom->beenHere) //entering a room youve already been to 
        {
            cout << "You are at (" << player.xCoord << ", " << player.yCoord << "): " << "You have already been here" << endl;
            cout << "atk = " << player.atk << endl;
            displayTM(pokemon);
        }

        // Allow the player to choose where to move next
        movementOptions(player, rooms);
    }

    return 0;
}