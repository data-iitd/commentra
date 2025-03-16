import java.util.*;

public class Main {
    public static void main(String[] args){
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read an integer N from the input
        int N = sc.nextInt();
        
        // Initialize a counter to keep track of the number of iterations
        int count = 0;
        
        // Initialize a variable to determine the next threshold for skipping numbers
        int next = 10;
        
        // Loop from 1 to N
        for(int i = 1; i <= N; i++){
            // Increment the count for each iteration
            count++;
            
            // Check if the current number is one less than the next threshold
            if(i == next - 1){
                // If true, skip to the next range by setting i to the next threshold
                i = next * 10 - 1;
                
                // Update the next threshold to the next power of 10
                next *= 100;
            }
        }
        
        // Output the total count of iterations
        System.out.println(count);
    }
}
