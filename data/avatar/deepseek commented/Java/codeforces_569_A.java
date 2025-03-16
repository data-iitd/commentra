
import java.util.Scanner; // Import the Scanner class for reading user input

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // Create a Scanner object to read input
        
        // Read the values of T, S, and q from the user input
        int T = in.nextInt();
        int S = in.nextInt();
        int q = in.nextInt();
        
        // Initialize the variable `previous` with the value of S
        long previous = S;
        
        // Initialize the variable `answer` with the value 0
        int answer = 0;
        
        // Enter a while loop that continues until `previous` is less than T
        while (previous < T) {
            // Inside the loop, multiply `previous` by q and increment the `answer` by 1
            previous *= q;
            answer++;
        }
        
        // After the loop, print the value of `answer`
        System.out.println(answer);
    }
}

