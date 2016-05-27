import os
import random
import time


class Sudoku:
  def __init__(self, nPuzzle, nBox, filename):
    self.nPuzzle = nPuzzle
    self.nBox    = nBox
    self.board   = self.readMyBoard(filename)

  def makeRandomBoard(self, nzero):
    random.seed(time.time())
    n = 0
    while n < nzero:
      i = random.randint(0, self.nPuzzle - 1)
      j = random.randint(0, self.nPuzzle - 1)
      k = random.randint(1, self.nPuzzle)
      if self.isLegalMove(i, j, k):
        self.board[i][j] = k
        n += 1

  def blankBoard(self):
    board = []
    for i in range(0,self.nPuzzle):
      board.append([0] * self.nPuzzle)
    return board

  def readMyBoard(self, infile):
    board = []
    with open(infile) as f:
      for line in f:
        line = line.split()
        if line:
          line = [int(i) for i in line]
          board.append(line)
    return board

  def printMyBoard(self):
    nLine = 0
    for line in self.board:
      nLine += 1
      line = [str(i) for i in line]
      for i in range(self.nBox, len(line), self.nBox + 1):
        line.insert(i, "|")
      line = ' '.join([str(i) for i in line])
      print(line)
      if nLine % self.nBox == 0 and nLine < self.nPuzzle:
        print("-" * len(line))
    print()

  def isLegalMove(self, i, j, val):
    tmp = [self.board[i][j] for i in range(0, self.nPuzzle)]
    if val in tmp:
      return False
    tmp = [self.board[i][j] for j in range(0, self.nPuzzle)]
    if val in tmp:
      return False
    tmp = self.makeBox(i, j)
    if val in tmp:
      return False
    return True

  def makeBox(self, i, j):
    box = []
    iScale = i - (i % self.nBox)
    jScale = j - (j % self.nBox)
    for i in range(0, self.nBox):
      ival = i + iScale 
      for j in range(0, self.nBox):
        jval = j + jScale 
        box.append(self.board[ival][jval])
    return box

  def isSolved(self):
    for row in self.board:
      if 0 in row:
        return False
    else:
      return True

  def solveBoard(self):
    if self.isSolved():
      return True
    for i in range(0, self.nPuzzle):
      for j in range(0, self.nPuzzle):
        if self.board[i][j] == 0:
          for k in range(1, self.nPuzzle + 1):
            if self.isLegalMove(i, j, k) and k < self.nPuzzle + 1:
              self.board[i][j] = k
              if self.solveBoard():
                return True
          else:
            self.board[i][j] = 0
            return False
  
          

       







