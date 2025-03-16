import java.util.*;
import java.io.*;

// Main class for the application.
public class Main {
    // I/O functions for reading input efficiently.
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter writer = new PrintWriter(System.out);

    // Function to read an integer from input.
    static int readInt() throws IOException {
        return Integer.parseInt(reader.readLine().trim());
    }

    // Function to read an array of integers from input.
    static int[] readIntArray(int n) throws IOException {
        int[] array = new int[n];
        StringTokenizer st = new StringTokenizer(reader.readLine());
        for (int i = 0; i < n; i++) {
            array[i] = Integer.parseInt(st.nextToken());
        }
        return array;
    }

    // Main function to read input, sort the array, and calculate the answer.
    public static void main(String[] args) throws IOException {
        int n = readInt();
        int x = readInt();
        int[] A = readIntArray(n);

        Arrays.sort(A);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (x >= A[i]) {
                ans++;
                x -= A[i];
            } else {
                break;
            }
        }
        if (ans == n && x > 0) {
            ans--;
        }
        writer.println(ans);
        writer.flush();
    }
}
// <END-OF-CODE>
