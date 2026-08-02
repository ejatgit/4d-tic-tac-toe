#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <limits>
#include <locale>
//#include <windows.h>

// --- Platform Headers for Console Setup ---
#if defined(_WIN32)
    #include <windows.h> // Required for SetConsoleOutputCP
#else
    // POSIX systems often require 'unistd' or similar, but setting locale is usually sufficient 
    // if the environment variable (LANG/LC_ALL) is correct.
#endif

/**
 * @brief Sets the console output encoding to UTF-8.
 */
void set_console_utf8() {
    // Check if we are on Windows
#ifdef _WIN32
    // Set the standard output code page to UTF-8 (65001)
    if (!SetConsoleOutputCP(CP_UTF8)) {
        std::cerr << "Warning: Failed to set console output code page to UTF-8." << std::endl;
    } else {
        // Success message for debugging, but optional for clean run
        // std::cout << "Console encoding set to UTF-8." << std::endl;
    }
#else 
    // For Unix/Linux/macOS, we rely on the locale setting below 
    // and assume the system environment variables (LANG=...) are set correctly.
#endif
}

void StartScreen(){
//SetConsoleOutputCP(437);
std::cout << ""<< std::endl;
std::cout << ""<< std::endl;
std::cout << "                ██╗    ██╗███████╗██╗      ██████╗ ██████╗ ███╗   ███╗███████╗                         "<< std::endl;
std::cout << "                ██║    ██║██╔════╝██║     ██╔════╝██╔═══██╗████╗ ████║██╔════╝                         "<< std::endl;
std::cout << "                ██║ █╗ ██║█████╗  ██║     ██║     ██║   ██║██╔████╔██║█████╗                           "<< std::endl;
std::cout << "                ██║███╗██║██╔══╝  ██║     ██║     ██║   ██║██║╚██╔╝██║██╔══╝                           "<< std::endl;
std::cout << "                ╚███╔███╔╝███████╗███████╗╚██████╗╚██████╔╝██║ ╚═╝ ██║███████╗                         "<< std::endl;
std::cout << "                 ╚══╝╚══╝ ╚══════╝╚══════╝ ╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚══════╝                         "<< std::endl;
std::cout << "                                                                                                       "<< std::endl;
std::cout << "                                        ████████╗ ██████╗                                              "<< std::endl;
std::cout << "                                        ╚══██╔══╝██╔═══██╗                                             "<< std::endl;
std::cout << "                                           ██║   ██║   ██║                                             "<< std::endl;
std::cout << "                                           ██║   ██║   ██║                                             "<< std::endl;
std::cout << "                                           ██║   ╚██████╔╝                                             "<< std::endl;
std::cout << "                                           ╚═╝    ╚═════╝                                              "<< std::endl;
std::cout << "                                                                                                       "<< std::endl;
std::cout << "██╗  ██╗██████╗     ████████╗██╗ ██████╗      ████████╗ █████╗  ██████╗      ████████╗ ██████╗ ███████╗"<< std::endl;
std::cout << "██║  ██║██╔══██╗    ╚══██╔══╝██║██╔════╝      ╚══██╔══╝██╔══██╗██╔════╝      ╚══██╔══╝██╔═══██╗██╔════╝"<< std::endl;
std::cout << "███████║██║  ██║       ██║   ██║██║     █████╗   ██║   ███████║██║     █████╗   ██║   ██║   ██║█████╗  "<< std::endl;
std::cout << "╚════██║██║  ██║       ██║   ██║██║     ╚════╝   ██║   ██╔══██║██║     ╚════╝   ██║   ██║   ██║██╔══╝  "<< std::endl;
std::cout << "     ██║██████╔╝       ██║   ██║╚██████╗         ██║   ██║  ██║╚██████╗         ██║   ╚██████╔╝███████╗"<< std::endl;
std::cout << "     ╚═╝╚═════╝        ╚═╝   ╚═╝ ╚═════╝         ╚═╝   ╚═╝  ╚═╝ ╚═════╝         ╚═╝    ╚═════╝ ╚══════╝"<< std::endl;
std::cout << ""<< std::endl;
std::cout << "                                             +-------+-------+-------+"<< std::endl;
std::cout << "                                            /       /       /       /|"<< std::endl;
std::cout << "                                           +-------+-------+-------+ |"<< std::endl;
std::cout << "                                          /       /       /       /| +"<< std::endl;
std::cout << "                                         +-------+-------+-------+ |/|"<< std::endl;
std::cout << "                                        /       /       /       /| + |"<< std::endl;
std::cout << "                                       +-------+-------+-------+ |/| +"<< std::endl;
std::cout << "                                       |       |       |       | + |/|"<< std::endl;
std::cout << "                                       |       |       |       |/| + |"<< std::endl;
std::cout << "                                       +-------+-------+-------+ |/| +"<< std::endl;
std::cout << "                                       |       |       |       | + |/"<< std::endl;
std::cout << "                                       |       |       |       |/| +"<< std::endl;
std::cout << "                                       +-------+-------+-------+ |/"<< std::endl;
std::cout << "                                       |       |       |       | +"<< std::endl;
std::cout << "                                       |       |       |       |/"<< std::endl;
std::cout << "                                       +-------+-------+-------+"<< std::endl;
std::cout << ""<< std::endl;
}
// Define the game board (4D)
struct GameBoard {
    std::vector<std::vector<std::vector<std::vector<char>>>> board;
};

// Initialize the game board
void initializeBoard(GameBoard& board) {
    board.board = std::vector<std::vector<std::vector<std::vector<char>>>>(
        3, 
        std::vector<std::vector<std::vector<char>>>(3, 
            std::vector<std::vector<char>>(3, 
                std::vector<char>(3, ' '))));
}

/* Use the below for colored background to show winning selection
0 = white black
7 = white background
X is the text
    printColoredChar('X', 0, 7);
with player variable it would become
    printColoredChar(player, 0, 7);
*/

void printColoredChar(char c, int fg, int bg) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Calculate combined attribute: bg * 16 + fg
    WORD color = (WORD)((bg << 4) | fg);
    SetConsoleTextAttribute(hConsole, color);
    //if(c == 'p'){std::cout << "|";}else{
    std::cout << c;
    //}
}

// Print the 4D board with proper formatting
void printBoard(const GameBoard& board,const GameBoard& winBoard) {
    std::string BoardLeftEdgeSpacing = "   ";
    std::cout << std::endl << BoardLeftEdgeSpacing << "      " << std::endl;
    std::cout << BoardLeftEdgeSpacing << "=============================   Depth (z)" << std::endl;
    
    for (int z = 2; z >= 0; z--) {
        std::cout << BoardLeftEdgeSpacing << "Y+-+-+-+   +-+-+-+   +-+-+-+" << std::endl;
        //std::cout << " z=" << z << std::endl;
        for (int y = 2; y >= 0; y--) {
          std::cout << BoardLeftEdgeSpacing << y ;
          for (int t = 0; t <= 2; t++) {        
                for (int x = 0; x <= 2; x++) {
                    if (x == 0) std::cout << "|";
                    if (winBoard.board[x][y][z][t]=='W')
                    {
                        printColoredChar(board.board[x][y][z][t], 0, 7);
                        printColoredChar('|', 7, 0);
                    }
                    else{
                        printColoredChar(board.board[x][y][z][t], 7, 0);
                        std::cout << "|";
                    }
                    
                    if(x==2){std::cout << "   ";}
                }                       
               // std::cout << "   t";
            }
            if(y==1){std::cout << " z=" << z ;}
            std::cout << std::endl << BoardLeftEdgeSpacing << " +-+-+-+   +-+-+-+   +-+-+-+" ;  
            std::cout << std::endl;
        }        
        std::cout << BoardLeftEdgeSpacing << "X 0 1 2     0 1 2     0 1 2" << std::endl << std::endl;        
    }  
    std::cout << BoardLeftEdgeSpacing << "   t=0       t=1       t=2" << std::endl;
    std::cout << std::endl << BoardLeftEdgeSpacing << "<------- Time (t) -------->" << std::endl;
}

// Check if a player has won
bool checkWin(const GameBoard& board, char player, GameBoard &winBoard) {
   
    /* =====================================
              Check Orthogonal Across
       ===================================== */
    // Check X direction (fixed y, z, t)
    for (int y = 0; y < 3; y++) {
        for (int z = 0; z < 3; z++) {
            for (int t = 0; t < 3; t++) {
                if (board.board[0][y][z][t] == player && board.board[1][y][z][t] == player && board.board[2][y][z][t] == player) {
                 winBoard.board[0][y][z][t] = 'W';   winBoard.board[1][y][z][t] = 'W';   winBoard.board[2][y][z][t] = 'W';
                    return true;
                }
            }
        }
    }
    // Check Y direction (fixed x, z, t)
    for (int x = 0; x < 3; x++) {
        for (int z = 0; z < 3; z++) {
            for (int t = 0; t < 3; t++) {
                if (board.board[x][0][z][t] == player && board.board[x][1][z][t] == player && board.board[x][2][z][t] == player) {
                 winBoard.board[x][0][z][t] = 'W';   winBoard.board[x][1][z][t] = 'W';   winBoard.board[x][2][z][t] = 'W';
                    return true;
                }
            }
        }
    }
    // Check Z direction (fixed x, y, t)
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            for (int t = 0; t < 3; t++) {
                if (board.board[x][y][0][t] == player && board.board[x][y][1][t] == player && board.board[x][y][2][t] == player) {
                 winBoard.board[x][y][0][t] = 'W';   winBoard.board[x][y][1][t] = 'W';   winBoard.board[x][y][2][t] = 'W';
                    return true;
                }
            }
        }
    }
    // Check T direction (fixed x, y, z)
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                if (board.board[x][y][z][0] == player && board.board[x][y][z][1] == player && board.board[x][y][z][2] == player) {
                 winBoard.board[x][y][z][0] = 'W';   winBoard.board[x][y][z][1] = 'W';   winBoard.board[x][y][z][2] = 'W';
                    return true;
                }
            }
        }
    }
    
    /* =====================================
              Check Planar Diagonals
       ===================================== */
      // X Y diagonals
    for (int t = 0; t < 3; t++) {
        for (int z = 0; z < 3; z++) {
            if (board.board[0][0][z][t] == player && board.board[1][1][z][t] == player && board.board[2][2][z][t] == player) {
             winBoard.board[0][0][z][t] = 'W';   winBoard.board[1][1][z][t] = 'W';   winBoard.board[2][2][z][t] = 'W';
                return true;
            }
            else if (board.board[2][0][z][t] == player && board.board[1][1][z][t] == player && board.board[0][2][z][t] == player) {
                  winBoard.board[2][0][z][t] = 'W';   winBoard.board[1][1][z][t] = 'W';   winBoard.board[0][2][z][t] = 'W';
                return true;
            }         
        }
   }
   // Y Z diagonals
   for (int t = 0; t < 3; t++) {
        for (int x = 0; x < 3; x++) {
            if (board.board[x][0][0][t] == player && board.board[x][1][1][t] == player && board.board[x][2][2][t] == player) {
             winBoard.board[x][0][0][t] = 'W';   winBoard.board[x][1][1][t] = 'W';   winBoard.board[x][2][2][t] = 'W';
                return true;
            } 
            else if (board.board[x][2][0][t] == player && board.board[x][1][1][t] == player && board.board[x][0][2][t] == player) {
                  winBoard.board[x][2][0][t] = 'W';   winBoard.board[x][1][1][t] = 'W';   winBoard.board[x][0][2][t] = 'W';
                return true;
            }         
        }
   }
   // t x diagonals
   for (int z = 0; z < 3; z++) {
        for (int y = 0; y < 3; y++) {
            if (board.board[0][y][z][0] == player && board.board[1][y][z][1] == player && board.board[2][y][z][2] == player) {
             winBoard.board[0][y][z][0] = 'W';   winBoard.board[1][y][z][1] = 'W';   winBoard.board[2][y][z][2] = 'W';
                return true;
            }  
            else if (board.board[2][y][z][0] == player && board.board[1][y][z][1] == player && board.board[0][y][z][2] == player) {
                  winBoard.board[2][y][z][0] = 'W';   winBoard.board[1][y][z][1] = 'W';   winBoard.board[0][y][z][2] = 'W';
                return true;
            }           
        }
   }
   // t y diagonals
   for (int z = 0; z < 3; z++) {
        for (int x = 0; x < 3; x++) {
            if (board.board[x][0][z][0] == player && board.board[x][1][z][1] == player && board.board[x][2][z][2] == player) {
             winBoard.board[x][0][z][0] = 'W';   winBoard.board[x][1][z][1] = 'W';   winBoard.board[x][2][z][2] = 'W';
                return true;
            }  
            else if (board.board[x][2][z][0] == player && board.board[x][1][z][1] == player && board.board[x][0][z][2] == player) {
                  winBoard.board[x][2][z][0] = 'W';   winBoard.board[x][1][z][1] = 'W';   winBoard.board[x][0][z][2] = 'W';
                return true;
            }           
        }
   }
    // t z diagonals
   for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            if (board.board[x][y][0][0] == player && board.board[x][y][1][1] == player && board.board[x][y][2][2] == player) {
             winBoard.board[x][y][0][0] = 'W';   winBoard.board[x][y][1][1] = 'W';   winBoard.board[x][y][2][2] = 'W';
                return true;
            }   
            else if (board.board[x][y][2][0] == player && board.board[x][y][1][1] == player && board.board[x][y][0][2] == player) {
                  winBoard.board[x][y][2][0] = 'W';   winBoard.board[x][y][1][1] = 'W';   winBoard.board[x][y][0][2] = 'W';
                return true;
            }           
        }
   }
      // X Z diagonals (Fix Y, Fix T) - From LM Studio - gemma-4-eb4
    for (int y = 0; y < 3; y++) {
        for (int t = 0; t < 3; t++) {
            if (board.board[0][y][0][t] == player && board.board[1][y][1][t] == player && board.board[2][y][2][t] == player) {
             winBoard.board[0][y][0][t] = 'W';   winBoard.board[1][y][1][t] = 'W';   winBoard.board[2][y][2][t] = 'W';
                return true;
            }  
        else if (board.board[2][y][0][t] == player && board.board[1][y][1][t] == player && board.board[0][y][2][t] == player) {
              winBoard.board[2][y][0][t] = 'W';   winBoard.board[1][y][1][t] = 'W';   winBoard.board[0][y][2][t] = 'W';
                return true;
            }
        }
   }
   
   /* =====================================
               Check Space Diagonals
      ===================================== */
    int Corner[4]; // Stores coordinates of the starting corner (C_x, C_y, C_z, C_t)
    int OppCorner[4]; // Stores coordinates of the opposite corner (Opp_x, ...)
    if (board.board[1][1][1][1] == player){
        //Only check if the central cell is filled by the current player.
        for (int i = 0; i < 16; i++) {            
            int Temp = i; // Use a temporary copy of the loop index
            // --- Step 1: Determine the coordinates of the starting corner and opposite corner ---
            // We use bitwise checking on 'i'. If the k-th bit is set (1), the coordinate is 2. If unset (0), it's 0.
            for (int k = 0; k < 4; k++) {
                // Loop through dimensions: X=0, Y=1, Z=2, T=3
                // Calculate corner coordinates (0 or 2)
                if ((Temp & 1) == 0) {
                    // Bit is 0
                    Corner[k] = 0;
                    OppCorner[k] = 2; // Opposite must be 2
                }else{ // Bit is 1
                    Corner[k] = 2;
                    OppCorner[k] = 0; // Opposite must be 0
                }
                // Shift the mask to check the next bit (X -> Y -> Z -> T)
                Temp = Temp / 2;
            }
        
            // Note: The loop above calculates C_x, C_y, C_z, C_t and Opp_x, Opp_y, Opp_z, Opp_t
        
            // --- Step 2: Check the win condition for this hyperdiagonal ---
        
            if (board.board[Corner[0]][Corner[1]][Corner[2]][Corner[3]] == player &&
                board.board[1][1][1][1] == player &&
                board.board[OppCorner[0]][OppCorner[1]][OppCorner[2]][OppCorner[3]] == player){
                // A win has been found!
                winBoard.board[Corner[0]][Corner[1]][Corner[2]][Corner[3]] = 'W';
                winBoard.board[1][1][1][1] = 'W';
                winBoard.board[OppCorner[0]][OppCorner[1]][OppCorner[2]][OppCorner[3]] = 'W';
                // Assign a unique code indicating a space diagonal victory.
                return true; // Since we only need to find one win, we exit immediately.
            }
        }
    }
    return false;
}

// Get player move with input validation
std::tuple<int, int, int, int> getPlayerMove(const GameBoard& board) {
    const int min = 0, max = 2;
    
    // Helper function for validated input
    auto validate = [&min, &max](int& value) {
        while (true) {
            std::cin >> value;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Please enter a number: ";
                continue;
            }
            if (value >= min && value <= max) {
                return true;
            }
            std::cout << "Invalid input. Please enter a number between " 
                      << min << " and " << max << ": ";
        }
    };

    int x, y, z, t;
    
    std::cout << "\nEnter x ("<< min << "-" << max << "): ";
    validate(x);
    std::cout << "Enter y ("<< min << "-" << max << "): ";
    validate(y);
    std::cout << "Enter z ("<< min << "-" << max << "): ";
    validate(z);
    std::cout << "Enter t ("<< min << "-" << max << "): ";
    validate(t);

    return std::make_tuple(x, y, z, t);
}

// Make a move
bool makeMove(GameBoard& board, int x, int y, int z, int t, char player) {
   
    if(board.board[x][y][z][t]!='X' && board.board[x][y][z][t]!='O'){
        board.board[x][y][z][t] = player;
        return true;
    }
    return false;    
}

// Check if the board is full
bool isBoardFull(const GameBoard& board) {
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            for (int z = 0; z < 3; z++) {
                for (int t = 0; t < 3; t++) {
                    if (board.board[x][y][z][t] == ' ') {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    srand(time(0));
     // 1. Set console encoding first to ensure output stream is ready for UTF-8.
    set_console_utf8();

    // 2. Set the C++ locale for robust handling of multi-byte characters within the program logic.
    try {
        std::locale::global(std::locale(""));
        std::wcout.imbue(std::locale());

    } catch (const std::runtime_error& e) {
        // Fallback warning if locale setting fails
        std::cerr << "Warning: Could not set system locale for UTF-8 characters. Output might be corrupted." << std::endl;
    }
    GameBoard board;
    initializeBoard(board);
    GameBoard winBoard;
    initializeBoard(winBoard);

    char currentPlayer = 'X';
    bool computerPlayerMode = false;
    bool fullcomputerMode = false;
    /*int pt1win[4];
    int pt2win[4];
    int pt3win[4];*/
    
    // Main menu
    StartScreen();
    std::cout << "4D Tic-Tac-Toe Game (3x3x3x3)" << std::endl;
    std::cout << "Do you want the computer to play against itself? (Y/N): ";
    char choice;
    std::cin >> choice;    
    if (choice == 'Y' || choice == 'y') {
        fullcomputerMode = true;
        std::cout << "Computer playing against computer..." << std::endl;
        }
        else{
            std::cout << "Would you like to play against the computer? (Y/N): ";
            char choice2;
            std::cin >> choice2; 
            if(choice2 == 'Y' || choice2 == 'y')
            {
                computerPlayerMode = true;
                std::cout << std::endl <<"You go first human, and you are 'X'."<< std::endl << "The computer is 'O'." << std::endl << "Playing against computer..." << std::endl;
            }
        }
    
    
    // Game loop
    while (true) {
        printBoard(board,winBoard);
               
        // Check if board is full (draw)
        if (isBoardFull(board)) {
            std::cout << "Draw!" << std::endl;
            break;
        }
        
        // Player move
        std::cout << "\n" << currentPlayer << "'s turn" << std::endl;
        if (!fullcomputerMode && !computerPlayerMode) {
            //std::cout << "\n" << currentPlayer << "'s turn" << std::endl;
            
            bool isValid = false;
            do {
                auto move = getPlayerMove(board);
                int x = std::get<0>(move);
                int y = std::get<1>(move);
                int z = std::get<2>(move);
                int t = std::get<3>(move);
                //makeMove(board, x, y, z, t, currentPlayer);
                isValid = makeMove(board, x, y, z, t, currentPlayer); // Returns true if valid, false otherwise
                        if (!isValid) {
                            std::cout << "Invalid move. Please try again." << std::endl;
                        }
                } while (!isValid); // Loop again if the result is false  
        }  
        else if (computerPlayerMode && currentPlayer=='X') {
            std::cout << "\nHuman make your move..." << std::endl;
            
            bool isValid = false;
            do {
                auto move = getPlayerMove(board);
                int x = std::get<0>(move);
                int y = std::get<1>(move);
                int z = std::get<2>(move);
                int t = std::get<3>(move);
                isValid = makeMove(board, x, y, z, t, currentPlayer); // Returns true if valid, false otherwise
                    if (!isValid) {
                        std::cout << "Invalid human move. Please try again." << std::endl;
                    }
                } while (!isValid); // Loop again if the result is false       
        }
        else if(computerPlayerMode && currentPlayer=='O') {
            std::cout << "\nComputer's turn..." << std::endl;
             bool isValid = false;
            do {
            int x = rand() % 3;
            int y = rand() % 3;
            int z = rand() % 3;
            int t = rand() % 3;
             isValid = makeMove(board, x, y, z, t, currentPlayer); // Returns true if valid, false otherwise
                    if (!isValid) {
                        std::cout << "Invalid computer move. Please try again." << std::endl;
                    }
                } while (!isValid); // Loop again if the result is false  
            }
        else { //Full Computer mode. Computer playing the computer.
            std::cout << "\nComputer's turn..." << std::endl;
             bool isValid = false;
            do {
            int x = rand() % 3;
            int y = rand() % 3;
            int z = rand() % 3;
            int t = rand() % 3;
             isValid = makeMove(board, x, y, z, t, currentPlayer); // Returns true if valid, false otherwise
                    if (!isValid) {
                        std::cout << "Invalid computer move. Please try again." << std::endl;
                    }
                } while (!isValid); // Loop again if the result is false  
            }    
                
         // Check if current player has won
        if (checkWin(board, currentPlayer,winBoard)) {
            printBoard(board,winBoard);
            if (computerPlayerMode && currentPlayer =='X') {std::cout << "\nHuman player '" << currentPlayer << "' wins!" << std::endl;}
            else if (computerPlayerMode && currentPlayer =='O') {std::cout << "\nComputer player '" << currentPlayer << "' wins!" << std::endl;}
            else{std::cout << "\n" << currentPlayer << " wins!" << std::endl;}
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    
    return 0;
}
