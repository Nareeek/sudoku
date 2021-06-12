#include "sudoku.h"
#include "gtest/gtest.h"

namespace {
	
// Tests sudoku: checking valid custom inputs - for valid solution(s).
TEST(SudokuTest, Normal_case) {
  const int size = 9;

  int arr[9][9] = {{0,0,0,0,0,1,3,0,0},
	  	   {7,6,0,4,0,0,1,0,0},
		   {0,0,5,0,7,0,0,6,0},
		   {6,0,0,0,0,0,0,3,0},
		   {0,0,0,0,0,7,0,4,9},
		   {5,0,0,0,1,0,0,0,0},
		   {0,0,0,0,3,2,0,0,0},
		   {0,9,0,0,0,0,0,0,8},
		   {0,8,4,0,0,0,0,0,0}};
   
  int solution[size][size] = {   {9,2,8,5,6,1,3,7,4},
	  			 {7,6,3,4,2,9,1,8,5},
				 {4,1,5,3,7,8,9,6,2},
				 {6,7,2,9,8,4,5,3,1},
				 {8,3,1,2,5,7,6,4,9},
				 {5,4,9,6,1,3,8,2,7},
				 {1,5,7,8,3,2,4,9,6},
				 {3,9,6,7,4,5,2,1,8},
				 {2,8,4,1,9,6,7,5,3}};

  bool is_correct = true;
  sudoku ss(arr);
  ss.solve();

  for(int i = 0; i < size; ++i){
    for(int j = 0; j < size; ++j){
      if(ss.result[i][j] != solution[i][j]){
	is_correct = false;
	break;
      }
    } 
    if(!is_correct){
      break;
    }
  }
  EXPECT_TRUE(is_correct);
}


// Tests sudoku: checking invalid custom input(repetitive numbers) - for invalid output.
TEST(SudokuTest, Repetitive_case) {
  bool is_error = false;
  const int size = 9;

  int arr[size][size] = { {7,0,0,0,0,1,3,0,0},
			  {7,6,0,4,0,0,1,0,0},
			  {0,0,5,0,7,0,0,6,0},
			  {6,5,0,0,0,0,0,3,0},
			  {0,0,0,0,0,7,7,4,9},
			  {5,0,0,0,1,0,0,0,0},
			  {0,0,0,3,3,2,0,0,0},
			  {0,9,0,0,0,0,0,0,8},
			  {0,8,4,0,0,0,0,0,0}};
 
  sudoku ss(arr);
  if(ss.is_valid_sudoku_input(ss.grid, size) == false){
      is_error = true;
  }

  EXPECT_TRUE(is_error);
}



// Tests sudoku: checking invalid custom input(out of range) numbers - for invalid output.
TEST(SudokuTest, Out_of_range_case) {
  const int size = 9;

  int arr[size][size] = {{7,0,0,0,0,1,3,0,0},
		  	 {7,6,0,4,10,0,1,0,0},
			 {0,0,5,0,70,0,0,6,0},
			 {6,5,0,0,0,0,0,3,0},
			 {0,0,0,0,0,7,7,4,9},
			 {5,0,0,0,1,0,0,0,0},
			 {0,0,0,3,3,20,0,60,0},
			 {0,9,0,0,0,0,0,0,8},
			 {0,8,4,0,0,0,0,0,0}};
 
  bool is_error = false;
  try{
    for(int i = 0; i < size; ++i){
      for(int j = 0; j < size; ++j){
        validate_range(arr[i][j]);
      }
    }
  } catch(...){
      is_error = true;
  }

  EXPECT_TRUE(is_error);
}



// Tests sudoku: checking invalid custom inputs(not a numbers) - for invalid output.
TEST(SudokuTest, Not_a_number_case) {
  const int size = 9;

  string arr[size][size] = {{"aa","aa","aa","aa","aa","aa","aa","aa","aa"},
			    {"bb","bb","bb","bb","bb","bb","bb","bb","bb"},
			    {"cc","cc","cc","cc","cc","cc","cc","cc","cc"},
			    {"dd","dd","dd","dd","dd","dd","dd","dd","dd"},
			    {"ee","ee","ee","ee","ee","ee","ee","ee","ee"},
			    {"ff","ff","ff","ff","ff","ff","ff","ff","ff"},
			    {"gg","gg","gg","gg","gg","gg","gg","gg","gg"},
			    {"hh","hh","hh","hh","hh","hh","hh","hh","hh"},
			    {"ii","ii","ii","ii","ii","ii","ii","ii","ii"}};
  
  
  bool is_error = false;
  try{
    for(int i = 0; i < size; ++i){
      for(int j = 0; j < size; ++j){
        validate_number(arr[i][j]);
      }
    }
  } catch(...){
      is_error = true;
  }

  EXPECT_TRUE(is_error);
}


} // namespace



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

