#pragma once

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::stoi;
using std::endl;
using std::vector;

class sudoku {
  public:
    sudoku();

    void enterDigits();
    bool is_possible_number(int y, int x, int number);
    void solve();
    const static int size = 9;
    void print();
    int grid[9][9];
    bool is_valid_sudoku_input(int grid[][size], int size);
};
