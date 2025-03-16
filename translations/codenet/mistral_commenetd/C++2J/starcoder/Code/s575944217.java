
import java.util.*;
import java.lang.*;
import java.io.*;

class Main
{
    public static void main (String[] args) throws java.lang.Exception
    {
        // Read the number of vertices from the input
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // Initialize an answer vector of size n
        int[] ans = new int[n];

        // Read the edges and increment the count of each vertex in the answer vector
        for(int i=0;i<n-1;i++){
            int a = sc.nextInt();
            a--; // Decrement the vertex index as it is 0-indexed
            ans[a]++; // Increment the count of the vertex
        }

        // Print the answer vector
        for(int i=0;i<n;i++)
            System.out.println(ans[i]);
    }
}

