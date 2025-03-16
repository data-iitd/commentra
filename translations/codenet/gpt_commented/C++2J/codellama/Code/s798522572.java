import java.util.Scanner;
import java.util.Vector;

public class Solution {

    public static void main(String[] args) {
        // Declare variables for the number of elements (N) and a threshold (T)
        int N, T;
        
        // Read the number of elements and the threshold from input
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        T = sc.nextInt();
        
        // Initialize an array A to hold the input values
        int[] A = new int[N];
        
        // Initialize a vector B to hold the transformed values
        Vector<Integer> B = new Vector<Integer>();
        
        // Read N integers into the array A
        for(int i = 0; i < N; i++) 
            A[i] = sc.nextInt();
        
        // Initialize m with the first element of A
        int m = A[0];
        
        // Calculate the first element of B based on the first element of A and update m
        B.add(A[1] - m);
        m = Math.min(m, A[1]);
        
        // Loop through the remaining elements of A to fill B and update m
        for(int i = 2; i < N; i++){
            // Fill B[i] with the difference between A[i] and the minimum value found so far (m)
            B.add(A[i] - m);
            
            // Update m to be the minimum of the current m and A[i]
            m = Math.min(m, A[i]);
        }
        
        // Count and output the number of times the maximum element in B appears
        System.out.println(count(B, B.get(B.size() - 1)));
    }
    
    // Count the number of occurrences of a given value in a vector
    public static int count(Vector<Integer> v, int value){
        int count = 0;
        for(int i = 0; i < v.size(); i++)
            if(v.get(i) == value)
                count++;
        return count;
    }
}

