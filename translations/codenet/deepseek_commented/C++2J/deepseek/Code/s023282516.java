import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();

        // Reverse the string S and all the words in divide
        String[] divide = {"dream", "dreamer", "erase", "eraser"};
        StringBuilder sb = new StringBuilder(S);
        S = sb.reverse().toString();
        for (int i = 0; i < 4; i++) {
            sb = new StringBuilder(divide[i]);
            divide[i] = sb.reverse().toString();
        }

        // Check from the start
        boolean can = true;
        for (int i = 0; i < S.length();) {
            boolean can2 = false; // Check if S can be divided by any of the words in divide
            for (int j = 0; j < 4; j++) {
                String d = divide[j];
                if (S.startsWith(d, i)) { // Check if S starts with d from index i
                    can2 = true;
                    i += d.length(); // Move i forward if division is possible
                }
            }
            if (!can2) { // If not divisible by any word, set can to false and break
                can = false;
                break;
            }
        }

        // Output the result
        System.out.println(can ? "YES" : "NO");
    }
}
