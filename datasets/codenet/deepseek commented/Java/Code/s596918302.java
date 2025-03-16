import java.util.*;
public class Main {
    public static void main(String args[]) {
    
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt(); // Reading input for the size of the array
    int[][] arr = new int[n][3]; // Initializing a 2D array with dimensions n x 3
    
    for(int i =0 ; i<n; i++) { // Filling the array with input values
        for(int j =0; j<3; j++)
        arr[i][j]=sc.nextInt();
    }
    
    int ans = 0;
    //ans = Math.max(dpc(arr, 0, n, 0), Math.max(dpc(arr,1,n,0), dpc(arr,2,n, 0)));
    ans = dpx(arr,n); // Calculating the answer using the dpx function
      System.out.println(ans); // Printing the result
      
      
    }
    
    static int min(int[] arr, int n) // Recursive function to calculate the minimum cost
    { 
        if(n==1) return 0; // Base case for single element
        if(n==2) return Math.abs(arr[n-1]-arr[n-2]); // Base case for two elements
            int op1 = Math.abs(arr[n-1]-arr[n-2]) +min(arr,n-1); // Recursive case 1
            int op2 = Math.abs(arr[n-1]-arr[n-3]) +min(arr,n-2); // Recursive case 2
          int res = Math.min(op1, op2); // Choosing the minimum cost
          
          return res;
    }
    
    static int dpc(int[][] arr, int i, int n, int row) // Dynamic programming function
    {
        if(row==n) // Base case for end of array
            return 0;
            int j=0;
            int k=0;
            if(i==1) // Setting indices based on the current index
                {
                    j=0;
                    k=2;
                }
                
            else  if(i==0)
                {
                    j=1;
                    k=2;
                }    
                
            else
            {
                j =0;
                k=1;
            }
            
            return arr[row][i]+Math.max(dpc(arr,j,n,row+1),dpc(arr,k,n,row+1)); // Recursive call with updated indices
        
    }
    
    static int dpx(int[][] arr, int n) // Another dynamic programming function
    {
        int[][] dp = new int[n][3]; // Initializing a 2D array for dynamic programming
        
        dp[0][0]=arr[0][0]; // Setting the base case for the first row
        dp[0][1]=arr[0][1];
        dp[0][2]=arr[0][2];
        
        for(int i=1; i<n; i++) { // Iterating through the array
            for(int in=0; in<3;in++) { 
                int j=0,k=0;
                 if(in==1) { // Setting indices based on the current index
                    j=0;
                    k=2;
                }
                
            else  if(in==0) {
                    j=1;
                    k=2;
                }    
                
            else {
                j =0;
                k=1;
            }
                dp[i][in] = Math.max(dp[i-1][k] ,dp[i-1][j]) +arr[i][in]; // Updating the dp array
            }
        }