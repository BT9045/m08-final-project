# Module 8A: Final Project

## Author
Belay Tekle-wold

## Date
October 18, 2026

## Course
Computer Science 1

## Project Description
This program reads a data file containing (x-coordinate, character,
y-coordinate) triplets, determines the maximum x and y values, creates a
2D grid initialized with spaces, places each character at its specified
coordinate, and prints the grid to reveal a picture made of block-annotated
letters.

The character column contains either a full block (█) or a light shade (░).
The full block is drawn as '#' in the output, and the light shade as '.'.

## Files Included
- main.cpp — The C++ source code
- Input.txt — The input data file
- README.md — This file
- flowchart.png — Flowchart of the program logic
- uml.png — UML diagram of the program structure
- screenshot.png — Screenshot of the program output

## How to Run
1. Compile: g++ main.cpp -o finalproject
2. Make sure Input.txt is in the same folder as the executable.
3. Run: ./finalproject (Mac/Linux) or finalproject.exe (Windows)

For online compilers (e.g., OnlineGDB), upload Input.txt as a program file
alongside the source code.

## Algorithm
1. Open Input.txt.
2. Read each line, parsing x-coordinate, character, and y-coordinate.
3. Track the maximum x and y values across all data points.
4. Create a 2D grid of size (maxY+1) rows x (maxX+1) columns, filled
   with spaces.
5. Place each character at position [y][x] in the grid.
6. Print the grid row by row from top to bottom to reveal the hidden
   picture.

## Sample Output
See `screenshot.png` for the full program output, which shows:
- Maximum x: 89
- Maximum y: 6
- Total data points: 332

## Output Note
The program reads all 332 data points from Input.txt and prints
the block-letter picture. The letters spelled out are:
E I C W D K O

## Lessons Learned
- How to read and parse a data file in C++ using ifstream and istringstream
- How to dynamically size a 2D grid based on the maximum x and y values
- How coordinate data maps to a grid using grid[y][x]
- How character encoding (UTF-8 vs. Windows-1252) can affect file reading
- The importance of matching filenames exactly between code and disk