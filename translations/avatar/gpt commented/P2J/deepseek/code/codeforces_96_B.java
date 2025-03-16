import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Initialize an empty list to store valid numbers
    static List<Long> l = new ArrayList<>();
    // Set a limit for the generated numbers
    static long limit = 10000000000L;

    // Recursive function to generate numbers composed of 4s and 7s
    static void gen(long number, int four, int seven) {
        // Base case: if the generated number exceeds the limit, stop recursion
        if (number > limit) {
            return;
        }
        // If the number is positive and the count of 4s equals the count of 7s, add it to the list
        if (number > 0 && four == seven) {
            l.add(number);
        }
        // Recursively generate the next number by adding a 4
        gen(number * 10 + 4, four + 1, seven);
        // Recursively generate the next number by adding a 7
        gen(number * 10 + 7, four, seven + 1);
    }

    // Main function to execute the number generation and find the answer
    public static void main(String[] args) {
        // Start the generation process with initial values
        gen(0, 0, 0);
        // Sort the list of generated numbers
        Collections.sort(l);
        // Read an integer input from the user
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int ans = 0;
        // Iterate through the sorted list to find the smallest number greater than or equal to n
        for (long val : l) {
            if (val >= n) {
                ans = (int) val;
                break;
            }
        }
        // Print the result
        System.out.println(ans);
        scanner.close();
    }
}
