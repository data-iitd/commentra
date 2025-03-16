import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    // Define a variable to hold the limit N
    static int N;

    // Define a recursive function 'aaa' that takes a string 'n'
    public static int aaa(String n) {
        // Check if the integer value of 'n' exceeds the limit N
        if (Integer.parseInt(n) > N) {
            return 0; // If it does, return 0 (base case)
        }

        // Check if the digits of 'n' are exactly '7', '5', and '3'
        Set<Character> digits = new HashSet<>();
        for (char c : n.toCharArray()) {
            digits.add(c);
        }
        int ans = (digits.equals(Set.of('7', '5', '3'))) ? 1 : 0;

        // Iterate over each character in the string '753'
        for (char i : "753".toCharArray()) {
            // Recursively call 'aaa' with the current number 'n' concatenated with 'i'
            ans += aaa(n + i);
        }

        // Return the accumulated answer
        return ans;
    }

    public static void main(String[] args) {
        // Read an integer input from the user
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        scanner.close();

        // Print the result of calling 'aaa' with the initial value '0'
        System.out.println(aaa("0"));
    }
}

// <END-OF-CODE>
