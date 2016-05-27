#include <iostream>
#include <string>
#include <fstream>
#include "cl_sudoku.h"
using namespace std;

Sudoku::Sudoku(int np, int nb, string fname){
  npuz = np;
  nbox = nb;
  board = new int*[npuz];
  for(int irow=0;irow<npuz;irow++){
    board[irow] = new int[npuz];}

  read_board(fname);
};


bool Sudoku::solver(){
  static int depth = 0;
  depth++;
  int row;
  int col;
  if(!find_zero(col,row)){
    cout << depth << endl;
    return true;
  }
  for(int val = 1; val < 10; val++){
    if(legal_move(row,col,val)){
      board[row][col] = val;
      if(solver())
        return true;
      board[row][col] = 0;
    }
  }
  return false;
};

bool Sudoku::find_zero(int& col, int& row){
  for(row = 0; row < npuz; row++){
    for(col = 0; col < npuz; col++){
      if(board[row][col] == 0){ 
        return true;
      }
    }
  }
  return false;
};

/*
int Sudoku::get_depth(){
  int return_val = depth;
  return return_val;
};  
*/

void Sudoku::print_board(){
  for(int i=0;i<npuz;i++){
    //cout << endl;
    for(int j=0;j<npuz;j++){
      if(j>0 && j%nbox == 0){
        cout << "| ";
      }
      cout << board[i][j] << " ";
    }
    if(i>0 && (i+1)%nbox == 0 && i<(npuz-1)){
      cout << endl;
      cout << "-----------------------";
    }
    cout << endl;
  }
  cout << endl;
};

void Sudoku::read_board(string file_in){
  int tmp;
  ifstream inp;
  inp.open(file_in.c_str());
  //inp.open(file_in);
  if(! inp.is_open()){
    cout << " *** error reading board *** " << endl;
  }else{
    cout << " reading... " << endl;
  }
  for(int i=0;i<npuz;i++){
    for(int j=0;j<npuz;j++){
      inp >> tmp;
      board[i][j]=tmp;
    }
  }
  inp.close();
};

bool Sudoku::legal_move(int row, int col, int val){
  return !in_row(row, val) && !in_col(col, val) &&
         !in_box((row - row%nbox), (col - col%nbox), val);
};

bool Sudoku::in_row(int row, int val){
  for(int col = 0; col < npuz; col++){
    if(board[row][col]==val) return true;
  }
  return false;
};

bool Sudoku::in_col(int col, int val){
  for(int row = 0; row < npuz; row++){
    if(board[row][col]==val) return true;
  }
  return false;
};

bool Sudoku::in_box(int rowstart, int colstart, int val){
  for (int row = 0; row < nbox; row++){
    for (int col = 0; col < nbox; col++){
      if(board[row+rowstart][col+colstart] == val){
        return true;
      }
    }
  }
  return false;
};
