import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read n and x
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        
        // Read the array a
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        
        // Sort the array
        Arrays.sort(a);
        
        int ans = 0;
        
        // Check if the smallest element is greater than x
        if (a[0] > x) {
            System.out.println(0);
            return;
        }
        
        // Process the array
        for (int i = 0; i < n; i++) {
            if (a[i] > x) {
                x = 0;
                break;
            }
            x -= a[i];
            ans++;
        }
        
        // Adjust the answer if there's remaining x
        if (x != 0) {
            ans--;
        }
        
        System.out.println(ans);
    }
}

// <END-OF-CODE>
