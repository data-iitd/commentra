import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the values of N and P from input
        int N = scanner.nextInt();
        int P = scanner.nextInt();
        
        // Read a list of integers from input
        int[] lis = new int[N];
        for (int i = 0; i < N; i++) {
            lis[i] = scanner.nextInt();
        }
        
        // Create a new list where each element is the remainder when divided by 2
        int[] ls = new int[N];
        for (int i = 0; i < N; i++) {
            ls[i] = lis[i] % 2;
        }
        
        // Count the number of 1s and 0s in the list
        int one = 0;
        int zero = 0;
        for (int i = 0; i < N; i++) {
            if (ls[i] == 1) {
                one++;
            } else {
                zero++;
            }
        }
        
        // Initialize variables to store the number of patterns
        long pattern_a = 0;
        long pattern_b = 0;
        
        // Calculate the number of patterns with `j` zeros using the combi function
        for (int j = 0; j <= zero; j++) {
            pattern_b += combi(zero, j);
        }
        
        // Initialize time to 0 for the while loop
        int time = 0;
        
        // Calculate the number of patterns with `time` ones, considering the parity with P
        while (time <= one) {
            if (time % 2 == P) {
                pattern_a += combi(one, time);
            }
            time++;
        }
        
        // Print the result as an integer by multiplying pattern_a and pattern_b
        System.out.println(pattern_a * pattern_b);
    }
    
    // Define a function to calculate the binomial coefficient
    public static long combi(int N, int K) {
        long a = 1;
        // Calculate the product part of the binomial coefficient
        for (int i = 0; i < K; i++) {
            a *= N - i;
        }
        // Calculate the division part of the binomial coefficient
        for (int j = 0; j < K; j++) {
            a /= j + 1;
        }
        return a;
    }
}
