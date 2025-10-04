# csc-155-group-project
CSC 155 Group Project


CSC155 Group Project Options

This document outlines the pros and cons of our potential project choices, evaluated against the CSC155 course goals. We want to demonstrate mastery of:

Input/Output (cin, cout)

Control structures (loops, decisions)

Arrays and Vectors

Sorting and Searching

Classes with constructors, overloads, and encapsulation (public/private)

Inheritance and Polymorphism

Exception Handling and Robustness


1. Grade Manager

Description: An application that tracks students, assignments, and grades. Provides averages, sorting by score, and searching by name or ID.

Pros:

Natural fit for arrays/vectors (storing student or grade records).

Strong use case for searching (find student by ID) and sorting (rank by average).

Easy to design multiple classes (e.g., Student, Course, GradeManager).

Can demonstrate inheritance (e.g., UndergraduateStudent vs. GraduateStudent).

Exception handling for invalid grade input.

Realistic, “practical” application.

Cons:

Data model can get complex (handling multiple students, multiple assignments).

Requires careful planning to avoid overwhelming scope.

User interface (text menus) may get repetitive if not well structured.


2. Quiz Application

Description: A program that lets instructors create quizzes and students take them, tracking scores and results.

Pros:

Clear I/O opportunities (questions in, answers out).

Arrays/vectors for storing questions and responses.

Polymorphism possible (different question types: multiple choice, true/false).

Searching/sorting to review high scores or quiz banks.

Natural use of exception handling for invalid input.

Cons:

Requires designing a question bank system — could be challenging.

May overlap heavily with Grade Manager concept (tracking scores).

Needs extra thought to avoid being “too simple” (just Q&A without added features).


3. Contact List Manager

Description: A program to add, search, edit, and remove contacts (like a simplified phonebook).

Pros:

Direct fit for arrays/vectors (list of contacts).

Sorting/searching by name, number, or email is very natural.

Classes with encapsulation (Contact with private attributes).

Can implement file input/output for persistence.

Robust exception handling opportunities (duplicate entries, invalid phone numbers).

Cons:

Might feel less “exciting” than games or academic tools.

Inheritance/polymorphism may feel a little forced unless extended (e.g., PersonalContact, BusinessContact).

Simpler overall scope, which could be a strength or weakness.


4. Tic-Tac-Toe Game

Description: A console-based game for two players (or vs. computer AI).

Pros:

Fun and visual, engages interest.

Uses arrays/vectors for the game board.

Opportunity for classes (Board, Player, Game).

Can extend with AI (introduces search algorithms).

Exception handling for invalid moves.

Cons:

Sorting/searching less relevant (unless adding a scoreboard).

Inheritance/polymorphism less natural unless extended (e.g., HumanPlayer vs. ComputerPlayer).

Risk of being “too small” unless extra features are added (save/load, multiple game modes, tournament mode).

Recommendation Summary

Grade Manager → Best for showcasing data handling, sorting/searching, and OOP structure. Strong academic feel.

Quiz Application → Good balance of OOP and user interaction, with potential for polymorphism in question types.

Contact List Manager → Cleanest demonstration of encapsulation and searching/sorting. Practical, but simpler scope.

Tic-Tac-Toe → Most engaging, but needs creative extensions to cover sorting/searching and polymorphism.
