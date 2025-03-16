#include<stdio.h> // Include the standard input/output library
#define N 4 // Define a constant N for the size of the puzzle

typedef struct{ // Define a structure for the puzzle
  int P[N][N]; // 2D array to store the puzzle state
}Pazz;

Pazz Q; // Initialize a global variable Q to store the puzzle state
int dx[4]={0,1,0,-1}; // Define an array for horizontal movement directions
int dy[4]={1,0,-1,0}; // Define an array for vertical movement directions

def Heu(Q): # Heuristic function to calculate the Manhattan distance
  sum = 0
  for i in range(N): # Iterate through each row
    for j in range(N): # Iterate through each column
      if Q.P[i][j] == 0: continue # Skip the empty tile

      hx = (Q.P[i][j] - 1) % N - j # Calculate the horizontal distance
      hy = (Q.P[i][j] - 1) / N - i # Calculate the vertical distance

      if hx < 0: sum -= hx # Add the horizontal distance to the sum
      else: sum += hx

      if hy < 0: sum -= hy # Add the vertical distance to the sum
      else: sum += hy
  return sum # Return the total sum of Manhattan distances

def dfs(x, y, max, count, n): # Depth-first search function
  h = Heu(Q) # Calculate the heuristic value of the current state

  if h == 0: return count # If the puzzle is solved, return the number of moves
  if (count + h) > max: return -1 # If the maximum depth is exceeded, return -1

  for i in range(4): # Iterate through all possible moves
    x0 = x + dx[i]
    y0 = y + dy[i]

    if ((i == (n + 2) % 4) and (n != -1)) or not ((0 <= x0) and (x0 < N) and (0 <= y0) and (y0 < N)): continue # Skip invalid moves
    temp = Q.P[y][x] # Swap the current tile with the target tile
    Q.P[y][x] = Q.P[y0][x0]
    Q.P[y0][x0] = temp

    ans = dfs(x0, y0, max, count + 1, i) # Recursively call dfs with the new state

    if ans != -1: return ans # If a solution is found, return the number of moves
    temp = Q.P[y][x] # Swap back to the original state
    Q.P[y][x] = Q.P[y0][x0]
    Q.P[y0][x0] = temp

  return -1 # If no solution is found, return -1

def main(): # Main function to read the puzzle, initialize it, and start the DFS search
  for i in range(N): # Read the puzzle from input
    for j in range(N):
      a = int(input())
      Q.P[i][j] = a
      if a == 0:
        kx = j
        ky = i

  tP = Q # Store the initial puzzle state
  for i in range(1, 46): # Iterate through possible depths
    Q = tP
    ans = dfs(kx, ky, i, 0, -1)
    if ans != -1:
      print(ans) # Print the number of moves if a solution is found
      break

main() # Call the main function

