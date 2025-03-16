#include<stdio.h> // Include the standard input/output library
#define N 4 // Define a constant N for the size of the puzzle

type Pazz struct{ // Define a structure for the puzzle
  P [N][N]int // 2D array to store the puzzle state
}

var Q Pazz // Initialize a global variable Q to store the puzzle state
var dx [4]int ={0,1,0,-1} // Define an array for horizontal movement directions
var dy [4]int ={1,0,-1,0} // Define an array for vertical movement directions

func Heu(Q Pazz) int { // Heuristic function to calculate the Manhattan distance
  var i,j int
  var hx,hy,sum int =0
  for i=0;i<N;i++{ // Iterate through each row
    for j=0;j<N;j++{ // Iterate through each column
      if Q.P[i][j]==0 continue // Skip the empty tile

      hx=(Q.P[i][j]-1)%N-j // Calculate the horizontal distance
      hy=(Q.P[i][j]-1)/N-i // Calculate the vertical distance

      if hx<0 sum-=hx // Add the horizontal distance to the sum
      else sum+=hx

      if hy<0 sum-=hy // Add the vertical distance to the sum
      else sum+=hy
    }
  }
  return sum // Return the total sum of Manhattan distances
}

func dfs (x,y,max,count,n int) int { // Depth-first search function
  var i,temp int
  var x0,y0,ans int =-1,h int

  h=Heu(Q) // Calculate the heuristic value of the current state

  if h==0 return count // If the puzzle is solved, return the number of moves
  if ((count+h) > max) return -1 // If the maximum depth is exceeded, return -1

  for i=0;i<4;i++{ // Iterate through all possible moves
    x0=x+dx[i]
    y0=y+dy[i]

    if (((i == (n+2)%4 )&& (n!=-1))||!((0<=x0 )&&( x0<N) && (0<=y0) && (y0<N))) continue // Skip invalid moves
    temp=Q.P[y][x] // Swap the current tile with the target tile
    Q.P[y][x]=Q.P[y0][x0]
    Q.P[y0][x0]=temp

    ans= dfs(x0,y0,max,count+1,i) // Recursively call dfs with the new state

    if ans!=-1 return ans // If a solution is found, return the number of moves
    temp=Q.P[y][x] // Swap back to the original state
    Q.P[y][x]=Q.P[y0][x0]
    Q.P[y0][x0]=temp
  }

  return -1 // If no solution is found, return -1
}

func main(){ // Main function to read the puzzle, initialize it, and start the DFS search
  var i,j int
  var kx,ky,ans,a int
  var tP Pazz

  for i=0;i<N;i++{ // Read the puzzle from input
    for j=0;j<N;j++{
      fmt.Scanf("%d",&a)
      Q.P[i][j]=a
      if a==0{
        kx=j
        ky=i
      }
    }
  }

  tP=Q // Store the initial puzzle state
  for i=1;i<46;i++{ // Iterate through possible depths
    Q=tP
    ans=dfs(kx,ky,i,0,-1)
    if ans!=-1{
      fmt.Printf("%d\n",ans) // Print the number of moves if a solution is found
      break
    }
  }

  return 0 // Return 0 to indicate successful execution
}

