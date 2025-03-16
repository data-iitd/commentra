import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Read a string from the standard input
        Scanner sc = new Scanner(System.in);
        String S = sc.next();

        // Reverse the string S
        StringBuilder sb = new StringBuilder(S);
        sb.reverse();
        String S2 = sb.toString();

        // Initialize an array of strings called divide
        String[] divide = new String[4];
        divide[0] = "dream";
        divide[1] = "dreamer";
        divide[2] = "erase";
        divide[3] = "eraser";

        // Reverse each string in the divide array
        for (int i = 0; i < 4; ++i) {
            StringBuilder sb2 = new StringBuilder(divide[i]);
            sb2.reverse();
            divide[i] = sb2.toString();
        }

        // Initialize a boolean variable called can to true
        boolean can = true;

        // Iterate through each character in the string S
        for (int i = 0; i < S2.length();) {
            // Initialize a boolean variable called can2 to false
            boolean can2 = false;

            // Iterate through each string in the divide array
            for (int j = 0; j < 4; ++j) {
                // Get the string d from the divide array
                String d = divide[j];

                // Check if the substring of S starting from the current index i and having the same size as d is equal to d
                if (S2.substring(i, i + d.length()).equals(d)) {
                    // If the substring is equal to d, set can2 to true and move the index i to the end of the matched substring
                    can2 = true;
                    i += d.length();
                }
            }

            // If can2 is false, it means the current substring of S cannot be divided by any string in the divide array, so set can to false and break the loop
            if (!can2) {
                can = false;
                break;
            }
        }

        // Output "YES" if can is true, otherwise output "NO"
        if (can) System.out.println("YES");
        else System.out.println("NO");
    }
}
