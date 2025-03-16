import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read n and m
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Read the list l
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }
        
        // Create the list l2
        int[] l2 = new int[n];
        for (int i = 0; i < n; i++) {
            if (l[i] % m == 0) {
                l2[i] = l[i] / m;
            } else {
                l2[i] = l[i] / m + 1;
            }
        }
        
        // Find the maximum value in l2
        int mx = l2[0];
        for (int i = 1; i < n; i++) {
            if (l2[i] > mx) {
                mx = l2[i];
            }
        }
        
        // Find the index of the first occurrence of mx
        int ind = 0;
        for (int i = 0; i < n; i++) {
            if (l2[i] == mx) {
                ind = i;
                break;
            }
        }
        
        // Print the index (1-based)
        System.out.println(ind + 1);
        
        scanner.close();
    }
}
// <END-OF-CODE>
