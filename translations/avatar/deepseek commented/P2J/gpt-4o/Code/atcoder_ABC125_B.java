import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int N = scanner.nextInt();  // Taking an integer input N, which represents the number of elements.
        int[] V = new int[N];  // Initializing an array V of size N.
        for (int i = 0; i < N; i++) {
            V[i] = scanner.nextInt();  // Taking the first line of space-separated integers and storing them in array V.
        }
        
        int[] C = new int[N];  // Initializing an array C of size N.
        for (int i = 0; i < N; i++) {
            C[i] = scanner.nextInt();  // Taking the second line of space-separated integers and storing them in array C.
        }
        
        int ans = 0;  // Initializing an integer ans set to 0.
        int X = 0;
        int Y = 0;
        
        // Entering a for loop that iterates N times.
        for (int i = 0; i < N; i++) {
            // Checking if the difference between the i-th element of V and the i-th element of C is greater than 0.
            if (V[i] - C[i] > 0) {
                X = V[i];  // Assigning the i-th element of V to X.
                Y = C[i];  // Assigning the i-th element of C to Y.
                ans += (X - Y);  // Adding the difference X - Y to ans.
            }
        }
        
        // Printing the sum of the differences.
        System.out.println(ans);
        
        scanner.close();
    }
}
// <END-OF-CODE>
