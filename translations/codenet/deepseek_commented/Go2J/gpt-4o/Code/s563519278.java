import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt(); // Step 1: Reading the number of elements (N)
        int[] v = new int[N]; // Step 3: Initializing the array
        
        for (int i = 0; i < N; i++) { // Step 4: Reading and counting elements
            int a = scanner.nextInt();
            v[a - 1]++;
        }
        
        // Step 5: Writing the results
        for (int e : v) {
            System.out.println(e);
        }
        
        scanner.close();
    }
}

// <END-OF-CODE>
