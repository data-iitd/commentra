import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Taking an integer input `n` which represents the number of elements.
        int[] t = new int[n + 1];  // Initializing an array `t` with size `n + 1`.
        int[] a = new int[n + 1];  // Initializing an array `a` with size `n + 1`.
        ArrayList<Integer> ans = new ArrayList<>();  // Initializing an empty list `ans`.
        int[] cnt = new int[n + 1];  // Initializing an array `cnt` with zeros.

        // Filling the `t` and `a` arrays with input values.
        for (int i = 1; i <= n; i++) {
            t[i] = scanner.nextInt();
        }
        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();
        }

        // Counting the occurrences of each element in `a` and storing them in `cnt`.
        for (int i = 1; i <= n; i++) {
            cnt[a[i]]++;
        }

        // Iterating over the range from 1 to `n` to find cycles starting from each element.
        for (int i = 1; i <= n; i++) {
            if (t[i] == 1) {  // Checking if `t[i]` is 1, indicating the start of a potential cycle.
                ArrayList<Integer> crt = new ArrayList<>();  // Starting a list `crt`.
                int x = a[i];  // Initializing `x` with the value at index `i` in `a`.
                // Finding the cycle by following the `a` array until reaching an element whose count is not 1.
                while (cnt[x] == 1) {
                    crt.add(x);
                    x = a[x];
                }
                // Updating `ans` if the size of `crt` is greater than the size of `ans`.
                if (crt.size() > ans.size()) {
                    ans = (ArrayList<Integer>) crt.clone();
                }
            }
        }

        // Reversing `ans` to get the correct order of elements in the cycle.
        java.util.Collections.reverse(ans);

        // Printing the size of `ans` and the elements of `ans`.
        System.out.println(ans.size());
        for (int i = 0; i < ans.size(); i++) {
            if (i > 0) {
                System.out.print(" ");
            }
            System.out.print(ans.get(i));
        }
        System.out.println();
    }
}
