

d = int(input()) # number of test cases

for l in range(d): # iterate through each test case
  n = int(input()) # size of the grid

  if n == 1: # if the size of the grid is 1
    print("#") # print '#'
    if l!= d-1: print() # print newline if it's not the last test case
    continue # move to the next test case

  map = [['#' for j in range(n+2)] for i in range(n+2)] # initialize the map with '#' and '.'

  for i in range(1, n+1):
    for j in range(1, n+1):
      map[i][j] = '.'

  def visit():
    # function to find the path of 'O' in the grid
    ab = [2, 2, 2, 2] # array to store the number of 'O's in 4 directions

    while True:
      sum = 0 # initialize sum to 0
      flg = 0 # initialize flag to 0

      while True:
        if map[y+dy[flg]*2][x+dx[flg]*2]!= '#' and map[y+dy[flg]][x+dx[flg]]!='':
          # check if the next cell is not a wall or empty
          flg += 1 # increment flag

          # mark the cell as visited
          map[y+dy[flg]][x+dx[flg]] =''

          # move to the next cell
          y = y + dy[flg]
          x = x + dx[flg]

          sum += 1 # increment sum

          break

      if flg == 4: # if all 4 directions are visited
        flg = 0 # reset flag

        if sum == 0: break # if no 'O' is found, break the loop

        ab[0] = ab[1] # copy the value of ab[1] to ab[0]
        ab[1] = ab[2] # copy the value of ab[2] to ab[1]
        ab[2] = sum # store the number of 'O's in the current direction

        if ab[0] == 1 and ab[2] == 1 and ab[1] == 1: # check if all 3 directions have 'O's
          break # if yes, break the loop
      else:
        break

  visit() # call the visit function

  for i in range(1, n+1): # print the grid
    for j in range(1, n+1):
      print(map[i][j], end='')
    print()

  if l!= d-1: print() # print newline if it's not the last test case

print("