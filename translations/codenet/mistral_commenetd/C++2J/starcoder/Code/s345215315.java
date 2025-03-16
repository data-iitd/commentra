import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        // Initialize the 2D vector to store the grid
        Scanner sc = new Scanner(System.in);
        int h = 19,w = 15;
        String[][] s = new String[h][w];
        rep(i,h)s[i] = sc.next().split("");

        // Find the position of the 'O'
        int sx,sy;
        rep(i,h)rep(j,w)if(s[i][j].equals("O")){
            sx = i;
            sy = j;
            s[i][j] = ".";
        }

        // Perform a depth-first search from the position of the 'O' with 0 steps
        dfs(s,sx,sy,0);

        // Print the answer if it is not equal to INF
        if(ans == INF)System.out.println(-1);
        else System.out.println(ans);
    }

    // Function to perform a depth-first search from a given position
    // with a given number of steps
    static void dfs(String[][] s, int x, int y, int cnt){
        // Base case: if the number of steps is greater than 20, return
        if(cnt > 20)return;

        // Print the current position, number of steps, and the current state of the grid
        // for debugging purposes
        //System.out.println(x + " " + y + " " + cnt);
        // Print the current state of the grid
        //rep(i,h)System.out.println(s[i]);

        // Check if the current position is the last row of the grid
        if(x == h-1){
            // Update the answer if the current number of steps is less than the previous answer
            ans = Math.min(ans,cnt);
            return;
        }

        // Iterate through all the possible directions
        rep(i,8){
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Check if the next position is out of the grid
            if(nx < 0 || nx >= h || ny < 0 || ny >= w)continue;

            // Check if the next position contains an 'X'
            if(!s[nx][ny].equals("X"))continue;

            // Perform a depth-first search from the next position with one more step
            boolean c = true;
            while(c && s[nx][ny].equals("X")){
                s[nx][ny] = ".";
                nx += dx[i];
                ny += dy[i];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w){
                    if(nx >= h)ans = Math.min(ans, cnt+1);
                    c = false;
                }
            }

            // If the loop did not exit due to an out-of-grid position, perform the depth-first search
            if(c)dfs(s,nx,ny,cnt+1);

            // Backtrack by restoring the previous state of the grid
            while(nx!= x || ny!= y){
                nx -= dx[i];
                ny -= dy[i];
                s[nx][ny] = "X";
            }

            // Restore the current position of the 'O'
            s[x][y] = ".";
        }
    }

    // Global variables
    static int ans = Integer.MAX_VALUE;
    static int h = 19,w = 15;
    static int[] dx = {0,1,0,-1,1,1,-1,-1};
    static int[] dy = {1,0,-1,0,1,-1,1,-1};
}

