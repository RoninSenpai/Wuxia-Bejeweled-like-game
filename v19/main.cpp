// Ronin Abonita Final Project Code, Heavily assisted by CHATGpt but with no online plagiarism.
// Unfinished:
// STORY, PREDETERMINED PATHS, POWERS.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>
#include <fstream>

using namespace std; 

const int numRows = 8;
const int numCols = 8;
char stage;
int moves = 0;
int matches = 0;
int currentRound = 1;
int matchesNeeded = 10;
int maxMoves = 10;
bool isHeavenPathChosen = false;
bool isDemonicPathChosen = false;
bool isWisdomPathChosen = false;
bool heavenPowerAvailable = true;
bool demonicPowerAvailable = true;
bool wisdomPowerAvailable = true;
bool nameCorrect = false;

struct Candy {
    char type;
};

Candy gameBoard[numRows][numCols];

int matchCounter = 0;
bool hasWarning;

void DisplayWarning(const string& message) {
    hasWarning = true;
    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout << "Warning: " << message << endl;
    cout << "Press Enter to continue...";
    cin.get();  
    hasWarning = false;
}

void InitializeGameBoard() {
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numCols; ++j) {
            gameBoard[i][j].type = 'A' + rand() % 5;
        }
    }
}
void ClearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void GetPlayerName(string &playerName) {
	while (!nameCorrect) {
		ClearScreen();	
		cout << "\n\n\n\n\t\t\t\t\t\t               ." << endl;
	    cout << "\t\t\t\t\t\t              .:." << endl;
	    cout << "\t\t\t\t\t\t             .:::." << endl;
	    cout << "\t\t\t\t\t\t            .:::::." << endl;
	    cout << "\t\t\t\t\t\t        ***.:::::::.***" << endl;
	    cout << "\t\t\t\t\t\t   *******.:::::::::.*******" << endl;
	    cout << "\t\t\t\t\t\t ********.:::::::::::.********" << endl;
	    cout << "\t\t\t\t\t\t********.:::::::::::::.********" << endl;
	    cout << "\t\t\t\t\t\t*******.::::::'***`::::.*******" << endl;
	    cout << "\t\t\t\t\t\t******.::::'*********`::.******" << endl;
	    cout << "\t\t\t\t\t\t ****.:::'*************`:.****" << endl;
	    cout << "\t\t\t\t\t\t   *.::'*****************`.*" << endl;
	    cout << "\t\t\t\t\t\t   .:'  ***************    ." << endl;
	    cout << "\t\t\t\t\t\t       Enter your name:\n\t\t\t\t\t\t\t    ";
	    cin >> playerName;
        cout << "\n\t\t\t\t      You entered the name: " << playerName << ". Is this correct? (yes/no): ";
        string response;
        cin >> response;
        if (response == "yes" && "Yes") {
            nameCorrect = true;
        } else if (response == "no") {
            cout << "\n\t\t\t\tPlease enter your character's name again.\n";
        } else {
            cout << "\n\t\t\t\t\tInvalid response. Please enter 'yes' or 'no'.\n";
        }
    }
}

void DisplayStoryIntro(string& playersName) {
    cout << "\n\n\n\n"
         << "\t\t\t\t¦                                                          \n"
         << "\t\t\t\t¦      In a distant realm of martial arts and cosmic       \n"
         << "\t\t\t\t¦      energy, a young martial artist, \033[97m" << playersName << "\033[0m,       \n"
         << "\t\t\t\t¦      embarks on a journey that will shape their destiny.  \n"
         << "\t\t\t\t¦      \033[97m" << playersName << "\033[0m is not seeking power but       \n"
         << "\t\t\t\t¦      stumbles upon it by accident.                        \n"
         << "\t\t\t\t¦                                                          \n";
    cin.get();
    
    cout << "\t\t\t\t¦      The story begins with \033[97m" << playersName << "\033[0m as a        \n"
         << "\t\t\t\t¦      novice martial artist, training in seclusion on a   \n"
         << "\t\t\t\t¦      remote mountain.                                     \n"
         << "\t\t\t\t¦      One fateful day, \033[97m" << playersName << "\033[0m comes across a \n"
         << "\t\t\t\t¦      mysterious celestial artifact hidden within a cave.  \n"
         << "\t\t\t\t¦      As they touch it, they are imbued with an energy    \n"
         << "\t\t\t\t¦      they cannot comprehend.                             \n";
    cin.get();

    cout << "\t\t\t\t¦      This celestial artifact is an inheritance of        \n"
         << "\t\t\t\t¦      immense power.                                       \n"
         << "\t\t\t\t¦                                                          \n";
    cin.get();

    cout << "\t\t\t\t¦      As \033[97m" << playersName << "\033[0m continues their training,     \n"
         << "\t\t\t\t¦      they discover that this newfound power leads to    \n"
         << "\t\t\t\t¦      three distinct paths: the Heaven Path, the Demonic  \n"
         << "\t\t\t\t¦      Path, and the Wisdom Path. Each path offers unique  \n"
         << "\t\t\t\t¦      abilities and insights into the cosmos.             \n";
    cin.get();

    cout << "\t\t\t\t¦      Now, \033[97m" << playersName << "\033[0m faces a pivotal choice. The    \n"
         << "\t\t\t\t¦      path they select will become their destiny,         \n"
         << "\t\t\t\t¦      shaping the course of their journey and the cosmic  \n"
         << "\t\t\t\t¦      powers they will wield. Let's explore each of      \n"
         << "\t\t\t\t¦      these paths further:                                \n";
    cin.get();

    cout << "\t\t\t\t\033[33m¦      The Heaven Path (H): Choosing this path, \033[97m" << playersName << "\033[33m  \n"
         << "\t\t\t\t\033[33m¦      unlocks celestial powers of benevolence and         \n"
         << "\t\t\t\t¦      enlightenment. It allows them to harness cosmic     \n"
         << "\t\t\t\t¦      forces for virtuous purposes, offering protection   \n"
         << "\t\t\t\t¦      and healing to those in need.\033[0m                       \n";
    cin.get();

    cout << "\t\t\t\t\033[31m¦      The Demonic Path (D): By venturing down the Demonic  \n"
         << "\t\t\t\t¦      Path, \033[0m" << playersName << " \033[31mgains control over dark,  \n"
         << "\t\t\t\t¦      malevolent energies hidden deep within the cosmos.  \n"
         << "\t\t\t\t¦      However, this power comes at a cost, risking the    \n"
         << "\t\t\t\t¦      corruption of their very soul.\033[0m                      \n";
    cin.get();

    cout << "\t\t\t\t\033[36m¦      The Wisdom Path (W): The Wisdom Path is one of       \n"
         << "\t\t\t\t¦      knowledge and insight. It enables \033[0m" << playersName << " \033[36mto  \n"
         << "\t\t\t\t¦      grasp the profound mysteries of the cosmos and      \n"
         << "\t\t\t\t¦      their own inner self. This path provides strategic  \n"
         << "\t\t\t\t¦      advantages and the ability to make wise decisions.\033[0m  \n";
    cin.get();

    cout << "\t\t\t\t¦      As \033[97m" << playersName << "\033[0m sets forth on their chosen     \n"
         << "\t\t\t\t¦      path, their journey will be filled with unique      \n"
         << "\t\t\t\t¦      challenges and pivotal choices. With each step,     \n"
         << "\t\t\t\t¦      they must learn to master their inherited abilities, \n"
         << "\t\t\t\t¦      navigating the intricate tapestry of the cosmos.   \n";
    cin.get();

    cout << "\t\t\t\t¦      The ultimate destination is the mastery of their    \n"
         << "\t\t\t\t¦      chosen path, a place where \033[97m" << playersName << "\033[0m can    \n"
         << "\t\t\t\t¦      wield the cosmic powers of entire planets, control  \n"
         << "\t\t\t\t¦      the vastness of galaxies, and harness the brilliance\n"
         << "\t\t\t\t¦      of entire star fields.                               \n";
    cin.get();

    cout << "\t\t\t\t¦      Throughout this odyssey, \033[97m" << playersName << "\033[0m may cross   \n"
         << "\t\t\t\t¦      paths with fellow martial artists and wise mentors  \n"
         << "\t\t\t\t¦      who offer guidance and share their own experiences.  \n"
         << "\t\t\t\t¦      It is in these encounters that \033[97m" << playersName << "\033[0m will   \n"
         << "\t\t\t\t¦      find allies and wisdom that help shape their journey.\n";
    cin.get();

    cout << "\t\t\t\t¦      \033[97m" << playersName << "\033[0m's name will become a legend in the  \n"
         << "\t\t\t\t¦      cosmos, a reflection of the path they chose and the  \n"
         << "\t\t\t\t¦      decisions they made. The power they unlock will be  \n"
         << "\t\t\t\t¦      a testament to their mastery of cosmic forces, but  \n"
         << "\t\t\t\t¦      it comes with the responsibility of wielding it     \n"
         << "\t\t\t\t¦      wisely.                                             \n";
    cin.get();

    cout << "\t\t\t\t¦      As you play this game, the narrative will evolve     \n"
         << "\t\t\t\t¦      based on your choices and the path you've chosen.   \n"
         << "\t\t\t\t¦      You, as \033[97m" << playersName << "\033[0m, will embark on an epic     \n"
         << "\t\t\t\t¦      adventure, and the consequences of your decisions  \n"
         << "\t\t\t\t¦      will determine the outcome of this celestial        \n"
         << "\t\t\t\t¦      challenge.                                          \n";
    cin.get();

    cout << "\t\t\t\t\033[97m¦      Are you ready, \033[97m" << playersName << ", to embrace your     \n"
         << "\t\t\t\t¦      destiny, choose your path, and conquer the cosmos?  \033[0m\n";
    cin.get();

    cout << "\t\t\t\t\n";
}


void DisplayGameBoard() {
    system("cls");

    
    std::cout << "(c)   . _       \t  ` : | | | |:  ||  :     `  :  |  |+|: | : : :|   .        `              .\n";
    std::cout << "   _, ;  `._   ____  __       ` : | :|  ||  |:  :    `  |  | :| : | : |:   |  .                    : +\n";
    std::cout << " -\\ \\-+--/| | | / / / /\\--- --   .' ':  ||  |:    ___  __  ` || | : | |: : |   .  `           .   :.+\n";
    std::cout << "   \\_\\/\\/ \\_\\_//_/_/_/--\\             `'         | |_)( (`    ` : | | :| |*|  :   :               :| +\n";
    std::cout << "      ! A Wuxia Story based Tile Puzzle game! By |_| \\_)_)        ` ' :| | :| . : :         *   :.|| +\n";
    std::cout << "\t\t\t         '    .`                   : .:|       ` | || | : |: |          | ||             \n";

    
    cout << "   ";
    for (int j = 0; j < numCols; ++j) {
        cout << "  " << j;
    }
    cout << "   '          .         + `  |  :  .: .         '| | : :| :    .   |:| ||\n   ";
    for (int j = 0; j < numCols; ++j) {
        cout << "===";
    }
    cout << "=\t .                 .    ` *|  || :       `    | | :| | :      |:| |\n";

    for (int i = 0; i < numRows; ++i) {

        cout << " " << i << " ";
        for (int j = 0; j < numCols; ++j) {
            cout << "||" << gameBoard[i][j].type;
        }
        cout << "||";

        
        if (i == 0) {
            cout << ".            .          .        || |.: *          | || : :   @ :|||\n";
        } else if (i == 1) {
            cout << "    .            .   . *    .   .  ` |||.  +        + '| |||  .  ||`\n";
        } else if (i == 2) {
            cout << " .           > @              .     +:`|!             . ||||  :.||`\n";
        } else if (i == 3) {
            cout << " +      \"You Are Here\".              ..!|*          . | :`||+ |||`\n";
        } else if (i == 4) {
            cout << "     .                     +      : |||`        .| :| | | |.| ||` .-.,=\"``\"=.   .\n";
        } else if (i == 5) {
            cout << "   *     +   '               +  :|| |`     :.+. || || | |:`|| `'   =/_       \\ \n";
        } else if (i == 6) {
            cout << "\t\t\t     .      .||` .    ..|| | |: '` `| | |`  +   |  '=._    |\n";
        } else if (i == 7) {
            cout << "\t\t +         .      .    | .      `|||.:      .||    .     \\     `=./`,  .\n";
        }

        else {
            
            cout << "\n";
        }
    }
    
    cout << "   ";
    for (int j = 0; j < numCols; ++j) {
        cout << "===";
    }
    cout << "=\t     '                           `|.   .  `:|||   + ||'   @  `    '=.__.=' `='\n";
    
cout << "| Current Path: ";
if (isHeavenPathChosen) {
    cout << "\033[33mHeaven Path\033[0m\t   +      *                         `'       `'|.    `:\n";
} else if (isDemonicPathChosen) {
    cout << "\033[31mDemonic Path\033[0m\t   +      *                         `'       `'|.    `:\n";
} else if (isWisdomPathChosen) {
    cout << "\033[36mWisdom Path\033[0m\t   +      *                         `'       `'|.    `:\n";
} else {
    cout << "No Path Chosen ";
}

cout << "\033[0m| Power: ";
if (isHeavenPathChosen) {
    if (heavenPowerAvailable) {
        cout << "\033[33m(-777)\033[0m \t\t __\t\t\t\t                  `.    `.  . \n";
    }
}
if (isDemonicPathChosen) {
    if (demonicPowerAvailable) {
        cout << "\033[31m(-666)\033[0m \t\t __\t\t\t\t                  `.    `.  . \n";
    }
}
if (isWisdomPathChosen) {
    if (wisdomPowerAvailable) {
        cout << "\033[36m(-9)\033[0m \t\t         __\t\t\t\t           `.    `.  . \n";
    }
}

// Reset color
cout << "\033[0m";



    //cout << "\t\t\t\t   +      *                         `'       `'|.    `:\n";
    //cout << "\t\t\t\t __\t\t\t\t                 `.    `.  . \n";
    cout << "\t\t\t\t'  `---\"\"\"----....____,..^---`^``----.,.___          `.    `.  .    ____,.,-\n";
    cout << "\t\t\t\t    ___,--'\"\"`---\"'   ^  ^ ^        ^       \"\"\"\'---,..___ __,..---\"\"\'\n";
}

bool IsMatch(int r, int c) {
    char candy = gameBoard[r][c].type;

    int count = 1;

    for (int i = c + 1; i < numCols; ++i) {
        if (gameBoard[r][i].type == candy) {
            count++;
        } else {
            break;
        }
    }
    for (int i = c - 1; i >= 0; --i) {
        if (gameBoard[r][i].type == candy) {
            count++;
        } else {
            break;
        }
    }
    if (count >= 3) {
        for (int i = c + 1; i < numCols; ++i) {
            if (gameBoard[r][i].type == candy) {
                gameBoard[r][i].type = ' ';
                matchCounter++;
            } else {
                break;
            }
        }
        for (int i = c - 1; i >= 0; --i) {
            if (gameBoard[r][i].type == candy) {
                gameBoard[r][i].type = ' ';
                matchCounter++;
            } else {
                break;
            }
        }
    }
    count = 1;

    for (int i = r + 1; i < numRows; ++i) {
        if (gameBoard[i][c].type == candy) {
            count++;
        } else {
            break;
        }
    }
    for (int i = r - 1; i >= 0; --i) {
        if (gameBoard[i][c].type == candy) {
            count++;
        } else {
            break;
        }
    }
    if (count >= 3) {
        for (int i = r + 1; i < numRows; ++i) {
            if (gameBoard[i][c].type == candy) {
                gameBoard[i][c].type = ' ';
                matchCounter++;
            } else {
                break;
            }
        }
        for (int i = r - 1; i >= 0; --i) {
            if (gameBoard[i][c].type == candy) {
                gameBoard[i][c].type = ' ';
                matchCounter++;
            } else {
                break;
            }
        }
    }

    return count >= 3;
}

void FillEmptyTiles() {
    for (int c = 0; c < numCols; ++c) {
        for (int r = numRows - 1; r >= 0; --r) {
            if (gameBoard[r][c].type == ' ') {
                int above = r - 1;
                while (above >= 0) {
                    if (gameBoard[above][c].type != ' ') {
                        gameBoard[r][c].type = gameBoard[above][c].type;
                        gameBoard[above][c].type = ' ';
                        above--;
                        r--;
                    } else {
                        above--;
                    }
                }
                if (above < 0) {
                    gameBoard[r][c].type = 'A' + rand() % 5;
                }
            }
        }
    }
}

void UpdateGameBoard() {
    for (int c = 0; c < numCols; ++c) {
        int emptySpaces = 0;
        for (int r = numRows - 1; r >= 0; --r) {
            if (gameBoard[r][c].type == ' ') {
                emptySpaces++;
            } else if (emptySpaces > 0) {
                gameBoard[r + emptySpaces][c] = gameBoard[r][c];
                gameBoard[r][c].type = ' ';
            }
        }
    }
}

void ResetGameBoard() {
    matchCounter = 0;
    InitializeGameBoard();
    FillEmptyTiles();
}

void RemoveMatches(int r, int c) {
    char candy = gameBoard[r][c].type;
    int startCol = c;
    while (startCol > 0 && gameBoard[r][startCol - 1].type == candy) {
        startCol--;
    }
    int endCol = c;
    while (endCol < numCols - 1 && gameBoard[r][endCol + 1].type == candy) {
        endCol++;
    }
    if (endCol - startCol >= 2) {
        for (int i = startCol; i <= endCol; ++i) {
            gameBoard[r][i].type = ' ';
            matchCounter++;
        }
    }
    int startRow = r;
    while (startRow > 0 && gameBoard[startRow - 1][c].type == candy) {
        startRow--;
    }
    int endRow = r;
    while (endRow < numRows - 1 && gameBoard[endRow + 1][c].type == candy) {
        endRow++;
    }
    if (endRow - startRow >= 2) {
        for (int i = startRow; i <= endRow; ++i) {
            gameBoard[i][c].type = ' ';
            matchCounter++;
        }
    }
}


bool IsValidSwap(int r1, int c1, int r2, int c2) {
    int dr = abs(r1 - r2);
    int dc = abs(c1 - c2);
    return (dr == 1 && dc == 0) || (dr == 0 && dc == 1);
}

void DisplayMainMenu() {
    ClearScreen();
    std::cout << "\n\n\n\t\t\t\t}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}" << std::endl;
    std::cout << "\t\t\t\t{{ (c)           +         . _           +        +   @       {{" << std::endl;
    std::cout << "\t\t\t\t}}   |               _, ;  `._   ____  __.::  +               }}" << std::endl;
    std::cout << "\t\t\t\t{{  -O-    o       -\\ \\-+--/| | | / / / /\\--- --       +      {{" << std::endl; 
    std::cout << "\t\t\t\t}}   |               \\_\\/\\/ \\_\\_//_/_/_/--\\      |            }}" << std::endl;
    std::cout << "\t\t\t\t{{           +       ===== Main Menu =====.::::.      -O-     {{" << std::endl;
    std::cout << "\t\t\t\t}}      *                .::. `:::::::' .:::::::.      |      }}" << std::endl;
    std::cout << "\t\t\t\t{{ .                  1. Start New Game.::::::::::            {{" << std::endl;
    std::cout << "\t\t\t\t}}         ' -     .::2. About::.  `:' .::::::::::'     .    +}}" << std::endl;
    std::cout << "\t\t\t\t{{ -- )--       .:::::3. Load Game.   :::::::::::             {{" << std::endl;
    std::cout << "\t\t\t\t}}       *   .::::::::4. Exit::::::' . `::::::::'      o      }}" << std::endl;
    std::cout << "\t\t\t\t{{          :::::::::::::::::::::' .::.  `::::::              {{" << std::endl;
    std::cout << "\t\t\t\t}}      .    `::::::::::::::::::' .:::::.  `:::'          @   }}" << std::endl;
    std::cout << "\t\t\t\t{{   o  '-     `:::::::::::::::' .::::::::.  `'    +          {{" << std::endl;
    std::cout << "\t\t\t\t}}      :  |      `::::::::::::' .::::::::::.             +   }}" << std::endl;
    std::cout << "\t\t\t\t{{      !       .    `::::::::'  .:::::::::::::.      @      o{{" << std::endl;
    std::cout << "\t\t\t\t}}      |                           *          o           .  }}" << std::endl;
    std::cout << "\t\t\t\t{{{{{{{{|_{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{" << std::endl;
    cout << "\t\t\t\t     ,  | `.                *.       ";

}

void DisplayInGameMenu() {
    ClearScreen();
        std::cout << "\n\n\n\t\t\t\t}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}" << std::endl;
    std::cout << "\t\t\t\t{{ (c)           +         . _           +        +   @       {{" << std::endl;
    std::cout << "\t\t\t\t}}   |               _, ;  `._   ____  __.::  +               }}" << std::endl;
    std::cout << "\t\t\t\t{{  -O-    o       -\\ \\-+--/| | | / / / /\\--- --       +      {{" << std::endl; 
    std::cout << "\t\t\t\t}}   |               \\_\\/\\/ \\_\\_//_/_/_/--\\      |            }}" << std::endl;
    std::cout << "\t\t\t\t{{           +       ===== Game Menu =====.::::.      -O-     {{" << std::endl;
    std::cout << "\t\t\t\t}}      *                .::. `:::::::' .:::::::.      |      }}" << std::endl;
    std::cout << "\t\t\t\t{{ .                  1. Continue::::'  .::::::::::           {{" << std::endl;
    std::cout << "\t\t\t\t}}         ' -     .::2. Save game`:' .::::::::::'      .    +}}" << std::endl;
    std::cout << "\t\t\t\t{{ -- )--       .:::::3. Load Game.   :::::::::::             {{" << std::endl;
    std::cout << "\t\t\t\t}}       *   .::::::::4. About:::::' . `::::::::'      o      }}" << std::endl;
    std::cout << "\t\t\t\t{{          ::::::::::5. Exit to Main Menu.:::::              {{" << std::endl;
    std::cout << "\t\t\t\t}}      .    `::::::::::::::::::' .:::::.  `:::'          @   }}" << std::endl;
    std::cout << "\t\t\t\t{{   o  '-     `:::::::::::::::' .::::::::.  `'    +          {{" << std::endl;
    std::cout << "\t\t\t\t}}      :  |      `::::::::::::' .::::::::::.             +   }}" << std::endl;
    std::cout << "\t\t\t\t{{      !       .    `::::::::'  .:::::::::::::.      @      o{{" << std::endl;
    std::cout << "\t\t\t\t}}      |                           *          o           .  }}" << std::endl;
    std::cout << "\t\t\t\t{{{{{{{{|_{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{" << std::endl;
    cout << "\t\t\t\t     ,  | `.                *.       ";
}

void DisplayAboutMenu() {
    ClearScreen();
    std::cout << "\n\n\n\t\t\t\t}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}}" << std::endl;
    std::cout << "\t\t\t\t{{ (c)           +         . _           +        +   @       {{" << std::endl;
    std::cout << "\t\t\t\t}}   |               _, ;  `._   ____  __.::  +               }}" << std::endl;
    std::cout << "\t\t\t\t{{  -O-    o       -\\ \\-+--/| | | / / / /\\--- --       +      {{" << std::endl; 
    std::cout << "\t\t\t\t}}   |               \\_\\/\\/ \\_\\_//_/_/_/--\\      |            }}" << std::endl;
    std::cout << "\t\t\t\t{{           +       ===== About Menu =====::::.      -O-     {{" << std::endl;
    std::cout << "\t\t\t\t}}      *                .::. `:::::::' .:::::::.      |      }}" << std::endl;
    std::cout << "\t\t\t\t{{ .                  1. Credits`::::'  .::::::::::           {{" << std::endl;
    std::cout << "\t\t\t\t}}         ' -     .::2. FAQ:::.  `:' .::::::::::'      .    +}}" << std::endl;
    std::cout << "\t\t\t\t{{ -- )--       .:::::3. Exit to main menu::::::              {{" << std::endl;
    std::cout << "\t\t\t\t}}       *   .::::::::::::::::::::' . `::::::::'      o       }}" << std::endl;
    std::cout << "\t\t\t\t{{          :::::::::::::::::::::' .::.  `.:::::              {{" << std::endl;
    std::cout << "\t\t\t\t}}      .    `::::::::::::::::::' .:::::.  `:::'          @   }}" << std::endl;
    std::cout << "\t\t\t\t{{   o  '-     `:::::::::::::::' .::::::::.  `'    +          {{" << std::endl;
    std::cout << "\t\t\t\t}}      :  |      `::::::::::::' .::::::::::.             +   }}" << std::endl;
    std::cout << "\t\t\t\t{{      !       .    `::::::::'  .:::::::::::::.      @      o{{" << std::endl;
    std::cout << "\t\t\t\t}}      |                           *          o           .  }}" << std::endl;
    std::cout << "\t\t\t\t{{{{{{{{|_{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{{" << std::endl;
    cout << "\t\t\t\t     ,  | `.                *.       ";
}


void DisplayCredits() {
    ClearScreen();
        cout << "                                   \t\t\t\t\t\t\t\t\tChatgpt made 90%";
    cout << "\t\t\t\t                                         __...---`````_,\n";
    cout << "\t\t\t\t       .-``-.     .-``-......__.-``   _.--``````  ___,\n";
    cout << "\t\t\t\t      ^      :   :               -`````---````````_,\n";
    cout << "\t\t\t\t      ^_      :  :....._                    _.-```\n";
    cout << "\t\t\t\t       |`|-.   `.    o  ``-.__.-`````...````\n";
    cout << "\t\t\t\t            `.   `...__. ,'.___.-```;:'\n";
    cout << "\t\t\t\t              `._     ; ;        .:'___,\n";
    cout << "\t\t\t\t                ````` ;        _...--`\n";
    cout << "\t\t\t\t              __..--```       -```-.\n";
    cout << "\t\t\t\t      .|,|_.-``___....---```````--.._\n";
    cout << "\t\t\t\t     `-,,--```     ..---```````--.\n";
    std::cout << "\t\t\t.         _  .          .          .    +     .          .          .      .\n";
	std::cout << ". .        .  .       .    .      .    .          ===== Credits =====     . .     .     .    .                     \n";
	std::cout << ". .        .  .       .              .     .     .    .      .   .     .     .        .      .   .      . .  .  -+-\n";
	std::cout << "  .    .           .         +       .      Game developed by: Ronin Abonita  /    .           .          @   \n";
	std::cout << ".            .  /         .            .        *   .       . .        .  .      /.   .      .    .     .     .   \n";
	std::cout << ".  +       .     .   .      .    .         Published for: Asia Pacific College    +      .        .         .\n";
	std::cout << "  . .        .  .       .              .     .  .            .  /         .            .        *   .         .     .\n";
	std::cout << ". .        .  .       .         Game code available in Github: (https://github.com/RoninSenpai).     .         . .\n";
	std::cout << " .        .  .       .   .      .    .     .     .    .      .      .           .           .           .           .         +  .\n";
	std::cout << ".    .      .   .     .     .        .      .   .      . .  .  -+-  . .        .  .       .   .      .    .     .     .    .      .   .\n";
	std::cout << "\t\t\t.   +      .          ___/\\_._/~~\\_...__/\\__.._._/~\\        .         .   .\n";
	std::cout << "\t\t\t       .          _.--'                              `--./\\          .   .\n";
	std::cout << "\t\t\t           /~~\\/~\\                                         `-/~\\_            .\n";
	std::cout << "\t\t\t.      .-'                                                      `-/\\_\n";
	std::cout << "\t\t\t _/\\.-'                                                          __/~\\/\\-.__\n";
	std::cout << "\t\t\t.'                                                                           `.";
    
    std::cout << ".. ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}


void DisplayFAQ() {
    ClearScreen();
    std::cout << "===== Frequently Asked Questions (FAQ) =====" << std::endl;
    std::cout << "Q: How do I play the game?" << std::endl;
    std::cout << "A: Input numbers to represent the row and columns. This can be represented as two separate inputs,\n e.g., '1 2, 1 3' or '1, 2, 1, 3'" << std::endl;
    std::cout << "\n\nQ: How do I navigate through the game menu?" << std::endl;
	std::cout << "A: In the game menu, use the corresponding number keys to select different options. \nFor example, '1' to continue, '2' to save, '3' to load, \n'4' to access the About section, and '5' to return to the main menu." << std::endl;

	cout << "\nQ: How can I activate the powers in the game?\033[0m\n";
	cout << "A: To activate your chosen path's power, use the following activation codes:\033[0m\n";
	cout << "\033[31m-666: Demonic Path\n\033[0m";
	cout << "\033[33m-777: Heaven Path\n\033[0m";
	cout << "\033[36m-9: Wisdom Path\033[0m\n";
	cout << "Simply enter the appropriate activation code when prompted during your journey.\033[0m\n";
	
	cout << "\nQ: What happens if I choose the Demonic Path and enter -666?\033[0m\n";
	cout << "\033[31mA: If you've chosen the Demonic Path and you enter -666, you'll be able to harness the malevolent aura. ";
	cout << "The demons will assist you by resetting the battlefield and your moves, granting you a fresh start in your journey.\033[0m\n";
	
	cout << "\nQ: How do I access the powers of the Heaven Path using -777?\033[0m\n";
	cout << "\033[33mA: If you've chosen the Heaven Path and enter -777, the divine powers of heaven will bless you. ";
	cout << "You'll receive 10 free matches to aid you in your quest and a mystery power awaits. Pray and be thankful for this divine gift.\033[0m\n";
	
	cout << "\nQ: What is the activation code for the Wisdom Path?\033[0m\n";
	cout << "\033[36mA: The Wisdom Path activation code is -9. By entering this code, you'll be presented with a choice to embrace the path ";
	cout << "of knowledge and receive 5 free moves or to embrace stillness and skip the current round. Choose wisely, young one.\033[0m\n";


    std::cout << "=============================================" << std::endl;
    
    std::cout << "Press Enter to return to the About menu... ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
void SaveGame(const string& filename, int currentRound, int matchesNeeded, int maxMoves) {
    ofstream saveFile(filename.c_str()); 
    if (saveFile.is_open()) {
    
        saveFile << currentRound << " " << matchesNeeded << " " << maxMoves << " " << moves << " " << matches << "\n";
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                saveFile << gameBoard[i][j].type << " ";
            }
            for (int k = 0; k < 100 - numCols * 2; ++k) {
                saveFile << "*";
            }
            saveFile << "\n";
        }
        saveFile.close();
    } else {
        cout << "Failed to open the save file." << endl;
    }
}

void LoadGame(const string& filename, int& currentRound, int& matchesNeeded, int& maxMoves) {
    ifstream loadFile(filename.c_str()); 
    if (loadFile.is_open()) {
        
        loadFile >> currentRound >> matchesNeeded >> maxMoves >> moves >> matches;
        loadFile.ignore(numeric_limits<streamsize>::max(), '\n'); 
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                loadFile >> gameBoard[i][j].type;
            }
            loadFile.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
        loadFile.close();
    } else {
        cout << "Failed to open the load file." << endl;
    }
}


void HeavenPower() {
    cout << "You have chosen the Heaven path." << endl;
    cout << "You can use the Heaven power to reset the board once." << endl;
}

void DemonicPower() {
    cout << "You have chosen the Demonic path." << endl;
    cout << "You can use the Demonic power to reset the game and get 10 free matches." << endl;
}

void WisdomPower() {
    cout << "You have chosen the Wisdom path." << endl;
    cout << "You can use the Wisdom power here (implement the power logic)." << endl;
}

void InitializeGame(bool isHeavenChosen, bool isDemonicChosen, bool isWisdomChosen) {
    
    if (isHeavenChosen) {
        if (heavenPowerAvailable = true) {
            InitializeGameBoard();  
        } else {
            cout << "You have already used the power of the Heaven path." << endl;
        }
    } else if (isDemonicChosen) {

        if (demonicPowerAvailable = true) {
        	InitializeGameBoard();
            ResetGameBoard();
            moves = 0;
        } else {
            cout << "You have already used the power of the Demonic path." << endl;
        }
    } else if (isWisdomChosen) {
        if (wisdomPowerAvailable = true) {
            InitializeGameBoard();  
    }
}
}


int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

    int choice = 0;
    bool inMainMenu = true;
    bool inGameMenu = false;
    bool exitFlag = false;
	bool resetFlag = false;
	bool heavenPowerAvailable = false;
	bool demonicPowerAvailable = false;
	bool wisdomPowerAvailable = false;
    const int numSaveSlots = 2;
    string saveSlotNames[numSaveSlots] = {"SaveSlot1.txt", "SaveSlot2.txt"};
    string playerName;

    int currentRound = 1;
    int matchesNeeded = 10;
    int maxMoves = 10;

    while (!exitFlag) {
        if (inMainMenu) {
            DisplayMainMenu();
            cout << "\n\t\t\t       --- --+-<#>-+-(1:-Start New Game, 2: About, 3: Load Game, 4: Exit)\n ";
            cout << "\t\t\t\t     `._|_,'        . :\n";
            cout << "\t\t\t\t +      T         *";
            cout << "\n\t\t\t\t\t\033[97m|Enter your choice:\033[0m ";
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                DisplayWarning("Invalid input. Please enter a number.");
                continue;
            }
            switch (choice) {
             case 1:
             		
             		ClearScreen();
             		
             	    GetPlayerName(playerName);
                    char pathChoice;
                    ClearScreen();
                    DisplayStoryIntro(playerName);

                    do {
                        ClearScreen();
                        
			cout << "\033[33m-777: Heaven Path\033[0m" << endl;
			cout << "\033[31m-666: Demonic Path\033[0m" << endl;
			cout << "\033[36m-9: Wisdom Path\033[0m" << endl;
			
			cout << "\t\t\t\t\033[33m¦ The Heaven Path (H): Choosing this path, \033[97m" << playerName << "\033[33m" << endl
			     << "\t\t\t\t\033[33m¦ unlocks celestial powers of benevolence and" << endl
			     << "\t\t\t\t¦ enlightenment. It allows them to harness cosmic" << endl
			     << "\t\t\t\t¦ forces for virtuous purposes, offering protection" << endl
			     << "\t\t\t\t¦ and healing to those in need.\033[0m" << endl;
			
			cout << "\t\t\t\t\033[31m¦ The Demonic Path (D): By venturing down the Demonic" << endl
			     << "\t\t\t\t\033[31m¦ Path, \033[0m" << playerName << " \033[31mgains control over dark," << endl
			     << "\t\t\t\t\033[31m¦ malevolent energies hidden deep within the cosmos." << endl
			     << "\t\t\t\t\033[31m¦ However, this power comes at a cost, risking the" << endl
			     << "\t\t\t\t\033[31m¦ corruption of their very soul.\033[0m" << endl;
			
			cout << "\t\t\t\t\033[36m¦ The Wisdom Path (W): The Wisdom Path is one of" << endl
			     << "\t\t\t\t\033[36m¦ knowledge and insight. It enables \033[0m" << playerName << " \033[36mto" << endl
			     << "\t\t\t\t\033[36m¦ grasp the profound mysteries of the cosmos and" << endl
			     << "\t\t\t\t\033[36m¦ their own inner self. This path provides strategic" << endl
			     << "\t\t\t\t\033[36m¦ advantages and the ability to make wise decisions.\033[0m" << endl;

			cout << "\nSelect your martial path and shape your destiny:" << endl;
			cout << "\033[33m1. Heaven Path (H)\033[0m - Unlock celestial powers of benevolence and enlightenment. Harness cosmic forces for virtuous purposes, offering protection and healing to those in need." << endl;
			cout << "\033[31m2. Demonic Path (D)\033[0m - Gain control over dark, malevolent energies hidden deep within the cosmos. This power comes at a cost, risking the corruption of your very soul." << endl;
			cout << "\033[36m3. Wisdom Path (W)\033[0m - Grasp the profound mysteries of the cosmos and your own inner self. Gain strategic advantages and the ability to make wise decisions." << endl;
			cout << "Enter the letter of your chosen path (e.g., 'H', 'D', 'W'): ";

                        cin >> pathChoice;

                        if (pathChoice == 'H') {
                            isHeavenPathChosen = true;
                            
                        } else if (pathChoice == 'D') {
                            isDemonicPathChosen = true;
                           
                        } else if (pathChoice == 'W') {
                            isWisdomPathChosen = true;
                           
                        } else {
                            cout << "Invalid path choice. Please select 'H', 'D', or 'W'." << endl;
                        }
                    } while (pathChoice != 'H' && pathChoice != 'D' && pathChoice != 'W');

                    InitializeGame(isHeavenPathChosen, isDemonicPathChosen, isWisdomPathChosen);
                    inMainMenu = false;
                    break;
                case 2:
                    while (!exitFlag) {
                        DisplayAboutMenu();
                        cout << "\n\t\t\t       --- --+-<#>-+-(1:-Credits, 2: FAQ, 3: Exit to main menu)\n ";
                        cout << "\t\t\t\t     `._|_,'        . :\n";
                        cout << "\t\t\t\t +      T         *";
                        cout << "\n\t\t\t\t\t\033[97m|Enter your choice:\033[0m ";
                        if (!(cin >> choice)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Invalid input. Please enter a number." << endl;
                            continue;
                        }

                        switch (choice) {
                            case 1:
                                DisplayCredits();
                                break;
                            case 2:
                                DisplayFAQ();
                                break;
                            case 3:
                                exitFlag = true;
                                break;
                            default:
                                cout << "Invalid choice. Try again." << endl;
                                break;
                        }
                    }
                    choice = 0;
                    exitFlag = false;
                    break;
                case 3:
                    int loadSlot;
                    cout << "\n\t\t\t\t\tSelect a load slot (1 or 2): ";
                    cin >> loadSlot;
                    if (loadSlot >= 1 && loadSlot <= numSaveSlots) {
                        LoadGame(saveSlotNames[loadSlot - 1], currentRound, matchesNeeded, maxMoves);
                        cout << "Game loaded successfully from Slot " << loadSlot << endl;
                    } else {
                        cout << "Invalid load slot. Please select 1 or 2." << endl;
                    }
                    inGameMenu = false;
                    inMainMenu = false;
                    break;
                case 4:
                    cout << "Thanks for playing! Exiting..." << endl;                 
					exitFlag = true;
                    break;
                default:
                    cout << "Invalid choice. Try again." << endl;
                    break;
            }
        } else if (inGameMenu) {
            DisplayInGameMenu();
            cout << "\n\t\t\t       --- --+-<#>-+-(1:-Continue, 2-3: Save/Load, 4: About, 5: Exit to main menu)\n ";
            cout << "\t\t\t\t     `._|_,'        . :\n";
            cout << "\t\t\t\t +      T         *";
            cout << "\n\t\t\t\t\t\033[97m|Enter your choice:\033[0m ";
            cin >> choice;
            switch (choice) {
                case 1:
                    inGameMenu = false;
                    break;
                case 2:
                    int saveSlot;
                    cout << "\n\t\t\t\t\tSelect a save slot (1 or 2): ";
                    cin >> saveSlot;
                    if (saveSlot >= 1 && saveSlot <= numSaveSlots) {
                        SaveGame(saveSlotNames[saveSlot - 1], currentRound, matchesNeeded, maxMoves);
                        cout << "Game saved successfully in Slot " << saveSlot << endl;
                    } else {
                        cout << "Invalid save slot. Please select 1 or 2." << endl;
                    }
                    break;
                case 3:
                    int loadSlot;
                    cout << "\n\t\t\t\t\tSelect a load slot (1 or 2): ";
                    cin >> loadSlot;
                    if (loadSlot >= 1 && loadSlot <= numSaveSlots) {
                        LoadGame(saveSlotNames[loadSlot - 1], currentRound, matchesNeeded, maxMoves);
                        cout << "Game loaded successfully from Slot " << loadSlot << endl;
                    } else {
                        cout << "Invalid load slot. Please select 1 or 2." << endl;
                    }
                    inGameMenu = false;
                    inMainMenu = false;
                    break;
                case 4:
                    while (!exitFlag) {
                        DisplayAboutMenu();
                        cout << "\n\t\t\t       --- --+-<#>-+-(1:-Credits, 2: FAQ, 3: Exit to main menu)\n ";
                        cout << "\t\t\t\t     `._|_,'        . :\n";
                        cout << "\t\t\t\t +      T         *";
                        cout << "\n\t\t\t\t\t\033[97m|Enter your choice:\033[0m ";
                        if (!(cin >> choice)) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Invalid input. Please enter a number." << endl;
                            continue;
                        }

                        switch (choice) {
                            case 1:
                                DisplayCredits();
                                break;
                            case 2:
                                DisplayFAQ();
                                break;
                            case 3:
                                exitFlag = true;
                                break;
                            default:
                                cout << "Invalid choice. Try again." << endl;
                                break;
                        }
                    }
                    choice = 0;
                    exitFlag = false;
                    break;
                case 5:
                    inGameMenu = false;
                    inMainMenu = true;
                    ResetGameBoard();
                    moves = 0;
                    resetFlag = true;
					currentRound = 1;
    			    matchesNeeded = 10;
   					maxMoves = 10;
   					matches = 0;
   					isHeavenPathChosen = false;
					isDemonicPathChosen = false;
				    isWisdomPathChosen = false;
				    heavenPowerAvailable = false;
				    demonicPowerAvailable = false;
				    wisdomPowerAvailable = false;
                    break;
                default:
                    cout << "Invalid choice. Try again." << endl;
                    break;
            }
        } else {
            DisplayGameBoard();

            cout << "\nRound: " << currentRound << " / " << matchesNeeded << "   Moves left: " << maxMoves - moves << "   Matches: " << matches << "    Matches needed: " << matchesNeeded << endl;

            if (resetFlag) {
                cout << "Enter the row and column (e.g., '3' or '3 4') to swap martial skills (-1 to exit, -5 for menu): ";
                resetFlag = false;
            } else {
                cout << "Enter the row and column (e.g., '3' or '3 4') to swap martial skills (-1 to exit, -5 for menu): ";
            }
            

            int r1, c1, r2, c2;
            cin >> r1;


			if (r1 == -777) {
			    if (isHeavenPathChosen && !heavenPowerAvailable) {
			        cout << "\n\033[33mThe power of the heavens has granted you an equal choice, blessed one:\033[0m" << endl;
			        cout << "\033[33m1. Accept the divine gift of 10 free matches (Enter '10')\033[0m\n";
			        cout << "\033[36m2. Seek the wisdom of the sacred path (Enter 'W')\033[0m\n";
			        cout << "\033[31m3. Embrace your malevolent side (Enter 'D')\033[0m\n";
			        cout << "\033[33mMake your choice with gratitude: ";
			        string heavenChoice;
			        cin >> heavenChoice;
			
			        if (heavenChoice == "10") {
			            // Option 1: Receive 10 free matches
			            matches += 10;
			            heavenPowerAvailable = true;
			            InitializeGame(isHeavenPathChosen, isDemonicPathChosen, isWisdomPathChosen);
			            cout << "\n\033[33mThe power of the heavens has granted you 10 free matches. Pray and be thankful.\033[0m" << endl;
			        } else if (heavenChoice == "W" || heavenChoice == "w") {
			            // Option 2: Seek the wisdom of the sacred path
			            cout << "\n\033[36mIn the sacred realm of wisdom, the cosmos guides your choice, young one.\033[0m" << endl;
			            currentRound++;
			            cout << "\n\033[36mIn the spirit of patience, you choose to skip the current round. Prepare for the next chapter, young one!\033[0m" << endl;
			            heavenPowerAvailable = true;
			        } else if (heavenChoice == "D" || heavenChoice == "d") {
			            // Option 3: Embrace your malevolent side
			            cout << "\n\033[31mAs you channel your malevolent aura, the wuxia demons acknowledge your presence and reset the battlefield. Rejoice, mortal!\033[0m" << endl;
			            ResetGameBoard();
			            moves = 0;
			            resetFlag = true;
			            InitializeGame(isHeavenPathChosen, isDemonicPathChosen, isWisdomPathChosen);
			            heavenPowerAvailable = true;
			        } else {
			            cout << "\n\033[33mYour indecision brings no favor from the heavens. Choose wisely next time, blessed one.\033[0m" << endl;
			        }
			
			        // Consume the newline character in the input stream
			        cin.ignore(numeric_limits<streamsize>::max(), '\n');
			    } else if (!isHeavenPathChosen) {
			        cout << "\n\033[33mYou must tread the path of the Heaven to unlock its power. Seek the celestial light, blessed one.\033[0m" << endl;
			        cin.ignore(numeric_limits<streamsize>::max(), '\n');
			    } else if (heavenPowerAvailable) {
					cout << "\n\033[33mYour divine blessing has been spent, blessed one. Offer your prayers and seek repentance, for strength shall soon be showered upon you.\033[0m" << endl;
			        cin.ignore(numeric_limits<streamsize>::max(), '\n');
			   }
		    }
		
			if (r1 == -666) {
			    if (isDemonicPathChosen && !demonicPowerAvailable) {
			        cout << "\n\033[31mAs you channel your malevolent aura, the wuxia demons acknowledge your presence. They offer you a choice:\033[0m" << endl;
			        cout << "\033[31m1. Accept their dark gift and reset the battlefield (Enter 'R')\033[0m\n";
			        cout << "\033[31m2. Embrace your inner chaos and reset your moves back to their original number for this round (Enter 'M')\033[0m\n";
			        cout << "\033[31mChoose your path with malice: ";
			        char demonicChoice;
			        cin >> demonicChoice;
			
			        if (demonicChoice == 'R' || demonicChoice == 'r') {
			            // Option 1: Reset the battlefield
			            ResetGameBoard();
			            moves = 0;
			            resetFlag = true;
			            demonicPowerAvailable = true;
			            InitializeGame(isHeavenPathChosen, isDemonicPathChosen, isWisdomPathChosen);
			            cout << "\n\033[31mYour malevolent aura has beckoned the demons, and they've decided to extend a helping hand by resetting your battlefield. Rejoice, mortal!\033[0m" << endl;
			        } else if (demonicChoice == 'M' || demonicChoice == 'm') {
			            // Option 2: Reset moves
			            moves = 0;  // You might need to set moves back to the original number for this round
			            demonicPowerAvailable = true;
			            cout << "\n\033[31mEmbracing your inner chaos, you reset your moves back to their original number for this round. The chaos within guides you.\033[0m" << endl;
			        } else {
			            cout << "\n\033[31mYour indecision brings no favor from the demons. Choose wisely next time, mortal.\033[0m" << endl;
			        }
			
			        // Consume the newline character in the input stream
			        cin.ignore(numeric_limits<streamsize>::max(), '\n');
					} else if (!isDemonicPathChosen) {
					    cout << "\n\033[31mBeware, for you cannot channel the power of the Demonic path, as you have not chosen this path. Be cautious when gazing into the abyss, for it gazes back.\033[0m" << endl;
					    cin.ignore(numeric_limits<streamsize>::max(), '\n');
					} else if (demonicPowerAvailable) {
					    cout << "\n\033[31mTake heed, for you have already harnessed the might of the Demonic path and must wait for the cosmic forces to align once more. Patience, mortal.\033[0m" << endl;
					    cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
			}

			if (r1 == -9) {
			    if (isWisdomPathChosen && !wisdomPowerAvailable) {
			        cout << "\n\033[36mIn the sacred realm of wisdom, a choice is presented before you, young one.\033[0m" << endl;
			        cout << "\033[36m1. Gaze upon the path of knowledge and receive 5 free moves (Enter '5')\033[0m\n";
			        cout << "\033[36m2. Embrace the stillness of the cosmos and skip the current round (Enter 'S')\033[0m\n";
			        cout << "\033[36mEnter your choice with humility: ";
			        char wisdomChoice;
			        cin >> wisdomChoice;
			
			        if (wisdomChoice == '5') {
			            // Option 1: Receive 5 free moves
			            maxMoves += 5;
			            cout << "\033[36mWith an open heart, you gain 5 free moves to navigate the cosmos. Use them wisely!\033[0m" << endl;
			        } else if (wisdomChoice == 'S' || wisdomChoice == 's') {
			            // Option 2: Skip the current round
			            currentRound++;
			            cout << "\033[36mIn the spirit of patience, you choose to skip the current round. Prepare for the next chapter!\033[0m" << endl;
			        } else {
			            cout << "\033[36mYour indecision brings no change. Reflect and choose wisely next time.\033[0m" << endl;
			        }
			
			        wisdomPowerAvailable = true;  // Mark Wisdom power as used only when a valid choice is made
			
			        // Consume the newline character in the input stream
			        cin.ignore(numeric_limits<streamsize>::max(), '\n');
			    } else if (!isWisdomPathChosen) {
			        cout << "\n\033[36mYou must tread the path of wisdom to unlock its power. Seek inner knowledge, young one.\033[0m" << endl;
			        cin.ignore(numeric_limits<streamsize>::max(), '\n');
			    } else if (wisdomPowerAvailable) {
			        cout << "\n\033[36mYou have already harnessed the power of wisdom and cannot channel it again at this time.\033[0m" << endl;
			        cin.ignore(numeric_limits<streamsize>::max(), '\n');
			    }
			}

		        	
            if (cin.fail()) {
	            cin.clear();
	            cin.ignore(numeric_limits<streamsize>::max(), '\n');
	            DisplayWarning("Invalid input. Try again.");
	            continue;
	        } else if (r1 == -100) {
                ResetGameBoard();
                moves = 0;
                resetFlag = true;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            } else if (r1 == -1) {
                cout << "Thanks for playing! Exiting..." << endl;
                exitFlag = true;
            } else if (r1 == -5) {
                inGameMenu = true;
            } else if (r1 >= 0 && r1 < numRows) {
                cin >> c1 >> r2 >> c2;

                /*if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    DisplayWarning("Invalid input. Try again.");
                    continue;
                }*/



                if (c1 >= 0 && c1 < numCols && r2 >= 0 && r2 < numRows && c2 >= 0 && c2 < numCols) {
                    if (IsValidSwap(r1, c1, r2, c2)) {
                        swap(gameBoard[r1][c1], gameBoard[r2][c2]);
                        moves++;

                        if (IsMatch(r1, c1)) {
                            RemoveMatches(r1, c1);
                        }
                        if (IsMatch(r2, c2)) {
                            RemoveMatches(r2, c2);
                        }
                        FillEmptyTiles();
                        UpdateGameBoard();
                        matches += matchCounter;
                        matchCounter = 0;

                        if (matches >= matchesNeeded) {
                            currentRound++;
                            matchesNeeded += 10;
                            matches = 0;
                            maxMoves += 5; 
                        }
                    } else {
                        DisplayWarning("Invalid swap. You can only move in a cross direction of 1 tile beside you.");
                        resetFlag = true;
                    }
                } else {
                    DisplayWarning("Invalid input. Try again.");
                }
            } else {
                DisplayWarning("Invalid input. Try again.");
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}


