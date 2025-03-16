
// +build ignore
import java.io.*;
import java.util.*;

public class s731620136{
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String S = sc.next();

        // Handle case where there are no elements
        if (N == 0) {
            System.out.println(0);
            return;
        }

        // If there are fewer than 4 elements, output 0
        if (N < 4) {
            System.out.println(0);
            return;
        }

        // Count occurrences of each color
        int nr = 0, nb = 0, ng = 0;
        for (char c : S.toCharArray()) {
            if (c == 'R') nr++;
            if (c == 'B') nb++;
            if (c == 'G') ng++;
        }

        int same = 0; // Counter for same color combinations

        // Iterate through possible combinations of indices
        for (int a = 1; a < N; a++) {
            int i = 0, j = a, k = 2 * a;
            if (k >= N) break; // Exit if index exceeds string length
            while (k < N) {
                // Check if the colors at the indices are different
                if (S.charAt(i)!= S.charAt(j) && S.charAt(i)!= S.charAt(k) && S.charAt(j)!= S.charAt(k)) {
                    same++; // Increment same color combination counter
                }
                i++; // Move to the next index
                j++;
                k++;
            }
        }

        // Calculate total combinations of different colors
        int tot = nr * nb * ng;

        // Output the result by subtracting same combinations from total
        System.out.println(tot - same);
    }
}

// Translate the above Java code to C++ and end with comment "