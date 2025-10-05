# CSC155 Group Project Options

This document outlines the pros and cons of our potential project choices, evaluated against the **CSC155 course goals**. We want to demonstrate mastery of:

- Input/Output (`cin`, `cout`)
- Control structures (loops, decisions)
- Arrays and Vectors
- Sorting and Searching
- Classes with constructors, overloads, and encapsulation (`public`/`private`)
- Inheritance and Polymorphism
- Exception Handling and Robustness
- File I/O (reading and writing data)

---

## 1. Student Grade Manager
**Description:** Reads grades from a file, calculates averages, applies letter grades, and writes results to a new file.

**Pros:**
- Strong use of **file I/O** (reading input, writing results).
- Great opportunity for **arrays/vectors** to store student scores.
- Natural place for **searching and sorting** (e.g., sort by average, search by student).
- Classes can represent `Student` and `GradeManager`.
- Exception handling for bad data (non-numeric input, missing files).
- Practical and academic application.

**Cons:**
- Heavy focus on file processing might overshadow gameplay-style creativity.
- Inheritance/polymorphism needs to be designed carefully (e.g., different student types).
- Can become complex if too many features are added.

---

## 2. Tic-Tac-Toe Game
**Description:** A 2-player console game using arrays, win detection logic, and replay option.

**Pros:**
- Fun and interactive.
- Uses **arrays** to represent the game board.
- Opportunity for **classes** like `Board`, `Player`, and `Game`.
- Exception handling for invalid moves (e.g., overwriting a taken square).
- Replay option shows control structures and looping.

**Cons:**
- **Sorting/searching** less relevant (unless extended with leaderboard/score history).
- Inheritance/polymorphism is not obvious (unless extended with `HumanPlayer` vs. `AIPlayer`).
- Risk of being too small unless additional features (AI, tournament mode, saving scores) are added.

---

## 3. Contact List Manager
**Description:** Stores, searches, and sorts contacts with file I/O for persistent storage.

**Pros:**
- Strong use of **arrays/vectors** for managing contacts.
- Natural application of **searching and sorting** (by name, phone, or email).
- File I/O for persistence (save/load contact lists).
- Classes with encapsulation (`Contact` class with private data).
- Exception handling for duplicate entries or invalid formats.

**Cons:**
- Could feel less engaging compared to a game.
- Inheritance/polymorphism may need extensions (e.g., `BusinessContact` vs. `PersonalContact`).
- Simpler scope than Grade Manager or Quiz Application.

---

## 4. Quiz Application
**Description:** Randomly selects and displays multiple-choice questions, tracks score, and saves results.

**Pros:**
- Strong use of **I/O** (input for answers, output for results).
- Uses **arrays/vectors** for questions and answers.
- Opportunity for **classes** like `Question`, `Quiz`, `Result`.
- Polymorphism possible with different question types (`TrueFalseQuestion`, `MultipleChoiceQuestion`).
- Exception handling for invalid input (e.g., selecting an option that doesn’t exist).
- File I/O for saving quiz results.

**Cons:**
- Requires designing a **question bank system** (random selection logic).
- Similar in concept to Grade Manager (tracking performance data).
- Needs extra thought to scale beyond just a basic Q&A loop.

---

## Recommendation Summary
- **Student Grade Manager** → Best fit for *file I/O, sorting/searching, and academic structure*.  
- **Tic-Tac-Toe** → Most engaging, but requires feature extensions for full CSC155 coverage.  
- **Contact List Manager** → Clean, practical, strong fit for *encapsulation and file I/O*, but lighter on polymorphism.  
- **Quiz Application** → Balanced option with *OOP, polymorphism, and file I/O*, but needs careful question bank design.  

---

If our goal is **robustness + coverage of all CSC155 concepts**, the **Student Grade Manager** or **Quiz Application** will likely give us the richest opportunities.  


# Tic-Tac-Toe: Game Rules and Logic Overview

## Objective
Tic-Tac-Toe is a 2-player, turn-based game played on a **3×3 grid**.  
Players take turns marking empty squares with their symbol — either **X** or **O**.  
The goal is to be the **first to get three of your symbols in a row** (horizontally, vertically, or diagonally).

---

## Game Rules

1. **Board Setup**
   - The game board is a 3×3 grid.
   - Each cell can be empty, contain an `X`, or contain an `O`.
   - In C++, this can be stored using:
     - A 2D array: `char board[3][3];`
     - Or a vector: `vector<vector<char>> board(3, vector<char>(3, ' '));`

2. **Player Turns**
   - There are two players: **Player 1 (X)** and **Player 2 (O)**.
   - By convention, **Player 1 (X)** always goes first.
   - Players alternate turns, each choosing one empty cell to mark with their symbol.
   - Input can be taken as row/column numbers (e.g., row 1, column 2).

3. **Move Validation**
   - A player cannot place a symbol on an already occupied space.
   - Invalid inputs should trigger **error messages** and a chance to re-enter.
   - This is a good spot to demonstrate **exception handling**.

4. **Winning Conditions**
   A player wins if they have **three of their symbols in a row** in any of these patterns:
   - **Rows:** all symbols in a row are the same.
     - `(0,0), (0,1), (0,2)` or `(1,0), (1,1), (1,2)` or `(2,0), (2,1), (2,2)`
   - **Columns:** all symbols in a column are the same.
     - `(0,0), (1,0), (2,0)` or `(0,1), (1,1), (2,1)` or `(0,2), (1,2), (2,2)`
   - **Diagonals:** all symbols match on either diagonal.
     - `(0,0), (1,1), (2,2)` or `(0,2), (1,1), (2,0)`

   After every turn, check these conditions to determine if a player has won.

5. **Tie (Draw) Conditions**
   - If all nine cells are filled and **no winning condition** is met, the game ends in a **tie**.
   - You can check for a tie after verifying no winner and counting filled spaces.

6. **Game End**
   - Once a winner or tie is detected, display a message like:
     - `"Player X wins!"`
     - `"Player O wins!"`
     - `"It’s a tie!"`
   - Then offer the **replay option**.

---

## 🔁 Replay Option
After the end of each game:

1. Ask the user:  
   `"Would you like to play again? (Y/N): "`
2. If the answer is `Y` or `y`:
   - Clear and reinitialize the board.
   - Switch which player starts (optional feature).
   - Begin a new game loop.
3. If the answer is `N` or `n`:
   - Exit the program gracefully with a thank-you message.

---

## ⚙️ Suggested Program Flow (Pseudocode)

```cpp
initializeBoard();

do {
    currentPlayer = 'X';
    while (!gameOver) {
        displayBoard();
        getPlayerMove(currentPlayer);
        updateBoard(currentPlayer);
        checkWinnerOrTie();
        switchPlayer();
    }

    displayResult();
    askReplay();

} while (userWantsReplay);
```

# Tic Tac Toe – Improvement Overview

This document outlines planned improvements and design enhancements for the CSC 155 Tic Tac Toe Project.  
The current implementation is functional and object-oriented but can be expanded for better usability, smarter logic, and clearer structure.

---

##  Overview of Improvement Areas

###  User Interface Enhancements (Usability & Presentation)

**CSC 155 Principles:** Input validation, output formatting, and user experience.

**Goals**
- Improve the console interface for a smoother gameplay experience.
- Provide clearer prompts and more intuitive board visualization.
- Reduce clutter and repetitive messages.

**Ideas**
- **Colorized Output:** Use ANSI escape codes to color X’s and O’s (e.g., X = red, O = blue).
- **Dynamic Refresh:** Clear the screen each turn using `system("clear")` (Linux/macOS) or `system("CLS")` (Windows).
- **Better Prompts:** Clearly display player names, symbols, and whose turn it is.
- **Status Line:** Show the current score (wins, losses, draws) after each round.
- **Flexible Input:** Accept moves as either `"1 2"` or `"A3"`, handling both formats gracefully.

---

### Smarter Draw Detection (Game Logic Enhancement)

**CSC 155 Principles:** Algorithm design, logical reasoning, and conditional structures.

The current implementation declares a draw only when the board is full.  
The goal is to enhance the logic so the game can detect when no remaining moves can lead to a win for either player (a strategic draw).

**Conceptual Steps**
1. For every empty cell:
   - Temporarily place an `'X'` and check if it would result in a win.
   - Temporarily place an `'O'` and check if it would result in a win.
   - Restore the cell.
2. If no possible winning paths remain, declare a draw.

**Example Implementation**
```cpp
bool isForcedDraw() const {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ') {
                board[i][j] = 'X';
                if (isWin('X')) { board[i][j] = ' '; return false; }
                board[i][j] = 'O';
                if (isWin('O')) { board[i][j] = ' '; return false; }
                board[i][j] = ' ';
            }
    return true;
}

```
#Integration 

```cpp
if (board.isForcedDraw()) {
    cout << "No possible winning paths remain — it's a strategic draw!\n";
    draws++;
    gameOver = true;
}
```

---

# Object-Oriented Refinements

#CSC 155 Principles: Encapsulation, abstraction, and class design.

# Proposed Improvements

-Separate UI from Logic: Move input/output to a dedicated GameUI class.
-Encapsulate Stats: Use a Scoreboard class to manage wins, losses, and draws cleanly.

---

# Error Handling and Input Validation

CSC 155 Principles: Exception handling and robust user interaction.

Goals

-Improve feedback for invalid coordinates and occupied cells.
-Handle unexpected inputs gracefully with try/catch blocks and clear messages.
