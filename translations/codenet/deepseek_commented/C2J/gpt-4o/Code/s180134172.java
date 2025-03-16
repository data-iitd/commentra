import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements (n) and the number of elements to sum (k)
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] p = new int[n];
        
        // Read n integers and store them in the array p
        for (int i = 0; i < n; i++) {
            p[i] = scanner.nextInt();
        }
        
        // Perform selection sort on the array p
        for (int i = 0; i < n; i++) {
            int l = i;
            for (int j = i + 1; j < n; j++) {
                if (p[j] < p[l]) {
                    l = j;
                }
            }
            if (l != i) {
                int m = p[i];
                p[i] = p[l];
                p[l] = m;
            }
        }
        
        // Sum the first k elements of the sorted array
        int o = 0;
        for (int i = 0; i < k; i++) {
            o += p[i];
        }
        
        // Print the sum of the first k elements
        System.out.println(o);
        
        scanner.close();
    }
}

// <END-OF-CODE>
