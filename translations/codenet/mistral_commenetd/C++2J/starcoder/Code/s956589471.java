
import java.util.*; // Include the standard input and output library

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object for reading the standard input
        int a = sc.nextInt(); // Read an integer from the standard input and store it in a
        int b = sc.nextInt(); // Read an integer from the standard input and store it in b
        int c = sc.nextInt(); // Read an integer from the standard input and store it in c
        int d = sc.nextInt(); // Read an integer from the standard input and store it in d
        int e = sc.nextInt(); // Read an integer from the standard input and store it in e
        int k = sc.nextInt(); // Read an integer from the standard input and store it in k

        // Perform a simple condition check using the relational operator <=
        if (e - a <= k) {
            System.out.println("Yay!"); // If the condition is true, print "Yay!" to the standard output
        } else {
            System.out.println(":("); // If the condition is false, print ":" and a sad face "(" to the standard output
        }
    }
}

