import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read input values for N and K
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        scanner.nextLine(); // Consume the newline
        String S = scanner.nextLine();
        
        // Initialize a flag to determine if we can use a shortcut for output
        boolean aaaa = false;

        // Check if K is large enough or if 2^K is greater than or equal to N
        if (K >= 15) {
            aaaa = true;
        } else if (Math.pow(2, K) >= N) {
            aaaa = true;
        }

        // If the shortcut condition is met, print the minimum character repeated N times and exit
        if (aaaa) {
            char minChar = getMinChar(S);
            System.out.println(String.valueOf(minChar).repeat(N));
            return;
        }

        // Get the lexicographically smallest rotation of the string
        S = getLastDict(S, N);

        // If K is 1, simply print the smallest rotation
        if (K == 1) {
            System.out.println(S);
        } else {
            int count = 0;
            // Count how many times the first character appears consecutively
            for (char c : S.toCharArray()) {
                if (c == S.charAt(0)) {
                    count++;
                } else {
                    break;
                }
            }

            // Check if the repeated character can fill the string of length N
            if (count * (int) Math.pow(2, K - 1) >= N) {
                System.out.println(String.valueOf(S.charAt(0)).repeat(N));
            } else {
                // Construct the output string based on the count and the original string
                StringBuilder result = new StringBuilder();
                result.append(String.valueOf(S.charAt(0)).repeat(count * ((int) Math.pow(2, K - 1) - 1)));
                result.append(S);
                // Print the first N characters of the constructed string
                System.out.println(result.substring(0, N));
            }
        }
    }

    // Function to get the minimum character in the string
    private static char getMinChar(String s) {
        char minChar = s.charAt(0);
        for (char c : s.toCharArray()) {
            if (c < minChar) {
                minChar = c;
            }
        }
        return minChar;
    }

    // Function to get the lexicographically smallest rotation of the string
    private static String getLastDict(String sStr, int N) {
        String U = sStr + new StringBuilder(sStr).reverse().toString();
        char c = getMinChar(sStr);
        int p = U.indexOf(c);
        int minIndex = p;
        p++;

        // Iterate through the doubled string to find the smallest rotation
        while (p <= N) {
            if (U.charAt(p) == c) {
                // Compare the current rotation with the previously found minimum
                if (checkNormalDict(U, minIndex, p, N)) {
                    minIndex = p;
                }
            }
            p++;
        }

        // Return the smallest rotation of length N
        return U.substring(minIndex, minIndex + N);
    }

    // Function to compare two rotations of the string
    private static boolean checkNormalDict(String u, int pointer1, int pointer2, int N) {
        for (int i = 0; i < N; i++) {
            if (u.charAt(pointer1 + i) > u.charAt(pointer2 + i)) {
                return true;
            } else if (u.charAt(pointer1 + i) < u.charAt(pointer2 + i)) {
                return false;
            }
        }
        return false;
    }
}
// <END-OF-CODE>
