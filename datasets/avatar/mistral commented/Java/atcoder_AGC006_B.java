
import java.util.Scanner; // Importing Scanner class for reading input from the console
import java.util.stream.IntStream; // Importing IntStream class for generating a sequence of integers

public class Main {

    public static void main(String[] args) { // Main method to start the execution of the program
        Scanner scanner = new Scanner(System.in); // Creating a new Scanner object to read input from the console
        int n = scanner.nextInt(); // Reading the first integer input from the user
        int x = scanner.nextInt(); // Reading the second integer input from the user
        print(x, n); // Calling the print method with x and n as arguments
    }

    public static void print(int x, int n) { // Method to print the answer based on the given input
        int max = n * 2 - 1; // Calculating the maximum index for the sequence

        if (x == 1 || x == max) { // Checking if x is the first or last index in the sequence
            System.out.println("No"); // If true, print "No" and return
            return;
        }

        System.out.println("Yes"); // If false, print "Yes"
        String sep = System.lineSeparator(); // Creating a separator string for new lines
        String ans = IntStream.range(x + n - 1, x + n + max - 1) // Generating a sequence of integers from x+n-1 to x+n+max-1
                .mapToObj(e -> (e % max + 1) + sep) // Appending a new line and the next integer to each element of the sequence
                .collect(StringBuilder::new, StringBuilder::append, StringBuilder::append) // Collecting all the elements into a single string
                .toString(); // Converting the StringBuilder object to a String
        System.out.println(ans); // Printing the final answer
    }
}

These comments should provide a clear understanding of what each part of the code does. Let me know if you need any further assistance!