# Passer Eater Game

## Overview

The Eater Game is a two-player game played on a square grid. Players take turns placing their markers ('P' for Passer and 'E' for Eater) on unoccupied cells. If both players choose the same cell, the Eater's marker takes precedence.

The Passer's objective is to create a connected path of their markers from the top row to the bottom row. This path can move downwards, left, right, diagonally down-left, or diagonally down-right, but cannot move upwards.

The Eater wins if the Passer fails to create a connected path and the board becomes full.

This implementation offers several game modes:

* **Single Player:** Play against a computer opponent (either as Passer or Eater).
* **Multi Player:** Two human players compete against each other.
* **Straight-line Player vs Random Player:** One player places markers in a straight line (either Passer or Eater), while the other player places markers randomly.

## How to Compile and Run

1.  **Save:** Save the provided C code as a `.c` file (e.g., `eater_game.c`).
2.  **Compile:** Open a terminal or command prompt and use a C compiler (like GCC) to compile the code:
    ```bash
    gcc main.c -o eater_game
    ```
3.  **Run:** Execute the compiled program:
    ```bash
    ./eater_game
    ```

## Game Controls

* The game will prompt you to select a game mode from the main menu. Enter the corresponding number.
* For player turns, you will be asked to enter the vertical and horizontal indices of the cell where you want to place your marker. The board indices start from 1.

## Game Modes

1.  **Single Player:**
    * You will be asked to choose your role: Passer or Eater.
    * The computer opponent will make random moves.

2.  **Multi Player:**
    * Two players take turns entering their moves.

3.  **Straight-line Player vs Random Player:**
    * You will choose the role (Passer or Eater) for the straight-line player.
    * The straight-line player will place their first available marker from left to right, top to bottom.
    * The random player (computer) will place their markers in random unoccupied cells.

4.  **View Game Rules:**
    * Displays the rules of the Eater Game. Press Enter to return to the main menu.

## Code Structure

* **`checkWin(char board[n][n])`:** This function checks if the Passer has won the game by detecting a connected path of 'P' markers from the top to the bottom of the board. It also includes a check for the Eater winning condition (board full without a Passer win), although this logic might need refinement.
* **`showBoard(char board[n][n])`:** Displays the current state of the game board in the console.
* **`boardSize(int n)`:** Prompts the user to enter the desired size of the game board (between 3 and 20) and returns the size incremented by 1 to accommodate the index labels.
* **`passerTurn(char board[n][n])`:** Prompts the Passer player to enter the coordinates for their move and places 'P' on the board if the cell is valid and unoccupied.
* **`eaterTurn(char board[n][n])`:** Prompts the Eater player to enter the coordinates for their move and places 'E' on the board if the cell is valid and either unoccupied or occupied by 'P'.
* **`randomEater(char board[n][n])`:** Places the Eater's marker 'E' in a random unoccupied cell.
* **`randomPasser(char board[n][n])`:** Places the Passer's marker 'P' in a random unoccupied cell.
* **`linePasser(char board[n][n])`:** Places the Passer's marker 'P' in the first available unoccupied cell encountered by iterating through the board row by row.
* **`lineEater(char board[n][n])`:** Places the Eater's marker 'E' in the first available cell (either '-' or 'P') encountered by iterating through the board row by row.
* **`main()`:** The main function that handles game initialization, menu navigation, game loop for different modes, and win condition checking.

## Notes

* The win-checking logic in `checkWin()` might need further review and refinement to ensure it correctly identifies all winning conditions for the Passer and the Eater.
* The game continues until the board is full in the multi-player and single-player modes. A more explicit check for a draw condition (board full without a Passer win) could be added.
* The random player logic makes purely random moves without any strategy.
* The board indexing starts from 1 as presented to the user, but the underlying array is 0-indexed. The code handles this conversion.
