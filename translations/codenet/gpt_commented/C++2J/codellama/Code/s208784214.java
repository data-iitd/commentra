import java.util.Scanner; // Import the Scanner class for input and output operations

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a Scanner object for input

        int N = sc.nextInt(); // Read an integer from standard input
        int A = sc.nextInt(); // Read an integer from standard input

        // Check if the remainder of N divided by 500 is less than or equal to A
        // If true, print "Yes"; otherwise, print "No"
        System.out.println((N % 500 <= A) ? "Yes" : "No");
    }
}

