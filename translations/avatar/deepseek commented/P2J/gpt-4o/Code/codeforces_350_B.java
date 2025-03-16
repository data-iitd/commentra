import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();  // Taking an integer input `n` which represents the number of elements.
        int[] t = new int[n + 1];  // Array to hold the values of `t`.
        for (int i = 1; i <= n; i++) {
            t[i] = scanner.nextInt();  // Taking a list of integers `t` as input.
        }
        
        int[] a = new int[n + 1];  // Array to hold the values of `a`.
        for (int i = 1; i <= n; i++) {
            a[i] = scanner.nextInt();  // Taking another list of integers `a` as input.
        }
        
        List<Integer> ans = new ArrayList<>();  // Initializing an empty list `ans`.
        int[] cnt = new int[n + 1];  // Array to count occurrences of each element in `a`.

        // Counting the occurrences of each element in `a` and storing them in `cnt`.
        for (int i = 1; i <= n; i++) {
            cnt[a[i]]++;
        }

        // Iterating over the range from 1 to `n` to find cycles starting from each element.
        for (int i = 1; i <= n; i++) {
            if (t[i] == 1) {  // Checking if `t[i]` is 1, indicating the start of a potential cycle.
                List<Integer> crt = new ArrayList<>();  // Starting a list `crt` with `i`.
                crt.add(i);
                int x = a[i];  // Initializing `x` with the value at index `i` in `a`.
                
                // Finding the cycle by following the `a` list until reaching an element whose count is not 1.
                while (cnt[x] == 1) {
                    crt.add(x);
                    x = a[x];
                }
                
                // Updating `ans` if the length of `crt` is greater than the length of `ans`.
                if (crt.size() > ans.size()) {
                    ans = new ArrayList<>(crt);
                }
            }
        }

        // Reversing `ans` to get the correct order of elements in the cycle.
        Collections.reverse(ans);

        // Printing the length of `ans` and the elements of `ans`.
        System.out.println(ans.size());
        for (int num : ans) {
            System.out.print(num + " ");
        }
        System.out.println();  // For a new line after printing the elements.
        
        scanner.close();
    }
}
// <END-OF-CODE>
