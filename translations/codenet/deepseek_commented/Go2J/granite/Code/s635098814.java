
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class s635098814{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        int[] count = new int[26];
        while ((line = br.readLine())!= null) {
            if (line.isEmpty()) {
                break;
            }
            char[] chars = line.toCharArray();
            for (char c : chars) {
                if (Character.isLetter(c)) {
                    count[Character.toLowerCase(c) - 'a']++;
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            System.out.println((char) (i + 'a') + " : " + count[i]);
        }
    }
}

Constants:
- The code defines constants for MOD and the number of alphabets, which can be used throughout the program.

Memoization:
- The code uses a memoization array to store counts of each letter.
- This is a common technique in competitive programming to optimize repeated calculations.

Loop and Conditionals:
- The main function reads input, processes it, and prints the results.
- This is a common structure for programs that need to handle multiple inputs.

