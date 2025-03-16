import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take two integers n and m as input
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        
        // Calculate the quotient and remainder
        int q = n / m;  // Number of items each group will have
        int r = n % m;  // Number of items that will be left over
        
        // Initialize an array a of length m with each element set to q
        int[] a = new int[m];
        for (int i = 0; i < m; i++) {
            a[i] = q;
        }
        
        // Distribute the remaining items
        for (int i = 0; i < r; i++) {
            a[i] += 1;  // Increment the corresponding element in the array a by 1
        }
        
        // Print the elements of the array a
        for (int i = 0; i < m; i++) {
            System.out.print(a[i] + " ");  // Print each element separated by a space
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
