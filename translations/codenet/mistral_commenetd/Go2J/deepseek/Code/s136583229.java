import java.util.Scanner; // Importing the 'Scanner' class from 'java.util' package for reading user input

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read user input
        Scanner scanner = new Scanner(System.in);

        // Declaring a variable 'data' of type 'int' to read user input
        int data = scanner.nextInt();

        // Declaring a variable 'result' of type 'int' to store the result
        int result = 0;

        // Assigning the value of 'data' cubed to the 'result' variable
        result = data * data * data;

        // Printing the result using the 'System.out.println' method
        System.out.println(result); // Printing the result
    }
}

