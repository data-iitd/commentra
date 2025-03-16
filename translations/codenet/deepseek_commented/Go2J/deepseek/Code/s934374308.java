import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int R = scanner.nextInt();
        int S = scanner.nextInt();
        int P = scanner.nextInt();
        String T = scanner.next();

        // Initialize the dictionary to keep track of the counts of 'r', 's', and 'p'
        int[] dict = new int[3];
        // Initialize a string to store the current character
        char charAt;
        // Initialize a boolean array to keep track of the availability of each choice for each player
        boolean[] s = new boolean[N];
        // Initialize all elements of the array to true
        for (int i = 0; i < N; i++) {
            s[i] = true;
        }
        // Create copies of the array for 'r', 'p'
        boolean[] r = s.clone();
        boolean[] p = s.clone();

        // Iterate over each character in the string T
        for (int i = 0; i < T.length(); i++) {
            charAt = T.charAt(i);
            // Check if the current index is greater than or equal to K
            if (i >= K) {
                // Check if the last K characters are the same as the current character
                if (charAt == T.charAt(i - K)) {
                    // Update the availability of the choice based on the current character
                    if (charAt == 's') {
                        if (s[i % K]) {
                            s[i % K] = false;
                            continue;
                        } else {
                            s[i % K] = true;
                        }
                    } else if (charAt == 'r') {
                        if (r[i % K]) {
                            r[i % K] = false;
                            continue;
                        } else {
                            r[i % K] = true;
                        }
                    } else if (charAt == 'p') {
                        if (p[i % K]) {
                            p[i % K] = false;
                            continue;
                        } else {
                            p[i % K] = true;
                        }
                    }
                } else {
                    // Set the availability of the choice based on the current character
                    if (charAt == 's') {
                        s[i % K] = true;
                    } else if (charAt == 'r') {
                        r[i % K] = true;
                    } else if (charAt == 'p') {
                        p[i % K] = true;
                    }
                }
            }
            // Update the counts in the dictionary based on the current character
            if (charAt == 's') {
                dict[0]++;
            } else if (charAt == 'r') {
                dict[1]++;
            } else if (charAt == 'p') {
                dict[2]++;
            }
        }

        // Calculate the result by multiplying the counts of 'r', 's', and 'p' with their respective values (P, S, R)
        int res = P * dict[1] + S * dict[2] + R * dict[0];
        // Print the result
        System.out.println(res);
    }
}
