import java.util.Scanner; // Importing the Scanner class for user input

public class Main { // Defining the Main class
    public static void main(String[] args) { // The entry point of the program
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object for input
        int n, i, a; // Declaring variables n, i, and a

        n = scanner.nextInt(); // Reading an integer value from the user and storing it in variable n

        for (i = 1; i <= n; i++) { // Starting a for loop that runs from 1 to n
            a = i; // Assigning the value of i to variable a

            if ((a % 3) == 0) { // Checking if the value of a is divisible by 3
                System.out.print(" " + i); // If true, print the value of i to the console
            } else { // If the condition is false
                while (a > 0) { // Starting an inner while loop that runs as long as a is greater than 0
                    if ((a % 10) == 3) { // Checking if the last digit of the number stored in a is 3
                        System.out.print(" " + i); // If true, print the value of i to the console
                        break; // Breaking out of the inner while loop
                    }
                    a = a / 10; // Otherwise, moving to the next digit by dividing a by 10
                }
            }
        }
        System.out.println(); // Printing a newline character to move the cursor to the next line
        scanner.close(); // Closing the scanner to prevent resource leaks
    }
} // End of the Main class
// <END-OF-CODE>
