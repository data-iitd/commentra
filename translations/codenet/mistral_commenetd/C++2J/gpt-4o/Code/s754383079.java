import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read string a from standard input
        String a = scanner.next();
        int n = a.length(); // get the length of string a

        // Read string b from standard input
        String b = scanner.next();
        int m = b.length(); // get the length of string b

        int ans = Integer.MAX_VALUE; // initialize ans to a large value

        // Iterate through all possible substrings of string a that have the same length as string b
        for (int i = 0; i + m <= n; i++) {
            // Initialize sum to 0, it will be used to count the number of differences
            int sum = 0;

            // Iterate through each character in the substring of string a and compare it with the corresponding character in string b
            for (int j = 0; j < m; j++) {
                // If the characters are different, increment sum by 1
                if (a.charAt(i + j) != b.charAt(j)) {
                    sum++;
                }
            }

            // Update the minimum number of differences if a smaller number is found
            ans = Math.min(ans, sum);
        }

        // Print the minimum number of differences to standard output
        System.out.println(ans);

        // Close the scanner
        scanner.close();
    }
}

// <END-OF-CODE>
