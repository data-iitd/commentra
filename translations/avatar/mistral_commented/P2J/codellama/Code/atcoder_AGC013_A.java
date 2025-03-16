# Import necessary libraries
import java.util.*;
import java.io.*;
import java.math.*;

// Set input parameters and initialize variables
public static void input() {
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();
    A = new int[N];
    for (int i = 0; i < N; i++) {
        A[i] = sc.nextInt();
    }
    sc.close();
}

// Main logic
public static void main(String[] args) {
    input();
    A = Arrays.stream(A).distinct().toArray();
    N = A.length;
    i = 1;
    ans = 0;
    while (i < N - 1) {
        if (A[i - 1] < A[i] > A[i + 1] || A[i - 1] > A[i] < A[i + 1]) {
            ans++;
            i++;
        }
        i++;
    }
    System.out.println(ans + 1);
}

// End of code
