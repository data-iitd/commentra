
// Importing sys and defining a custom input function
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Reading input from stdin
        Scanner sc = new Scanner(System.in);

        // Reading input values: N, A, and B
        int N = sc.nextInt();
        int A = sc.nextInt();
        int B = sc.nextInt();

        // Initializing the answer variable to 0
        int ans = 0;

        // Calculating the number of repetitions
        int rep = N / (A + B);

        // Adding the number of blocks that can be fully covered by A and B in one repetition
        ans += rep * A;

        // Calculating the remaining number of blocks
        int res = N - rep * (A + B);

        // Adding the number of blocks that can be covered by A in the remaining blocks
        ans += Math.min(res, A);

        // Printing the final answer
        System.out.println(ans);
    }
}

