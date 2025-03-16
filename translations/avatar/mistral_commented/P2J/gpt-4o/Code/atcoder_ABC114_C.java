import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    static int N;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt(); // User inputs an integer value `N`
        System.out.println(aaa("0")); // Call the function with argument "0" and print the result
    }

    public static int aaa(String n) { // Function definition for function `aaa` that takes a String argument `n`
        int num = Integer.parseInt(n); // Convert the string `n` to an integer
        if (num > N) { // Check if the input integer `n` is greater than `N`
            return 0; // If it is, return 0
        }

        Set<Character> set = new HashSet<>(); // Create a set to store characters
        for (char c : n.toCharArray()) { // Iterate through each character in the string `n`
            set.add(c); // Add each character to the set
        }

        int ans = set.equals(Set.of('7', '5', '3')) ? 1 : 0; // Assign a value of 1 to `ans` if the set of characters is equal to the set {'7', '5', '3'}; otherwise, assign it a value of 0

        for (char i : "753".toCharArray()) { // Iterate through each character in the string "753"
            ans += aaa(n + i); // Call the function recursively with the argument `n + i` and add the result to `ans`
        }

        return ans; // Return the value of `ans`
    }
}
