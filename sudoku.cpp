#include "sudoku.h"



sudoku::sudoku(){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            grid[i][j] = 0;
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




void validate_number(string str){
  for(int i = 0; i < str.size(); i++){
    if(!(isdigit(str[i]))){
      throw 0;
    }
  }
}




void validate_range(int number){
  if(number < 0 || number >= 10){
    throw 0;
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




bool sudoku::is_valid_sudoku_input(int grid[][9], int n){
    // checking the uniqueness of row numbers
    for(int i = 0; i < n; i++) {
        vector<bool> v(n, false);
        for(int j = 0;j < n; j++) {
            if (grid[i][j] != 0) {
                int index = grid[i][j];
                if (v[index]) {
		    cout << "\nSame row numbrs!";
                    return false;
                } 
                v[index] = true;
            }
        }
    }
    
    // checking the uniqueness of column numbers
    for(int j = 0; j < n; j++) {
        vector<bool> v(n, false);
        for(int i = 0; i < n; i++) {
            if (grid[i][j] != 0) {
                int index = grid[i][j];
                if (v[index]) {
		    cout << "\nSame column numbers!";
                    return false;
                } 
                v[index] = true;
            }
        }
    }
    
    // checking the uniqueness of 3x3 grid numbers
    for(int k = 0; k < n; k++) {
        int r = (k / 3) * 3;
        int c = (k % 3) * 3;
        vector<int> v = {
            grid[r][c], grid[r][c+1], grid[r][c+2],
            grid[r+1][c], grid[r+1][c+1], grid[r+1][c+2],
            grid[r+2][c], grid[r+2][c+1], grid[r+2][c+2]  };
        
        vector<bool> vb(n, false);
       
        for(int i = 0; i < n; i++) {
            if(v[i]!= 0) {
                int index = v[i];
                if(vb[index]){
		    cout << "\nSame 3x3 grid numbers!";    
		    return false;
		}
                vb[index] = true;
            }
        }        
    }
    return true;
}




void sudoku::solve(){
  static int counter = 0;

  for (int y = 0; y < size; y++){
    for (int x = 0; x < size; x++){
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

  if(counter > 3){
    cout << "\nMultiple solutions: " << counter;
      throw 0;
    }

  counter++;
  print();
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

