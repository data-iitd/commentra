import java.util.Scanner; // We import the Scanner class to read user input

public class Main { // We define the Main class
    public static void main(String[] args) { // The main method is the entry point of the program
        Scanner scanner = new Scanner(System.in); // We create a Scanner object to read input
        long a, b; // We declare two long integers named a and b to store user input

        // We read user input and store it in variables a and b
        a = scanner.nextLong();
        b = scanner.nextLong();

        if ((a + b) % 2 == 0) { // We check if the sum of a and b is even
            // If the sum is even, we print the result by dividing it by 2
            System.out.println((a + b) / 2);
        } else { // If the sum is odd, we print "IMPOSSIBLE"
            System.out.println("IMPOSSIBLE");
        }

        scanner.close(); // We close the scanner to free up resources
    }
}

// <END-OF-CODE>
