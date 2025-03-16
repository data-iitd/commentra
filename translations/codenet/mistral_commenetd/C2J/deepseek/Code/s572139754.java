import java.util.Scanner; // Importing the Scanner class to read input from the user

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object to read input from the user

        System.out.print("Enter a number: "); // Printing a message to ask the user to enter a number
        int n = scanner.nextInt(); // Reading an integer value from the standard input and storing it in the variable `n`

        if(n % 1000 == 0) { // Checking if the remainder of `n` when divided by 1000 is equal to 0
            System.out.println(0); // If the condition is true, we print the value 0 to the standard output
        } else {
            System.out.println((n / 1000 + 1) * 1000 - n); // If the condition is false, we calculate the number that is one thousand greater than the quotient of `n` when divided by 1000 and print that value to the standard output
        }

        scanner.close(); // Closing the Scanner object
    }
}
