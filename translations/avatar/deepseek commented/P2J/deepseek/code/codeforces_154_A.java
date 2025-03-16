import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();  // Taking input string s
        int n = Integer.parseInt(scanner.nextLine());  // Taking integer input n
        int ans = 0;  // Initializing the answer variable to 0

        // Loop runs n times
        for (int i = 0; i < n; i++) {
            String x = scanner.nextLine();  // Taking input for string x of length 2
            int a = 0, b = 0;  // Initializing counters a and b to 0

            // Iterating over each character in the string s
            for (char j : s.toCharArray()) {
                if (j == x.charAt(0)) {  // Checking if the character matches the first character of x
                    a++;  // Incrementing the count for the first character
                } else if (j == x.charAt(1)) {  // Checking if the character matches the second character of x
                    b++;  // Incrementing the count for the second character
                } else {  // If the character does not match any of the two
                    ans += Math.min(a, b);  // Adding the minimum of a and b to ans
                    a = 0; b = 0;  // Resetting the counters a and b to 0
                }
            }

            ans += Math.min(a, b);  // Adding the minimum of a and b to ans after the inner loop
        }

        System.out.println(ans);  // Printing the final answer
    }
}
