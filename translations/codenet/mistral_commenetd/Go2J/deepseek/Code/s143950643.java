import java.util.Scanner; // Importing the 'Scanner' class for input operations

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the standard input stream
        Scanner scanner = new Scanner(System.in);

        // Declaring a variable 'a' of type 'int'
        int a;

        // Reading an integer value from the standard input using the Scanner object
        a = scanner.nextInt();

        // Multiplying the value of 'a' with itself twice and storing the result in a variable
        int result = 3 * a * a;

        // Printing the result to the standard output using 'System.out.println'
        System.out.println(result);
        // This line prints the square of the number 'a' multiplied by 3
    }
}

