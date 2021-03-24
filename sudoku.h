#pragma once

class sudoku {
  public:
    sudoku();

    void enterDigits();
    bool is_possible_number(int y, int x, int number);
    void solve();
    void print();
    int grid[9][9];
    // TODO - is_valid_sudoku();
};
