import java.util.Scanner; // Importing the Scanner class for input operations

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Initializing a Scanner to read input

        // Reading the first integer input
        int a = sc.nextInt();
        // Reading the second integer input
        int b = sc.nextInt();

        // Checking if the product of a and b is odd or even and printing the result
        if (a * b % 2 != 0) {
            System.out.println("Odd");
        } else {
            System.out.println("Even");
        }

        sc.close(); // Closing the scanner
    }
}

// <END-OF-CODE>
