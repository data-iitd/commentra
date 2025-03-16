
import java.util.Scanner; // Importing the Scanner class for reading input from the user

public class s589878052{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Creating a Scanner object to read input from the user

        int a = scanner.nextInt(); // Reading the first integer input from the user and storing it in the variable a
        int b = scanner.nextInt(); // Reading the second integer input from the user and storing it in the variable b
        int h = scanner.nextInt(); // Reading the third integer input from the user and storing it in the variable h

        System.out.println((a + b) * h / 2); // Calculating and printing the area of a trapezoid

        scanner.close(); // Closing the Scanner object to release system resources
    }
}
