#include <iostream>
#include <string>
#include <fstream>
#include "cl_sudoku.h"
#include <ctime>

int main()
{
  using namespace std;
  cout << endl;
  Sudoku sudoku1(9,3,"board.txt");

  cout << "Original Board to solve: " << endl;
  sudoku1.print_board();

  time_t start = time(0);
  if(sudoku1.solver()){
    cout << "Solved!" << endl;
    sudoku1.print_board();
  }
  cout << endl;
  cout << "Time to solve: " << time(0) - start << endl;
  cout << endl;

  return 0;
}

