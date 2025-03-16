
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int R = sc.nextInt();
        int S = sc.nextInt();
        int P = sc.nextInt();
        String T = sc.next();

        // Initialize the dictionary to keep track of the counts of 'r', 's', and 'p'
        int[] dict = new int[3];
        // Initialize a string to store the current character
        String char = "";
        // Initialize a boolean array to keep track of the availability of each choice for each player
        boolean[] s = new boolean[N];
        // Initialize all elements of the array to true
        for (int i = 0; i < N; i++) {
            s[i] = true;
        }
        // Create copies of the array for 'r', 'p'
        boolean[] r = new boolean[N];
        boolean[] p = new boolean[N];
        for (int i = 0; i < N; i++) {
            r[i] = s[i];
            p[i] = s[i];
        }

        // Iterate over each character in the string T
        for (int i = 0; i < T.length(); i++) {
            char = T.substring(i, i+1);
            // Check if the current index is greater than or equal to K
            if (i >= K) {
                // Check if the last K characters are the same as the current character
                if (char.equals(T.substring(i-K, i+1-K))) {
                    // Update the availability of the choice based on the current character
                    switch (char) {
                        case "s":
                            if (s[i%K]) {
                                s[i%K] = false;
                                continue;
                            } else {
                                s[i%K] = true;
                            }
                        case "r":
                            if (r[i%K]) {
                                r[i%K] = false;
                                continue;
                            } else {
                                r[i%K] = true;
                            }
                        case "p":
                            if (p[i%K]) {
                                p[i%K] = false;
                                continue;
                            } else {
                                p[i%K] = true;
                            }
                    }
                } else {
                    // Set the availability of the choice based on the current character
                    switch (char) {
                        case "s":
                            s[i%K] = true;
                        case "r":
                            r[i%K] = true;
                        case "p":
                            p[i%K] = true;
                    }
                }
            }
            // Update the counts in the dictionary based on the current character
            switch (char) {
                case "s":
                    dict[0] = dict[0] + 1;
                case "r":
                    dict[1] = dict[1] + 1;
                case "p":
                    dict[2] = dict[2] + 1;
            }
        }

        // Calculate the result by multiplying the counts of 'r', 's', and 'p' with their respective values (P, S, R)
        int res = P*dict[0] + S*dict[1] + R*dict[2];
        // Print the result
        System.out.println(res);
    }
}

