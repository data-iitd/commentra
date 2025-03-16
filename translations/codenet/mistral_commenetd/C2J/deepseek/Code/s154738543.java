import java.util.Scanner; // Importing the Scanner class to read input from the user

public class Main { // Main class declaration

    public static void main(String[] args) { // Main method declaration

        Scanner scanner = new Scanner(System.in); // Creating a Scanner object

        int x, y; // Declaring two integer variables x and y

        System.out.print("Enter a number: "); // Printing a message to ask user for input
        x = scanner.nextInt(); // Reading an integer value from the user and storing it in variable x

        y = x * x * x; // Assigning the value of x cubed to variable y

        System.out.printf("The cube of %d is %d\n", x, y); // Printing the message with the input number and its cube

        scanner.close(); // Closing the Scanner object
    }
}
