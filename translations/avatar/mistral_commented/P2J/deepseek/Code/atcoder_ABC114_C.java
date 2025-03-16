import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Read an integer value `N` from the user input

        System.out.println(aaa(0)); // Call the function with argument `0` and print the result
    }

    public static int aaa(int n) {
        if (n > N) { // Check if the integer `n` is greater than `N`
            return 0; // If it is, return 0
        }

        int ans = n == 7 || n == 5 || n == 3 ? 1 : 0; // Assign a value of 1 to `ans` if the integer `n` is equal to 7, 5, or 3; otherwise, assign it a value of 0

        for (char c : "753".toCharArray()) { // Iterate through each character in the string `'753'`
            ans += aaa(n * 10 + (c - '0')); // Call the function recursively with the argument `n * 10 + (c - '0')` and add the result to `ans`
        }

        return ans; // Return the value of `ans`
    }
}
