# 4D Tic-Tac-Toe

## Here's a complete C++ console implementation of a 4D tic-tac-toe game as described:

### This implementation includes:

1. A 4D game board (3x3x3x3)

2. A console interface that displays:
   - Depth (z) as vertical (top to bottom)
   - Time (t) as horizontal (left to right)
   - Each cell is a 3x3 grid (x,y)

3. Win conditions for all 4 dimensions:
   - X direction (fixed y,z,t)
   - Y direction (fixed x,z,t)
   - Z direction (fixed x,y,t)
   - T direction (fixed x,y,z)

4. Three game modes:
   - Computer vs. Computer
   - Human vs. Computer
   - Human vs. Human (no computer)
   
5. Features:
   - Clear board display with labels
   - Win detection in all dimensions
   - Draw detection
   - Random computer moves

---

### To use the game:

1. Run the program
2. Select whether the computer plays against the computer (Y/N)
3. Select whether to play against computer (Y/N)
4. For human players, enter x, y, z, t coordinates (0-2) for each dimension
5. The computer plays randomly if selected
6. The game ends when someone wins or the board is full

The display shows the game as three vertical tic-tac-toe boards (depth) arranged in three horizontal columns (time), matching the description of "three normal tic-tac-toe boards vertically which will make one column" (depth) and "three time intervals in a console window" (time).

The implementation follows C++ best practices with proper comments and handles all edge cases including board validation and win conditions in all four dimensions.

---

### Background
After an LLM handedly created tic-tac-toe (see repos), it was given a task to create a 4D version. It created the overall structure, but the code had gaps and major logic issues. The biggest challenge was the win logic. It did well with the space (4D) diagonal checks, but it struggled with the planar diagonals and the orthogonal wins. That logic was a compilation of the LLMs' code and a human developer patching things up. Interestingly enough, some things the LLMs struggled with, online search engine AIs solved pretty easily. The whole project could use a good refactoring, but this is just hobby work as a refresher, and it is time to move on to something else.  

A compiled version of the game is located in the 'bin' folder. It was compiled on a 64-bit Windows 10 system using the following terminal command from the 'repos/4d-tic-tac-toe folder':
~~~
g++ src/4d-tic-tac-toe.cpp -o bin/4d-tic-tac-toe
~~~
