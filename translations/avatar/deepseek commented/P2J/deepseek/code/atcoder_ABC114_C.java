import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();  // Take an integer input N

        // Call the function `aaa` with the initial argument '0' and print the result
        System.out.println(aaa(0));
    }

    // Define a function named `aaa` that takes an argument `n`
    public static int aaa(int n) {
        // Check if the integer value of `n` is greater than N. If it is, return 0
        if (Integer.parseInt(String.valueOf(n)) > N) {
            return 0;
        }

        // Check if the digits of `n` are '7', '5', and '3'. If they are, set `ans` to 1; otherwise, set `ans` to 0
        int ans = 0;
        String strN = String.valueOf(n);
        if (strN.chars().allMatch(c -> c == '7' || c == '5' || c == '3')) {
            ans = 1;
        }

        // Iterate over the string '753' and recursively call the function `aaa` with `n` incremented by each digit
        for (char i : "753".toCharArray()) {
            ans += aaa(Integer.parseInt(strN + i));
        }

        // Return the value of `ans`
        return ans;
    }
}
