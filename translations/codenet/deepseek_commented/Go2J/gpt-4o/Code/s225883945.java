import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] a = new int[n];
        
        // Set the first element of `a` to 0 to avoid unused variable error.
        a[0] = 0;

        int sum = k;
        int ans = 1;

        // Loop to increment `sum` and `ans` until `sum` is less than `n`.
        while (sum < n) {
            sum = sum - 1 + k;
            ans++;
        }
        
        System.out.println(ans);
        sc.close();
    }
}

// <END-OF-CODE>
