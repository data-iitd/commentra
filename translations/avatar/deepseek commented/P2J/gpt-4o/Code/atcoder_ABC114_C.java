import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    static int N;

    // Define a function named `aaa` that takes an argument `n`
    static int aaa(String n) {
        // Check if the integer value of `n` is greater than N. If it is, return 0
        if (Integer.parseInt(n) > N) {
            return 0;
        }

        // Check if the digits of `n` are '7', '5', and '3'
        Set<Character> digits = new HashSet<>();
        for (char c : n.toCharArray()) {
            digits.add(c);
        }
        int ans = (digits.equals(Set.of('7', '5', '3'))) ? 1 : 0;

        // Iterate over the string '753' and recursively call the function `aaa` with `n` incremented by each digit
        for (char i : "753".toCharArray()) {
            ans += aaa(n + i);
        }

        // Return the value of `ans`
        return ans;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();  // Take an integer input N
        // Call the function `aaa` with the initial argument '0' and print the result
        System.out.println(aaa("0"));
        scanner.close();
    }
}

// <END-OF-CODE>
