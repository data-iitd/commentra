import java.util.*;  // Importing necessary libraries
import java.lang.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Reading number of elements
        int N = Integer.parseInt(new BufferedReader(new InputStreamReader(System.in)).readLine());
        // Reading list of elements
        int[] A = new int[N];
        String[] A_temp = new String[N];
        for (int i = 0; i < N; i++) {
            A_temp[i] = new BufferedReader(new InputStreamReader(System.in)).readLine().trim();
        }
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(A_temp[i]);
        }

        // Removing consecutive duplicates from list A
        int j = 0;
        for (int i = 1; i < N; i++) {
            if (A[i]!= A[j]) {
                j++;
                A[j] = A[i];
            }
        }
        N = j + 1;

        // Initializing variables for main logic
        int i = 1;
        int ans = 0;

        // Main logic to find peaks
        while (i < N - 1) {
            if (A[i - 1] < A[i] && A[i] > A[i + 1] || A[i - 1] > A[i] && A[i] < A[i + 1]) {
                ans++;
                i++;  // Skip next element as it's already checked
            }
            i++;
        }

        // Output the total number of peaks found
        System.out.println(ans + 1);
    }
}

