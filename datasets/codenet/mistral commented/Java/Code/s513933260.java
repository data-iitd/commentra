import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // This method is the entry point of the Java application
        Scanner stdIn = new Scanner(System.in);

        // Read a long integer value from the standard input
        long n = stdIn.nextLong();

        // Calculate the sum of the first n natural numbers (excluding n)
        long sum = n * (n + 1);

        // Divide the sum by 2
        long result = sum / 2;

        // Subtract n from the result
        long finalResult = result - n;

        // Print the final result
        System.out.println(finalResult);
    }
}