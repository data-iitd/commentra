import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Initialize variables
        long a, b;

        // Read input values from standard input
        Scanner sc = new Scanner(System.in);
        a = sc.nextLong();
        b = sc.nextLong();

        // Calculate the maximum value among a+b, a-b, and a*b
        long result = Math.max(a+b, Math.max(a-b, a*b));

        // Output the result to standard output
        System.out.println(result);
    }
}

