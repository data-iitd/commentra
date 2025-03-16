import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Read the number of elements in the array
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        // Read the elements of the array
        String[] a = br.readLine().split(" ");
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(a[i]);
        }

        // Initialize some variables
        int[] dl = new int[n]; // An array to store the difference between the index and the index of the element in the array
        int ans = 0; // The answer
        List<Ban> bans = new ArrayList<Ban>(); // A vector to store some information about the intervals

        // Calculate the differences between the indices and the elements in the array
        for (int i = 0; i < n; i++) {
            if (arr[i] > i) { // Check if the element is out of its position
                System.out.println(-1); // Output -1 if the element is out of its position
                return;
            }
            dl[i] = i - arr[i]; // Calculate the difference between the index and the element
        }

        // Calculate the answer and store some information about the intervals in a vector
        for (int i = 0; i < n; i++) {
            int r = i; // Initialize a variable to store the right endpoint of the current interval
            while (r + 1 < n && arr[r] + 1 == arr[r + 1]) { // Check if there is a longer interval with the same value
                r++; // Move to the next index if there is
            }
            ans += arr[r]; // Add the value of the right endpoint of the current interval to the answer
            i = r; // Update the index to be the right endpoint of the current interval
            bans.add(new Ban(r - arr[r], r, r - arr[r])); // Store some information about the current interval in the vector
        }

        // Initialize the segment tree using the differences between the indices and the elements in the array
        Sp.init(dl);

        // Check some conditions and calculate the answer if possible
        for (Ban t : bans) {
            if (Sp.get(t.l, t.r) > t.val) { // Check if the minimum value in the segment of the segment tree is greater than the value of the interval
                System.out.println(-1); // Output -1 if the condition is not satisfied
                return;
            }
        }

        // Output the answer
        System.out.println(ans);
    }
}

class Sp {
    public static final int LIM = 20; // Maximum depth of the segment tree
    public static final int N = 2e5 + 7; // Maximum number of elements in the array

    // An array to store the minimum value in each segment of the segment tree
    public static int[] mn = new int[LIM][N];

    // A function to initialize the segment tree
    public static void init(int[] a) {
        int n = a.length;
        // Initialize the first level of the segment tree
        for (int i = 0; i < n; i++) {
            mn[0][i] = a[i]; // Store the value of the element at index i in the first level of the segment tree
        }
        // Build the segment tree recursively
        for (int i = 0; i + 1 < LIM; i++) {
            for (int j = 0; j + (1 << (i + 1)) <= n; j++) {
                mn[i + 1][j] = Math.max(mn[i][j], mn[i][j + (1 << i)]); // Find the minimum value in the current segment and store it in the next level of the segment tree
            }
        }
        // Calculate the power of 2 up to the maximum depth of the segment tree
        pw[1] = 0;
        for (int i = 2; i < N; i++) {
            pw[i] = pw[i / 2] + 1; // Calculate the power of 2 for each index
        }
    }

    // A function to get the minimum value in a segment of the segment tree
    public static int get(int l, int r) {
        r++; // Adjust the index of the right endpoint of the segment to be one more than the actual index
        int p = pw[r - l]; // Calculate the depth of the segment tree for the given segment
        return Math.min(mn[p][l], mn[p][r - (1 << p)]); // Return the minimum value in the given segment
    }

    // A function to calculate the power of 2
    public static int[] pw = new int[N];
}

class Ban {
    int l; // left endpoint of the interval
    int r; // right endpoint of the interval
    int val; // value of the interval

    Ban() {}

    Ban(int l_, int r_, int val_) {
        l = l_;
        r = r_;
        val = val_;
    }
}

