import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Initialize variables
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int R = scanner.nextInt();
        int S = scanner.nextInt();
        int P = scanner.nextInt();
        String T = scanner.next();

        // Initialize dictionary to store the count of each character
        Map<String, Integer> dict = new HashMap<>();
        dict.put("r", 0);
        dict.put("s", 0);
        dict.put("p", 0);

        // Initialize boolean arrays to represent the state of each character
        boolean[] s = new boolean[N];
        boolean[] r = new boolean[N];
        boolean[] p = new boolean[N];

        // Initialize all characters to be in the 'on' state
        for (int i = 0; i < N; i++) {
            s[i] = true;
        }

        // Iterate through each character in the input string
        for (int i = 0; i < T.length(); i++) {
            // Assign the current character to a variable
            String charAtI = T.substring(i, i + 1);

            // Check if we have reached the window size
            if (i >= K) {
                // If the current character is a substring of the previous K characters, toggle the state of the character
                if (charAtI.equals(T.substring(i - K, i + 1 - K))) {
                    switch (charAtI) {
                        case "s":
                            // Toggle the state of the character at index i%K
                            s[i % K] = !s[i % K];
                            continue;
                        case "r":
                            // Toggle the state of the character at index i%K
                            r[i % K] = !r[i % K];
                            continue;
                        case "p":
                            // Toggle the state of the character at index i%K
                            p[i % K] = !p[i % K];
                            continue;
                    }
                } else {
                    // If the current character is not a substring of the previous K characters, update the state of the characters accordingly
                    switch (charAtI) {
                        case "s":
                            // Set the state of the character at index i%K to 'on'
                            s[i % K] = true;
                            break;
                        case "r":
                            // Set the state of the character at index i%K to 'on'
                            r[i % K] = true;
                            break;
                        case "p":
                            // Set the state of the character at index i%K to 'on'
                            p[i % K] = true;
                            break;
                    }
                }
            }

            // Update the dictionary with the count of the current character
            dict.put(charAtI, dict.get(charAtI) + 1);
        }

        // Calculate and print the result
        int res = P * dict.get("r") + S * dict.get("p") + R * dict.get("s");
        System.out.println(res);
    }
}
// <END-OF-CODE>
