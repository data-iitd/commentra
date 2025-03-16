
// I/O
import java.io.*;
import java.util.*;

public class s211556675{
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in); // Create a new Scanner from System.in
        PrintWriter wtr = new PrintWriter(System.out); // Create a new PrintWriter for output

        // Read input values
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int K = sc.nextInt();

        // Find the maximum value among A, B, and C
        int ma = Math.max(A, Math.max(B, C));

        // Calculate the rest of the numbers that need to be multiplied by 2 to reach or exceed K
        int rest = 0;
        if (ma == A) {
            rest += B + C;
        } else if (ma == B) {
            rest += A + C;
        } else {
            rest += A + B;
        }

        // Calculate the final answer
        int answer = (int) Math.pow(ma, K) + rest;

        // Write the answer to the output
        wtr.println(answer);
        wtr.flush(); // Flush the buffer to write the output
    }
}

// 

