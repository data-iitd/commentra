
import java.util.*;
import java.io.*;

public class s765257696{
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()); // Comment 1: Reads the size of the array p from standard input
        int[] p = new int[n];
        String[] input = br.readLine().split(" "); // Comment 2: Reads the array p from standard input
        for (int i = 0; i < n; i++) p[i] = Integer.parseInt(input[i]); // Comment 3: Populates the array p with n integers from standard input
        int ans = 0; // Comment 4: Initializes the variable ans to 0
        for (int i = 0; i < n - 2; i++) { // Comment 5: Loops through the array p
            if (p[i] > p[i+1] && p[i+1] > p[i+2]) ans++; // Comment 6: Checks for a peak and increments ans
            if (p[i] < p[i+1] && p[i+1] < p[i+2]) ans++; // Comment 7: Checks for a valley and increments ans
        }
        System.out.println(ans); // Comment 8: Prints the final value of ans to standard output
    }
}

Translate the above Java code to Python and end with comment "