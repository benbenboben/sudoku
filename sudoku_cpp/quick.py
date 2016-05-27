for i in range(0,9):
  print("i, i % 9: ",i,i%3, i - (i%3))

mylist = [0] * 8
mylist.append([0] * 8)

if 0 in mylist:
  print("mylist has zero")
else:
  print("no zeroes")
