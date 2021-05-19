#include "sudoku.h"


void validate_number(string str){
  for(int i = 0; i < str.size(); i++){
    if(!(isdigit(str[i]))){
      throw 0;
    }
  }
}


void validate_range(int number){
  if(number <= 0 || number >= 10){
    throw 0;
  }
}





sudoku::sudoku(){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            grid[i][j] = 0;
        }
    }
}


void sudoku::enterDigits(){
  for (int i = 0; i < size; i++){
    cout << "\nEnter " << i + 1 << " row numbers: " << std::endl;
    for (int j = 0; j < size; j++){
      string str;
      cin >> str;
      validate_number(str);
      
      int number = stoi(str);
      validate_range(number);
      
      grid[i][j] = number;
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

    int x1 = int(x / 3) * 3;
    int y1 = int(y / 3) * 3;

    for (int i = 0; i < 3; i++){
      for (int j = 0; j < 3; j++){
        if (grid[y1 + i][x1 + j] == number){
                return false;
        }
      }
    }
    return true;
}


void sudoku::solve(){
  for (int y = 1; y < size+1; y++){
    for (int x = 1; x < size+1; x++){
      if (grid[y][x] == 0){
        for (int n = 1; n < size+1; n++){
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
}


void sudoku::print(){
    cout << "\n";
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}
