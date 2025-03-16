import java.util.Scanner; // Importing Scanner class for user input
import java.util.stream.IntStream; // Importing IntStream for range operations

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);
        
        // Reading two integers from user input: n and x
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        
        // Calling the print method with the inputs x and n
        print(x, n);
    }

    public static void print(int x, int n) {
        // Calculating the maximum value based on n
        int max = n * 2 - 1;
        
        // Checking if x is equal to 1 or max, if so, print "No" and exit the method
        if (x == 1 || x == max) {
            System.out.println("No");
            return; // Exit the method early
        }
        
        // If x is valid, print "Yes"
        System.out.println("Yes");
        
        // Prepare the line separator for formatting output
        String sep = System.lineSeparator();
        
        // Generate a sequence of numbers based on the input x and n
        String ans = IntStream.range(x + n - 1, x + n + max - 1)
            .mapToObj(e -> (e % max + 1) + sep) // Adjusting the number to fit within the range
            .collect(StringBuilder::new, StringBuilder::append, StringBuilder::append)
            .toString(); // Collecting the results into a single string
        
        // Print the generated sequence
        System.out.println(ans);
    }
}
