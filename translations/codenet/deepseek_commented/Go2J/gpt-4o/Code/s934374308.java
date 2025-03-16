import java.util.HashMap;
import java.util.Map;
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
        Map<String, Integer> dict = new HashMap<>();
        dict.put("r", 0);
        dict.put("s", 0);
        dict.put("p", 0);
        
        // Initialize a boolean array to keep track of the availability of each choice for each player
        boolean[] s = new boolean[N];
        boolean[] r = new boolean[N];
        boolean[] p = new boolean[N];
        
        // Initialize all elements of the array to true
        for (int i = 0; i < N; i++) {
            s[i] = true;
            r[i] = true;
            p[i] = true;
        }

        // Iterate over each character in the string T
        for (int i = 0; i < T.length(); i++) {
            String charAtI = String.valueOf(T.charAt(i));
            // Check if the current index is greater than or equal to K
            if (i >= K) {
                // Check if the last K characters are the same as the current character
                if (charAtI.equals(String.valueOf(T.charAt(i - K)))) {
                    // Update the availability of the choice based on the current character
                    switch (charAtI) {
                        case "s":
                            if (s[i % K]) {
                                s[i % K] = false;
                                continue;
                            } else {
                                s[i % K] = true;
                            }
                            break;
                        case "r":
                            if (r[i % K]) {
                                r[i % K] = false;
                                continue;
                            } else {
                                r[i % K] = true;
                            }
                            break;
                        case "p":
                            if (p[i % K]) {
                                p[i % K] = false;
                                continue;
                            } else {
                                p[i % K] = true;
                            }
                            break;
                    }
                } else {
                    // Set the availability of the choice based on the current character
                    switch (charAtI) {
                        case "s":
                            s[i % K] = true;
                            break;
                        case "r":
                            r[i % K] = true;
                            break;
                        case "p":
                            p[i % K] = true;
                            break;
                    }
                }
            }
            // Update the counts in the dictionary based on the current character
            dict.put(charAtI, dict.get(charAtI) + 1);
        }

        // Calculate the result by multiplying the counts of 'r', 's', and 'p' with their respective values (P, S, R)
        int res = P * dict.get("r") + S * dict.get("p") + R * dict.get("s");
        // Print the result
        System.out.println(res);
    }
}

// <END-OF-CODE>
