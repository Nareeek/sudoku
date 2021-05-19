#pragma once

#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::stoi;
using std::endl;

class sudoku {
  public:
    sudoku();

    void enterDigits();
    bool is_possible_number(int y, int x, int number);
    void solve();
    const int size = 9;
    void print();
    int grid[9][9];
    // TODO - is_valid_sudoku();
};
