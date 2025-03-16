import java.util.*;
import java.io.*;

public class Main {
    // Define constants and global variables
    static final String[] march = {"M", "A", "R", "C", "H"};  // List of marching orders
    static int[] marchLis = new int[5];  // Array to store the count of each marching order
    static long ans = 0;  // Variable to store the answer

    // Function to read input as integer
    static int readInt() throws IOException {
        return Integer.parseInt(br.readLine().trim());
    }

    // Function to read input as list of strings
    static String[] readStringArray() throws IOException {
        return br.readLine().trim().split(" ");
    }

    // BufferedReader for fast input
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        // Read number of inputs
        int N = readInt();
        // Initialize marchLis with zeros
        Arrays.fill(marchLis, 0);
        
        // Iterate through each string and increment the count of the corresponding marching order in marchLis
        for (int i = 0; i < N; i++) {
            String[] s = readStringArray();
            String firstChar = s[0].toUpperCase();
            for (int j = 0; j < march.length; j++) {
                if (firstChar.equals(march[j])) {
                    marchLis[j]++;
                    break;
                }
            }
        }

        // Calculate the answer by finding the triple product of the counts of each marching order
        for (int i = 0; i < marchLis.length; i++) {
            for (int j = i + 1; j < marchLis.length; j++) {
                for (int k = j + 1; k < marchLis.length; k++) {
                    ans += (long) marchLis[i] * marchLis[j] * marchLis[k];
                }
            }
        }

        // Print the answer
        System.out.println(ans);
    }
}
// <END-OF-CODE>
