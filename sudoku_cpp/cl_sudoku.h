#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Sudoku{
  public:
    Sudoku(int,int,string); 
    bool solver();
    void print_board();
    //int get_depth();
  private:
    //int static depth;
    int npuz;
    int nbox;
    int** board;
    bool in_row(int, int);
    bool in_col(int, int);
    bool in_box(int, int, int);
    bool legal_move(int, int, int);
    void read_board(string);
    bool find_zero(int&, int&);
};

