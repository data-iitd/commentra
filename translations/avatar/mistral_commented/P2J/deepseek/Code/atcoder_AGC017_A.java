import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the input values N and P from the user
        int N = scanner.nextInt();
        int P = scanner.nextInt();
        
        // Define a function to calculate the number of combinations of choosing K items from a set of N items
        long combi(int N, int K) {
            // Initialize the combination value to 1
            long a = 1;
            
            // Calculate the combination value by multiplying the number of choices from the set (N) to the current index (i)
            // and then dividing it by the current index (i+1) to account for the repetition of choices
            for (int i = 0; i < K; i++) {
                a *= (N - i);
                a /= (i + 1);
            }
            
            // Return the calculated combination value
            return a;
        }
        
        // Initialize the answer variable to 0
        long ans = 0;
        
        // Read the input values from the user and store them in a list
        int[] lis = new int[N];
        for (int i = 0; i < N; i++) {
            lis[i] = scanner.nextInt();
        }
        
        // Initialize an empty list to store the remainder of each input value when divided by 2
        int[] ls = new int[N];
        
        // Iterate through each value in the list and append its remainder to the list
        int one = 0, zero = 0;
        for (int a : lis) {
            ls[i] = a % 2;
            if (ls[i] == 1) {
                one++;
            } else {
                zero++;
            }
        }
        
        // Initialize two variables to store the pattern values
        long pattern_a = 0;
        long pattern_b = 0;
        
        // Calculate the value of pattern_b by summing up the combinations of choosing 0's from the list
        for (int j = 0; j <= zero; j++) {
            pattern_b += combi(zero, j);
        }
        
        // Calculate the value of pattern_a by summing up the combinations of choosing numbers from the list based on the value of P
        int time = 0;
        while (time <= one) {
            // Check if the current index (time) is a multiple of P
            if (time % P == 0) {
                // If yes, add the combination value to pattern_a
                pattern_a += combi(one, time);
            }
            
            // Increment the index for the next combination
            time++;
        }
        
        // Print the final answer as an integer
        System.out.println(pattern_a * pattern_b);
    }
}
