#include<stdio.h>
#define N 4

# Define a structure to represent the puzzle state
class Pazz:
  def __init__(self):
    self.P = [[0 for i in range(N)] for j in range(N)]

Q = Pazz() # Global variable to hold the current state of the puzzle
dx = [0,1,0,-1] # Array to represent movement in the x-direction (right, down, left, up)
dy = [1,0,-1,0] # Array to represent movement in the y-direction (right, down, left, up)

# Function to calculate the heuristic value (Manhattan distance) of the puzzle state
def Heu(Q):
  i, j
  hx, hy, sum = 0, 0, 0 # Initialize variables for horizontal and vertical distances, and sum

  # Loop through each cell in the puzzle
  for i in range(N):
    for j in range(N):
      # Skip the empty tile (represented by 0)
      if(Q.P[i][j] == 0) continue

      # Calculate the expected position of the tile
      hx = (Q.P[i][j] - 1) % N - j # Horizontal distance
      hy = (Q.P[i][j] - 1) / N - i # Vertical distance

      # Update the sum based on the distances
      if(hx < 0): sum -= hx # If hx is negative, subtract it from sum
      else: sum += hx # Otherwise, add it to sum

      if(hy < 0): sum -= hy # If hy is negative, subtract it from sum
      else: sum += hy # Otherwise, add it to sum
  return sum # Return the total heuristic value

# Depth-first search function to explore possible moves
def dfs(x, y, max, count, n):
  i, temp
  x0, y0, ans = -1, 0, -1, 0 # Initialize variables
  h = Heu(Q) # Calculate the heuristic value for the current state

  # If the puzzle is solved (heuristic is 0), return the count of moves
  if(h == 0): return count

  # If the current count plus heuristic exceeds the maximum allowed, return -1
  if((count + h) > max): return -1

  # Explore all possible moves
  for i in range(4):
    x0 = x + dx[i] # Calculate new x position
    y0 = y + dy[i] # Calculate new y position

    # Check if the move is valid and not reversing the last move
    if(((i == (n + 2) % 4) and (n!= -1)) or not((0 <= x0) and (x0 < N) and (0 <= y0) and (y0 < N))): continue

    # Swap the empty tile with the adjacent tile
    temp = Q.P[y][x]
    Q.P[y][x] = Q.P[y0][x0]
    Q.P[y0][x0] = temp

    # Recursively call dfs with the new position
    ans = dfs(x0, y0, max, count + 1, i)

    # If a solution is found, return the answer
    if(ans!= -1): return ans

    # Swap back to restore the previous state
    temp = Q.P[y][x]
    Q.P[y][x] = Q.P[y0][x0]
    Q.P[y0][x0] = temp
  return -1 # Return -1 if no solution is found

# Main function to execute the program
def main():
  i, j
  kx, ky, ans, a = 0, 0, 0, 0 # Variables to hold the position of the empty tile and the answer
  tP = Pazz() # Temporary variable to hold the puzzle state

  # Read the puzzle input from the user
  for i in range(N):
    for j in range(N):
      scanf("%d", &a) # Read each tile value
      Q.P[i][j] = a # Store the value in the puzzle state
      if(a == 0): # If the tile is empty
        kx = j # Store its x position
        ky = i # Store its y position
    # End of inner for loop
  # End of outer for loop

  tP = Q # Copy the initial puzzle state
  # Attempt to solve the puzzle with increasing maximum move limits
  for i in range(1, 46):
    Q = tP # Reset the puzzle state
    ans = dfs(kx, ky, i, 0, -1) # Call dfs to find a solution
    if(ans!= -1): # If a solution is found
      printf("%d\n", ans) # Print the number of moves
      break # Exit the loop
  # End of for loop

  return 0 # Return success
# End of main function

# 