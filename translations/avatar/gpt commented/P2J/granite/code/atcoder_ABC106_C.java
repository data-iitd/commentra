
import java.util.*;
import java.io.*;

class atcoder_ABC106_C {
    public static void main(String[] args) throws Exception {
        // Reading a string from input
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        // Reading an integer k from input
        int k = Integer.parseInt(br.readLine());
        int l = 0;  // Initialize a counter for leading '1's

        // Count the number of leading '1's in the string
        for (char c : s.toCharArray()) {
            if (c!= '1') {
                break;
            }
            l++;
        }

        // If the count of leading '1's is greater than or equal to k, return 1
        if (l >= k) {
            System.out.println(1);
        } else {
            // Otherwise, return the character at position l in the string
            System.out.println(s.charAt(l));
        }
    }
}

// End of code