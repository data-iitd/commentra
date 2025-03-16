import java.util.Scanner; // Import the Scanner class for user input

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner in = new Scanner(System.in);
        
        // Read three integers from the input: T, S, and q
        int T = in.nextInt(); // The upper limit
        int S = in.nextInt(); // The starting value
        int q = in.nextInt(); // The multiplier
        
        long previous = S; // Initialize 'previous' with the starting value S
        int answer = 0; // Initialize the answer counter
        
        // Loop until 'previous' is less than 'T'
        while (previous < T) {
            answer++; // Increment the answer counter
            previous *= q; // Multiply 'previous' by 'q' for the next iteration
        }
        
        // Output the final count of how many times 'previous' was multiplied before reaching 'T'
        System.out.println(answer);
    }
}
