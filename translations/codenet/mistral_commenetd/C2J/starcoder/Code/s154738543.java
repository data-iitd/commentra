
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        int x, y; // Declaring two integer variables x and y

        Scanner input = new Scanner(System.in); // Creating a Scanner object to read input from the user

        System.out.print("Enter a number: "); // Printing a message to ask user for input
        x = input.nextInt(); // Reading an integer value from the user and storing it in variable x

        y = x * x * x; // Assigning the value of x cubed to variable y

        System.out.printf("The cube of %d is %d\n", x, y); // Printing the message with the input number and its cube

    }
}

