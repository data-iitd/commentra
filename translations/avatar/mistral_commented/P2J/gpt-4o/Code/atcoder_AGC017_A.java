import java.util.Scanner;

public class Combinations {
    
    // Function to calculate the number of combinations of choosing K items from a set of N items
    public static long combi(int N, int K) {
        long a = 1;
        
        // Calculate the combination value
        for (int i = 0; i < K; i++) {
            a *= (N - i);
            a /= (i + 1);
        }
        
        return a;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the input values N and P from the user
        int N = scanner.nextInt();
        int P = scanner.nextInt();
        
        // Initialize the answer variable to 0
        long ans = 0;
        
        // Read the input values from the user and store them in an array
        int[] lis = new int[N];
        for (int i = 0; i < N; i++) {
            lis[i] = scanner.nextInt();
        }
        
        // Initialize counters for 1's and 0's
        int one = 0;
        int zero = 0;
        
        // Calculate the number of 1's and 0's in the list
        for (int a : lis) {
            if (a % 2 == 0) {
                zero++;
            } else {
                one++;
            }
        }
        
        // Initialize two variables to store the pattern values
        long pattern_a = 0;
        long pattern_b = 0;
        
        // Calculate the value of pattern_b
        for (int j = 0; j <= zero; j++) {
            pattern_b += combi(zero, j);
        }
        
        // Calculate the value of pattern_a
        for (int time = 0; time <= one; time++) {
            // Check if the current index (time) is a multiple of P
            if (time % P == 0) {
                pattern_a += combi(one, time);
            }
        }
        
        // Print the final answer as an integer
        System.out.println(pattern_a * pattern_b);
        
        scanner.close();
    }
}

// <END-OF-CODE>
