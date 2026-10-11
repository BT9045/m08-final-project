/*
 * Name: Belay Tekle-wold
 * Date: October 18, 2026
 * Module 8A: Final Project
 *
 * Purpose:
 * Read coordinate data from Input.txt.
 * Determine the maximum x and y coordinates.
 * Create a 2D grid initialized with spaces.
 * Fill the grid with characters from the input file.
 * Print the grid to reveal the hidden block letters.
 *
 * Input format:
 * x <tab> character <tab> y
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Store each coordinate and its character.
struct Pixel {
    int x;
    int y;
    char ch;
};

int main() {

    // ---- Open the input file ----
    vector<Pixel> pixels;
    ifstream file("Input.txt");

    if (!file.is_open()) {
        // Try the Code::Blocks Debug directory layout.
        file.clear();
        file.open("..\\..\\Input.txt");
    }

    if (!file.is_open()) {
        cerr << "ERROR: Could not open Input.txt." << endl;
        cerr << "Place Input.txt in the program's working directory."
             << endl;
        cerr << "For an online compiler, upload Input.txt as a program file."
             << endl;
        return 1;
    }

    string line;
    int maxX = -1;
    int maxY = -1;

    // ---- Read and parse the input data ----
    while (getline(file, line)) {

        if (line.empty()) {
            continue;
        }

        istringstream iss(line);

        int x, y;
        string chStr;

        // Read x, character, and y from each line.
        if (!(iss >> x >> chStr >> y)) {
            continue;
        }

        // Convert the input characters for display.
        char ch;

        if (chStr == "█") {
            ch = '#';
        }
        else if (chStr == "░") {
            ch = '.';
        }
        else {
            ch = chStr[0];
        }

        // Store the coordinate and character.
        pixels.push_back({x, y, ch});

        if (x > maxX) {
            maxX = x;
        }

        if (y > maxY) {
            maxY = y;
        }
    }

    file.close();

    // ---- Check whether valid data was read ----
    if (pixels.empty()) {
        cerr << "ERROR: No valid data was read from Input.txt."
             << endl;
        return 1;
    }

    // ---- Display the results ----
    cout << "Maximum x: " << maxX << endl;
    cout << "Maximum y: " << maxY << endl;
    cout << "Total data points: " << pixels.size() << endl;
    cout << endl;

    // ---- Create the 2D grid ----
    int rows = maxY + 1;
    int cols = maxX + 1;

    // Initialize every position with a space.
    vector<vector<char> > grid(
        rows, vector<char>(cols, ' ')
    );

    // ---- Fill the grid with the input characters ----
    for (size_t i = 0; i < pixels.size(); i++) {

        Pixel p = pixels[i];

        if (p.x >= 0 && p.x < cols &&
            p.y >= 0 && p.y < rows) {

            grid[p.y][p.x] = p.ch;
        }
    }

    // ---- Print the hidden block-letter answer ----
    cout << "Hidden block-letter answer:" << endl << endl;

    for (int r = rows - 1; r >= 0; r--) {

        for (int c = 0; c < cols; c++) {
            cout << grid[r][c];
        }

        cout << endl;
    }

    return 0;
}
