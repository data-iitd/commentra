
import java.util.*;

public class Main {
    public static void main(String[] args){
        // Create a new Scanner object to read input from the standard input stream
        Scanner sc = new Scanner(System.in);

        // Read the first integer `N` from the standard input using the nextInt() method of the Scanner class and assign it to the variable `N`
        int N = sc.nextInt();

        // Initialize the variable `count` to zero
        int count = 0;

        // Initialize the variable `next` to 10
        int next = 10;

        // Start a for loop that iterates from 1 to `N`
        for(int i = 1; i <= N; i++){
            // Increment the `count` variable
            count++;

            // Check if the current iteration `i` is one less than the value of `next` minus 1
            if(i == next - 1){
                // If the condition is true, update the value of `i` to be one less than the value of `next` times 10, and update the value of `next` to be the next power of 10
                i = next * 10 - 1;
                next *= 100;
            }
        }

        // Print the value of `count` to the standard output using the println() method of the PrintStream class
        System.out.println(count);

        // Close the Scanner object to free up system resources
        sc.close();
    }
}