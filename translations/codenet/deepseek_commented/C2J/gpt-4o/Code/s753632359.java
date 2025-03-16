import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read two integers from standard input
        int N = scanner.nextInt();
        int D = scanner.nextInt();
        
        // Calculate the number of groups that can be formed
        int ans = N / (D * 2 + 1);
        int rem = N % (D * 2 + 1);
        
        // If there are remaining items, increment the number of groups
        if (rem != 0) {
            ans = ans + 1;
        }
        
        // Print the result to standard output
        System.out.println(ans);
        
        scanner.close();
    }
}

// <END-OF-CODE>
