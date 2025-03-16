
import java.io.*;
import java.util.*;

public class s521372598{
    public static void main(String[] args) throws IOException {
        // Read the number of elements
        int n = getInt();
        // Read the integer array of size n
        int[] as = getIntArray(n);

        // Create a new array to store adjusted values
        int[] xs = new int[n];
        for (int i = 0; i < n; i++) {
            // Adjust each element by subtracting its index and adding 1
            xs[i] = as[i] - i + 1;
        }
        // Sort the adjusted values
        Arrays.sort(xs);

        // Find the median value from the sorted array
        int b = xs[n / 2];
        int ans = 0;
        // Calculate the total distance from each element to the median
        for (int x : xs) {
            ans += Math.abs(x - b);
        }
        // Output the result
        System.out.println(ans);
    }

    // getInt reads an integer from input
    public static int getInt() throws IOException {
        return Integer.parseInt(br.readLine());
    }

    // getIntArray reads an array of integers from input
    public static int[] getIntArray(int n) throws IOException {
        int[] arr = new int[n];
        String[] strs = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(strs[i]);
        }
        return arr;
    }

    // BufferedReader for input
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    // PrintWriter for output
    static PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
}

// -----------------------------------------

const int inf = (int) 1e9; // A constant representing infinity
// final int mod = (int) 1e9 + 7; // Uncomment if modular arithmetic is needed

public class s521372598{
    public static void main(String[] args) throws IOException {
        // Set a maximum buffer size for the scanner
        br.useDelimiter("\\s+");
        // Call the solve function to perform the main logic
        solve();
        // Flush the output buffer
        pw.flush();
    }

    // solve function computes the minimum total distance to a median value
    public static void solve() throws IOException {
        // Read the number of elements
        int n = getInt();
        // Read the integer array of size n
        int[] as = getIntArray(n);

        // Create a new array to store adjusted values
        int[] xs = new int[n];
        for (int i = 0; i < n; i++) {
            // Adjust each element by subtracting its index and adding 1
            xs[i] = as[i] - i + 1;
        }
        // Sort the adjusted values
        Arrays.sort(xs);

        // Find the median value from the sorted array
        int b = xs[n / 2];
        int ans = 0;
        // Calculate the total distance from each element to the median
        for (int x : xs) {
            ans += Math.abs(x - b);
        }
        // Output the result
        pw.println(ans);
    }

    // getInt reads an integer from input
    public static int getInt() throws IOException {
        return Integer.parseInt(br.readLine());
    }

    // getIntArray reads an array of integers from input
    public static int[] getIntArray(int n) throws IOException {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        return arr;
    }

    // BufferedReader for input
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    // PrintWriter for output
    static PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
}

// -----------------------------------------

const int inf = (int) 1e9; // A constant representing infinity
// final int mod = (int) 1e9 + 7; // Uncomment if modular arithmetic is needed

public class s521372598{
    public static void main(String[] args) throws IOException {
        // Set a maximum buffer size for the scanner
        br.useDelimiter("\\s+");
        // Call the solve function to perform the main logic
        solve();
        // Flush the output buffer
        pw.flush();
    }

    // solve function computes the minimum total distance to a median value
    public static void solve() throws IOException {
        // Read the number of elements
        int n = getInt();
        // Read the integer array of size n
        int[] as = getIntArray(n);

        // Create a new array to store adjusted values
        int[] xs = new int[n];
        for (int i = 0; i < n; i++) {
            // Adjust each element by subtracting its index and adding 1
            xs[i] = as[i] - i + 1;
        }
        // Sort the adjusted values
        Arrays.sort(xs);

        // Find the median value from the sorted array
        int b = xs[n / 2];
        int ans = 0;
        // Calculate the total distance from each element to the median
        for (int x : xs) {
            ans += Math.abs(x - b);
        }
        // Output the result
        pw.println(ans);
    }

    // getInt reads an integer from input
    public static int getInt() throws IOException {
        return Integer.parseInt(br.readLine());
    }

    // getIntArray reads an array of integers from input
    public static int[] getIntArray(int n) throws IOException {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        return arr;
    }

    // BufferedReader for input
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    // PrintWriter for output
    static PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
}

// -----------------------------------------

const int inf = (int) 1e9; // A constant representing infinity
// final int mod = (int) 1e9 + 7; // Uncomment if modular arithmetic is needed

public class s521372598{
    public static void main(String[] args) throws IOException {
        // Set a maximum buffer size for the scanner
        br.useDelimiter("\\s+");
        // Call the solve function to perform the main logic
        solve();
        // Flush the output buffer
        pw.flush();
    }

    // solve function computes the minimum total distance to a median value
    public static void solve() throws IOException {
        // Read the number of elements
        int n = getInt();
        // Read the integer array of size n
        int[] as = getIntArray(n);

        // Create a new array to store adjusted values
        int[] xs = new int[n];
        for (int i = 0; i < n; i++) {
            // Adjust each element by subtracting its index and adding 1
            xs[i] = as[i] - i + 1;
        }
        // Sort the adjusted values
        Arrays.sort(xs);

        // Find the median value from the sorted array
        int b = xs[n / 2];
        int ans = 0;
        // Calculate the total distance from each element to the median
        for (int x : xs) {
            ans += Math.abs(x - b);
        }
        // Output the result
        pw.println(ans);
    }

    // getInt reads an integer from input
    public static int getInt() throws IOException {
        return Integer.parseInt(br.readLine());
    }

    // getIntArray reads an array of integers from input
    public static int[] getIntArray(int n) throws IOException {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        return arr;
    }

    // BufferedReader for input
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    // PrintWriter for output
    static PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
}

// -----------------------------------------

const int inf = (int) 1e9; // A constant representing infinity
// final int mod = (int) 1e9 + 7; // Uncomment if modular arithmetic is needed

public class s521372598{
    public static void main(String[] args) throws IOException {
        // Set a maximum buffer size for the scanner
        br.useDelimiter("\\s+");
        // Call the solve function to perform the main logic
        solve();
        // Flush the output buffer
        pw.flush();
    }

    // solve function computes the minimum total distance to a median value
    public static void solve() throws IOException {
        // Read the number of elements
        int n = getInt();
        // Read the integer array of size n
        int[] as = getIntArray(n);

        // Create a new array to store adjusted values
        int[] xs = new int[n];
        for (int i = 0; i < n; i++) {
            // Adjust each element by subtracting its index and adding 1
            xs[i] = as[i] - i + 1;
        }
        // Sort the adjusted values
        Arrays.sort(xs);

        // Find the median value from the sorted array
        int b = xs[n / 2];
        int ans = 0;
        // Calculate the total distance from each element to the median
        for (int x : xs) {
            ans += Math.abs(x - b);
        }
        // Output the result
        pw.println(ans);
    }

    // getInt reads an integer from input
    public static int getInt() throws IOException {
        return Integer.parseInt(br.readLine());
    }

    // getIntArray reads an array of integers from input
    public static int[] getIntArray(int n) throws IOException {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }
        return arr;
    }

    // BufferedReader for input
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    // PrintWriter for output
    static PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
}

// -----------------------------------------

const int inf = (int) 1e9; // A constant representing infinity
// final