import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class GCDCalculator {

    // Method to calculate the greatest common divisor (GCD) of two integers
    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    // Method to calculate the GCD of a list of integers
    public static int findGCD(List<Integer> numbers) {
        int result = numbers.get(0);
        for (int i = 1; i < numbers.size(); i++) {
            result = gcd(result, numbers.get(i));
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ask the user for the number of elements in the list
        int N = scanner.nextInt();
        List<Integer> A = new ArrayList<>();

        // Get a list of integers from the user input
        for (int i = 0; i < N; i++) {
            A.add(scanner.nextInt());
        }

        // Calculate the GCD of all integers in the list A
        int resultGCD = findGCD(A);

        // Print the result, which is the GCD of all the integers in the list A
        System.out.println(resultGCD);

        scanner.close();
    }
}

// <END-OF-CODE>
