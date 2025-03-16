import java.util.Scanner; // Importing Scanner class for user input

public class Main {

    public static void main(String[] args) { // Main method to start the program
        Scanner sc = new Scanner(System.in); // Creating a new Scanner object to read user input

        long k = sc.nextLong(); // Reading the first long integer value from user input
        long a = sc.nextLong(); // Reading the second long integer value from user input
        long b = sc.nextLong(); // Reading the third long integer value from user input

        // Checking if the condition b is less than or equal to a + 2
        if (b <= a + 2) {
            System.out.println(1 + k); // If true, print the value 1 plus k
            return; // Exit the method after printing the result
        }

        long x = k - (a - 1); // Calculate the value of x
        long ans = a + (x / 2) * (b - a) + (x % 2); // Calculate the answer using the given formula

        System.out.println(ans); // Print the calculated answer
    }
}
