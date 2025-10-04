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

✅ If our goal is **robustness + coverage of all CSC155 concepts**, the **Student Grade Manager** or **Quiz Application** will likely give us the richest opportunities.  
