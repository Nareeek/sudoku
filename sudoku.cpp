#include <iostream>
#include "sudoku.h"


sudoku::sudoku(){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            grid[i][j] = 0;
        }
    }
}


void sudoku::enterDigits(){
  bool is_correct_row = true;
  bool is_valid_number = true;
    for (int i = 0; i < size; ){
      std::cout << "Enter " << i + 1 << " row numbers: " << std::endl;
      for (int j = 0; j < size; j++){
        std::cin >> grid[i][j];

        // TODO - check when multiple times typing incorrect row
        if (!(grid[i][j] >= 0 && grid[i][j] <= size) && is_valid_number){
          is_valid_number = false;
          is_correct_row = false;
          std::cout << "\nInvalid value(s), try again " << i + 1 << "-row\n";
      } 
    }
    if (is_correct_row){
      i++;
      std::cout << std::endl;
    }
    else{
      is_correct_row = true;
      continue;
      
    }
    
  }
}



bool sudoku::is_possible_number(int y, int x, int number){
  for (int i = 0; i < size; i++){
    if (grid[y][i] == number){
      return false;
    }
  }

  for (int i = 0; i < size; i++){
    if (grid[i][x] == number){
      return false;
    }
  }

    int x0 = int(x / 3) * 3;
    int y0 = int(y / 3) * 3;

    for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
        if (grid[y0 + i][x0 + j] == number){
                return false;
        }
      }
    }
    return true;
}


void sudoku::solve(){
  for (int y = 0; y < size; y++){
    for (int x = 0; x < size; x++){
      if (grid[y][x] == 0){
        for (int n = 1; n < size + 1; n++){
          if (is_possible_number(y, x, n)){
            grid[y][x] = n;
            solve();
            grid[y][x] = 0;
          }
        }
        return;
      }
    }
  }
  print();
}


void sudoku::print(){
    std::cout << "\n";
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}
