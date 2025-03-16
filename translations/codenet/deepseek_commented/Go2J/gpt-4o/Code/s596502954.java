import java.util.Scanner; // Importing the Scanner class for input operations

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Creating a Scanner instance for input

        // Reading three integers and checking if their sum is greater than or equal to the third integer
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        if (a + b >= c) {
            System.out.println("Yes"); // Printing "Yes" if the condition is true
        } else {
            System.out.println("No"); // Printing "No" if the condition is false
        }

        sc.close(); // Closing the Scanner
    }
}

// <END-OF-CODE>
