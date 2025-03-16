
import java.util.*;

public class s107204188{
    public static void main(String[] args) {
        // Initialize the minimum value to a large number
        int minA = (int)Math.pow(10,9) + 1;
        // Initialize the number of ways to achieve the maximum profit
        int num = 0;
        
        // Create a scanner to read input
        Scanner sc = new Scanner(System.in);
        // Read the number of elements and an unused variable 't'
        int n = sc.nextInt();
        int t = sc.nextInt();
        // Create an array to store the elements
        int[] A = new int[n];
        
        // Read the elements into the array
        for(int i = 0; i < n; i++){
            A[i] = sc.nextInt();
        }
        
        // Iterate through the array to find the maximum profit
        for(int i = 0; i < n; i++){
            // Update the minimum value found so far
            if(minA > A[i]){
                minA = A[i];
            }else{
                // Check if the current profit is equal to the maximum profit found so far
                if(f == A[i] - minA) num++;
                // Update the maximum profit and reset the count if a new maximum is found
                else if(f < A[i] - minA){
                    num = 1;
                    f = A[i] - minA;
                }
            }
        }
        
        // Output the number of ways to achieve the maximum profit
        System.out.println(num);
    }
}

Translate the above Java code to Python and end with comment "