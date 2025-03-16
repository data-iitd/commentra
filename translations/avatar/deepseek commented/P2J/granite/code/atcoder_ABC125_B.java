

import java.util.Scanner;

public class atcoder_ABC125_B{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();  // Taking an integer input N, which represents the number of elements.
        int[] V = new int[N];  // Creating an integer array V with a length of N.
        int[] C = new int[N];  // Creating an integer array C with a length of N.

        // Entering a for loop that iterates N times.
        for (int i = 0; i < N; i++) {
            V[i] = scanner.nextInt();  // Taking an integer input and storing it in the i-th element of V.
            C[i] = scanner.nextInt();  // Taking an integer input and storing it in the i-th element of C.
        }

        int ans = 0;  // Initializing an integer ans set to 0.
        int X = 0;  // Initializing an integer X set to 0.
        int Y = 0;  // Initializing an integer Y set to 0.

        // Entering a for loop that iterates N times.
        for (int i = 0; i < N; i++) {
            // Checking if the difference between the i-th element of V and the i-th element of C is greater than 0.
            if (V[i] - C[i] > 0) {
                X = V[i];  // Assigning the i-th element of V to X.
                Y = C[i];  // Assigning the i-th element of C to Y.
                ans += X - Y;  // Adding the difference X - Y to ans.
            }
        }

        // Printing the value of ans.
        System.out.println(ans);
    }
}
