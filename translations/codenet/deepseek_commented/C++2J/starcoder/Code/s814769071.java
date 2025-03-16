#pragma region
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Step 2: Read input values
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        sc.close();

        // Step 3: Calculate the maximum and minimum sums
        int mx = n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2;
        int mn = k * (k - 1) / 2;

        // Step 4: Initialize variables
        int res = 0;

        // Step 5: Loop through possible lengths
        for (int i = k; i <= n + 1; ++i)
        {
            // Update res, mx, and mn in each iteration
            res += mx - mn + 1;
            mx += n - i;
            mn += i;
        }

        // Step 6: Output the result
        System.out.println(res);
    }
}
#pragma endregion

