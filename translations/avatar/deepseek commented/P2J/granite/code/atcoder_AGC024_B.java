

import java.util.Scanner;

public class atcoder_AGC024_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        // Read the number of elements N
        int N = scanner.nextInt();
        // Read the list of integers P
        int[] P = new int[N];
        for (int i = 0; i < N; i++) {
            P[i] = scanner.nextInt();
        }
        // Call the editorial function with N and P as arguments
        editorial(N, P);
    }

    public static void editorial(int N, int[] P) {
        // If there is only one element, print 0 and return
        if (N == 1) {
            System.out.println(0);
            return;
        }
        // Initialize an array to store positions of elements in P
        int[] a = new int[N + 1];
        // Populate the array with positions of elements in P
        for (int i = 0; i < N; i++) {
            a[P[i]] = i;
        }
        // Initialize temporary and maximum length variables
        int tmp = 1;
        int maxLen = 1;
        // Iterate through the positions to find the maximum length of consecutive increasing elements
        for (int i = 1; i < N; i++) {
            if (a[i] < a[i + 1]) {
                tmp += 1;
                maxLen = Math.max(maxLen, tmp);
            } else {
                tmp = 1;
            }
        }
        // Calculate the answer as N - max_len
        int ans = N - maxLen;
        // Print the answer
        System.out.println(ans);
    }

    public static void WA(int N, int[] P) {
        int tmp = 0;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (i == 0 || P[i - 1] + 1 == P[i]) {
                tmp += 1;
            } else {
                ans = Math.max(ans, tmp);
                tmp = 1;
            }
        }
        System.out.println(N - ans);
    }
}

Translate the above Java code to C++ and end with comment "