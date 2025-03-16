
import java.util.*;  // Importing necessary classes
import java.io.*;
import java.math.*;

public class codeforces_682_B{
    public static void main(String[] args) throws IOException {
        // Define input functions
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        // Read the number of elements
        int n = Integer.parseInt(br.readLine());

        // Read the list of elements
        int[] l = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            l[i] = Integer.parseInt(st.nextToken());
        }

        // Initialize variables
        int f = 1;  // Flag variable
        Arrays.sort(l);  // Sort the list
        int c = 0;  // Counter variable

        // Iterate through the list to find the maximum number of unique elements
        for (int i = 0; i < n; i++) {
            if (l[i] > c) {
                c++;  // Increment the counter if the current element is greater than the counter
            }
        }

        // Print the result
        System.out.println(c + 1);  // Print the maximum number of unique elements
    }
}

Translate the above Java code to C++ and end with comment "