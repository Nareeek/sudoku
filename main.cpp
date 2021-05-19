#include "sudoku.h"

int main()
{
  try{
    sudoku s;

    cout << "Let's start typing Sudoku numbers (1-9), (0-if empty):\n\n";
    s.enterDigits();

    cout << "\nbefore solving the problem \n";
    s.print();
    
    cout << "\n\nafter solving the problem \n";
    
    // TODO is valid sudoku
    s.solve();
    s.print();
  }
  catch(const int& e){
    cout << "\nERROR\n";
  
  }

    return 0;
}
