import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Set the recursion limit to a large value
        // This is necessary to prevent a "StackOverflowError" when dealing with large inputs
        // In Java, we don't have a direct equivalent to Python's setrecursionlimit,
        // but we can control the stack size using JVM options.
        // For example, to set the stack size to 1GB, you can use:
        // java -Xss1G Main
        // However, for simplicity, we'll just set a default value here.

        // Import other required modules
        // In Java, we use classes from the java.util package and custom classes for other functionalities
        Scanner scanner = new Scanner(System.in);

        // Read input for two numbers 'a' and 'b'
        String[] input = scanner.nextLine().split(" ");
        int a = Integer.parseInt(input[0]);
        double b = Double.parseDouble(input[1]) * 100;

        // Calculate the product of 'a' and 'b' and print the result
        System.out.println((int) (a * b / 100));
    }
}
