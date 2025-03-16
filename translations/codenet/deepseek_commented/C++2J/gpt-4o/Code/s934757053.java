import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int A, B;
        int ans = 0;
        int out = 1; // Initialize out to 1

        A = scanner.nextInt(); // Read integer A from the standard input
        B = scanner.nextInt(); // Read integer B from the standard input

        while (out < B) { // Continue the loop as long as out is less than B
            out--; // Decrement out by 1
            out += A; // Increment out by A
            ans++; // Increment ans by 1
        }
        
        System.out.println(ans); // Print the value of ans to the standard output
        scanner.close(); // Close the scanner
    }
}

// <END-OF-CODE>
