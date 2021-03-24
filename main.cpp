#include <iostream>
#include "sudoku.h"

int main()
{
    sudoku s;

    std::cout << "Let's start typing Sudoku numbers (1-9), (0-if empty):\n\n";
    s.enterDigits();

    std::cout << "\nbefore solving the problem \n";
    s.print();
    
    std::cout << "\n\nafter solving the problem \n";
    
    // TODO is valid sudoku
    s.solve();

    return 0;
}
