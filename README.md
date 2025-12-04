# Rock Paper Scissors - Raylib C++ Edition

## Overview
This project is a **Rock Paper Scissors** game implemented in C++ using the **Raylib** graphics library. The game allows a player to compete against a computer opponent in a visually interactive environment. The game includes animations for each move (rock, paper, scissors) and displays the winner of each round.

---

## Basic Logic
1. **Game Initialization**:
   - The game initializes a window using Raylib with a resolution of `800x600` and sets the target frame rate to `60 FPS`.

2. **Player Input**:
   - The player is prompted to enter their move (`rock`, `paper`, or `scissors`) via the console.
   - The input is validated, and the corresponding move is set.

3. **Computer Move**:
   - The computer generates a random move (`rock`, `paper`, or `scissors`).

4. **Countdown**:
   - A countdown is displayed on the screen before the moves are revealed.

5. **Move Animations**:
   - Animations for the player's and computer's moves are displayed on the screen.

6. **Winner Determination**:
   - The game logic determines the winner based on the rules of Rock Paper Scissors:
     - Rock beats Scissors.
     - Scissors beats Paper.
     - Paper beats Rock.
   - The winner is displayed on the screen.

7. **Replay Option**:
   - After the round ends, the player is asked if they want to play again.

---

## How to Initialize and Run the Game

### Prerequisites
- **C++ Compiler**: Ensure you have a C++ compiler installed (e.g., `g++`).
- **CMake**: Required to build the project.
- **Raylib**: The Raylib library must be installed on your system.

### Steps to Run
1. **Clone the Repository**:
   ```bash
   git clone <repository-url>
   cd RockPaperScissor
2. **Build the Project**:
  - Create a build directory:
    ```bash
    mkdir build
    cd build
  - Run CMake to configure the project:
    ```bash
    cmake ..
  - Build the project:
    ```bash
    make
3. **Run the Game**:
  - After building, run the executable:
     ```bash
     ./mainApp
4. **Play the Game**:
  -Follow the on-screen instructions to play the game.

## Key Features:
- **Interactive Animations**: 
  - Animations for each move (rock, paper, scissors).
- **Countdown Timer**:
  - A countdown before moves are revealed.
- **Winner Announcement**:
  - Displays the winner of each round.
- **Replay Option**:
  - Allows the player to play multiple rounds.
 
## Notes:
- Ensure the ``assets`` folder is copied to the build directory during the build process (handled by CMake).
- The game uses the console for player input and the Raylib window for graphical output.
