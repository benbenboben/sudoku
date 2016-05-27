import sys
import time
import sudoku


def main():
  mySudoku = sudoku.Sudoku(9, 3, 'board.txt')
  print("Board to be solved: ")
  mySudoku.printMyBoard()
  print()
  prompt = input('Press (C)ontinue or (Q)uit... ')
  print()
  if not prompt.upper().startswith('C'):
    print("quitting...") 
    print()
    sys.exit()
  print()
  start = time.time()
  if mySudoku.solveBoard():
    print("solved!...")
    mySudoku.printMyBoard()
    end = time.time()
    total = end - start
    print("Total time to solve: %s seconds." % (total))
  else:
    print("not solved...")


if __name__ == '__main__':
  main()
