
#include<stdio.h>
#define N 4

# Define a structure Pazz to hold a 2D array P
class Pazz:
  def __init__(self):
    self.P=[[0 for i in range(N)] for j in range(N)]

Q=Pazz() # Initialize an empty Pazz structure Q
dx=[0,1,0,-1] # Define the possible moves in x direction
dy=[1,0,-1,0] # Define the possible moves in y direction

# Function to calculate the heuristic value of the given Pazz structure Q
def Heu(Q):
  i=0 # Iterator variable
  j=0 # Iterator variable
  hx=0 # Local variable
  hy=0 # Local variable
  sum=0 # Local variable

  # Iterate through all the elements of the 2D array P in Q
  for i in range(N):
    for j in range(N):
      # If the current element is not part of the puzzle, continue to next iteration
      if(Q.P[i][j]==0):continue

      # Calculate the heuristic value hx and hy for the current element
      hx=(Q.P[i][j]-1)%N-j
      hy=(Q.P[i][j]-1)/N-i

      # Update the sum based on the heuristic values hx and hy
      if(hx<0):sum-=hx
      else:sum+=hx

      if(hy<0):sum-=hy
      else:sum+=hy

  # Return the final sum as the heuristic value of the given Pazz structure Q
  return sum

# Recursive function to find the solution using Depth First Search algorithm
def dfs (x,y,max,count,n):
  i=0 # Local variable
  temp=0 # Local variable
  x0=0 # Local variable
  y0=0 # Local variable
  ans=-1 # Local variable to store the answer and temporary variables

  # Calculate the heuristic value h of the current Pazz structure Q
  h=Heu(Q)

  # Base case: If the heuristic value h is 0, return the current count as the solution
  if(h==0):return count

  # Check if the current count plus the heuristic value h is greater than the maximum allowed count
  if((count+h) > max):return -1

  # Iterate through all the possible moves from the current position (x,y)
  for i in range(4):
    # Calculate the new position (x0,y0) based on the current position (x,y) and the move i
    x0=x+dx[i]
    y0=y+dy[i]

    # Check if the new position (x0,y0) is valid or not
    if(((i == (n+2)%4 )and (n!=-1))or not((0<=x0 )and ( x0<N) and (0<=y0) and (y0<N))):continue

    # Swap the current position (x,y) with the new position (x0,y0) in the Pazz structure Q
    temp=Q.P[y][x]
    Q.P[y][x]=Q.P[y0][x0]
    Q.P[y0][x0]=temp

    # Recursively call the function dfs with the new position (x0,y0), the maximum allowed count max, the current count+1, and the move i
    ans= dfs(x0,y0,max,count+1,i)

    # If the function call returns a valid solution, return it
    if(ans!=-1):return ans

    # Swap back the current position (x,y) with the new position (x0,y0) in the Pazz structure Q
    temp=Q.P[y][x]
    Q.P[y][x]=Q.P[y0][x0]
    Q.P[y0][x0]=temp

  # If no valid solution is found, return -1
  return -1

# Main function to read the input and call the function dfs to find the solution
def main():
  i=0 # Iterator variable
  j=0 # Iterator variable
  kx=0 # Local variable
  ky=0 # Local variable
  ans=0 # Local variable
  a=0 # Local variable
  tP=Pazz() # Temporary Pazz structure to store the original Pazz structure Q

  # Initialize an empty Pazz structure Q
  for i in range(N):
    for j in range(N):
      # Read the input and store it in the Pazz structure Q
      scanf("%d",&a)
      Q.P[i][j]=a
      if(a==0):
        kx=j # Store the position of the empty cell in x direction
        ky=i # Store the position of the empty cell in y direction
    # Create a temporary Pazz structure tP to store the original Pazz structure Q
    tP=Q

  # Call the function dfs with the initial position (kx,ky), the maximum allowed count 46, the initial count 0, and the initial move -1
  ans=dfs(kx,ky,46,0,-1)

  # If a valid solution is found, print it and exit the program
  if(ans!=-1):
    printf("%d\n",ans)
    exit(0)

  # If no valid solution is found, print an error message and exit the program
  printf("No solution found\n")
  exit(1)

