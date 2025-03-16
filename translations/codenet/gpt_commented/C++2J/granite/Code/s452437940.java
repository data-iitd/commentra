
import java.util.*;
import java.io.*;

public class s452437940{
    public static void main(String[] args) throws IOException {
        // Declare variables to hold the input values
        long long int a, b, x;

        // Create a Scanner object to read input from standard input
        Scanner sc = new Scanner(System.in);

        // Read three long long integers from standard input
        a = sc.nextLong();
        b = sc.nextLong();
        x = sc.nextLong();

        // Calculate the number of multiples of x in the range [a, b]
        long long int s = (b / x - a / x);

        // If 'a' is a multiple of 'x', include it in the count
        if (a % x == 0) s++;

        // Print the result: the total count of multiples of x in the range
        System.out.println(s);

        // Close the Scanner object to release system resources
        sc.close();
    }
}
