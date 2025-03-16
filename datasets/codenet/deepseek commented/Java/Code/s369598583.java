
import java.util.*;

public class Main {
    public static void main(String[] args){
        // Import the Scanner class to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read an integer N from the user
        int N = sc.nextInt();
        
        // Initialize count to keep track of the number of integers
        int count = 0;
        
        // Initialize next to determine the range of numbers to skip
        int next = 10;
        
        // Loop from 1 to N
        for(int i = 1; i <= N; i++){
            // Increment the count for each integer
            count++;
            
            // If the current number i is one less than next, reset i and update next
            if(i == next - 1){
                i = next * 10 - 1;
                next *= 100;
            }
        }
        
        // Print the final count of integers
        System.out.println(count);
    }
}

I hope this helps! Let me know if you need any further assistance.