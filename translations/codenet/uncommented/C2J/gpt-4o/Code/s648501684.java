import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        long n = scanner.nextLong();
        long k = scanner.nextLong();
        long q = scanner.nextLong();
        
        int[] arr = new int[(int) n + 1]; // Create an array of size n + 1
        
        for (long i = 0; i <= n; i++) {
            arr[(int) i] = 0; // Initialize the array
        }
        
        for (long i = 0; i < q; i++) {
            long temp = scanner.nextLong();
            arr[(int) temp] += 1; // Increment the count for the given index
        }
        
        for (long i = 1; i <= n; i++) {
            if (arr[(int) i] > (q - k)) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
