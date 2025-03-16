
import java.util.Scanner; // Import the Scanner class for input and output

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a new Scanner object for input

        int a = sc.nextInt(); // Read the value of a from the standard input using nextInt()
        int b = sc.nextInt(); // Read the value of b from the standard input using nextInt()
        int c = sc.nextInt(); // Read the value of c from the standard input using nextInt()
        int d = sc.nextInt(); // Read the value of d from the standard input using nextInt()
        int e = sc.nextInt(); // Read the value of e from the standard input using nextInt()
        int k = sc.nextInt(); // Read the value of k from the standard input using nextInt()

        if (e - a <= k) { // Perform a simple condition check using the relational operator <=
            System.out.println("Yay!"); // If the condition is true, print "Yay!" to the standard output
        } else {
            System.out.println(":("); // If the condition is false, print ":" and a sad face "(" to the standard output
        }
    }
}

