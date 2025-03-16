

import java.util.*;
// Import the Scanner class from the java.util package

public class atcoder_AGC027_A{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Create a Scanner object to read input from the console

        int n = sc.nextInt();
        int x = sc.nextInt();
        // Read the values of n and x from input

        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(sc.nextInt());
        }
        // Read the list `a` from input and store it in an ArrayList

        Collections.sort(a);
        // Sort the ArrayList `a` in ascending order

        int ans = 0;
        if (a.get(0) > x) {
            System.out.println(0);
            return;
        }
        // Check if the smallest element in the sorted list `a` is greater than `x`. If so, print 0 and return.

        for (int i = 0; i < n; i++) {
            if (a.get(i) > x) {
                x = 0;
                break;
            }
            x -= a.get(i);
            ans++;
        }
        // Iterate through each element in the sorted list `a`, subtracting each element from `x` and incrementing `ans` until `x` becomes 0 or an element greater than `x` is encountered.

        if (x!= 0) {
            ans--;
        }
        // If `x` is not 0 after the loop, decrement `ans` by 1.

        System.out.println(ans);
        // Print the value of `ans`.
    }
}
