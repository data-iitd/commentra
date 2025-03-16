import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] a = new int[n];
        
        // Read the array (though it's not used)
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        
        // Variable unused warning avoidance
        a[0] = 0;

        int sum = k;
        int ans = 1;
        while (sum < n) {
            sum = sum - 1 + k;
            ans++;
        }
        System.out.println(ans);
        
        sc.close();
    }
}

// <END-OF-CODE>
