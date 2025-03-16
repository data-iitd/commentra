import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Read input values
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int K = sc.nextInt();
        
        // Determine the maximum value among A, B, and C
        int ma = Math.max(A, Math.max(B, C));
        
        // Calculate the sum of the other two values
        int rest = 0;
        if (ma == A) {
            rest += B + C;
        } else if (ma == B) {
            rest += A + C;
        } else {
            rest += A + B;
        }
        
        // Double the maximum value K times
        for (int i = 0; i < K; i++) {
            ma *= 2;
        }
        
        // Print the final result
        System.out.println(ma + rest);
        
        sc.close();
    }
}

// <END-OF-CODE>
