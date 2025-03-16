import java.util.*;

public class Main{
  public static void main(String[] args){
    int[][] P=new int[4][4]; // Initialize a 2D array to store the puzzle state
    int[] dx={0,1,0,-1}; // Define an array for horizontal movement directions
    int[] dy={1,0,-1,0}; // Define an array for vertical movement directions
    int i,j,kx,ky,ans,a;
    int[] tP=new int[16]; // Store the initial puzzle state
    for(i=0;i<4;i++){ // Read the puzzle from input
      for(j=0;j<4;j++){
        P[i][j]=Integer.parseInt(args[i*4+j]);
        if(P[i][j]==0){
          kx=j;
          ky=i;
        }
      }
    }

    for(i=0;i<16;i++){ // Iterate through possible depths
      for(j=0;j<4;j++)tP[j]=P[j][i%4];
      for(j=0;j<4;j++)P[j][i%4]=tP[j];
      for(j=0;j<4;j++)tP[j]=P[i%4][j];
      for(j=0;j<4;j++)P[i%4][j]=tP[j];
      ans=dfs(P,kx,ky,i+1,0,-1);
      if(ans!=-1){
        System.out.println(ans); // Print the number of moves if a solution is found
        break;
      }
    }
  }

  public static int dfs(int[][] P,int x,int y,int max,int count,int n){ // Depth-first search function
    int i,temp;
    int x0,y0,ans=-1,h;

    h=Heu(P); // Calculate the heuristic value of the current state

    if(h==0)return count; // If the puzzle is solved, return the number of moves
    if((count+h) > max)return -1; // If the maximum depth is exceeded, return -1

    for(i=0;i<4;i++){ // Iterate through all possible moves
      x0=x+dx[i];
      y0=y+dy[i];

      if(((i == (n+2)%4 )&& (n!=-1))||!((0<=x0 )&&( x0<4) && (0<=y0) && (y0<4)))continue; // Skip invalid moves
      temp=P[y][x]; // Swap the current tile with the target tile
      P[y][x]=P[y0][x0];
      P[y0][x0]=temp;

      ans= dfs(P,x0,y0,max,count+1,i); // Recursively call dfs with the new state

      if(ans!=-1)return ans; // If a solution is found, return the number of moves
      temp=P[y][x]; // Swap back to the original state
      P[y][x]=P[y0][x0];
      P[y0][x0]=temp;
    }

    return -1; // If no solution is found, return -1
  }

  public static int Heu(int[][] P){ // Heuristic function to calculate the Manhattan distance
    int i,j;
    int hx,hy,sum=0;
    for(i=0;i<4;i++){ // Iterate through each row
      for(j=0;j<4;j++){ // Iterate through each column
        if(P[i][j]==0)continue; // Skip the empty tile

        hx=(P[i][j]-1)%4-j; // Calculate the horizontal distance
        hy=(P[i][j]-1)/4-i; // Calculate the vertical distance

        if(hx<0)sum-=hx; // Add the horizontal distance to the sum
        else sum+=hx;

        if(hy<0)sum-=hy; // Add the vertical distance to the sum
        else sum+=hy;
      }
    }
    return sum; // Return the total sum of Manhattan distances
  }
}

