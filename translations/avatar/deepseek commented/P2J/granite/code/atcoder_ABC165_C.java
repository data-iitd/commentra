

import java.util.*;

class atcoder_ABC165_C {
    static int res = 0;  // Initialize the result variable to store the maximum score

    // Define the recursive function to generate sequences
    static void rec(List<Integer> A, int N, int M, int Q, int[] a, int[] b, int[] c, int[] d) {
        if (A.size() == N) {  // If the sequence length is equal to N
            int ans = 0;  // Initialize the answer for this sequence
            for (int i = 0; i < Q; i++) {  // Iterate over all constraints
                if (A.get(b[i] - 1) - A.get(a[i] - 1) == c[i]) {  // Check if the constraint is satisfied
                    ans += d[i];  // Add the value of the constraint to the answer
                }
            }
            res = Math.max(res, ans);  // Update the result with the maximum score
            return;
        }
        int last_max = A.size() == 0? 1 : A.get(A.size() - 1);  // Determine the starting point for the next number
        for (int i = last_max; i <= M; i++) {  // Generate the next number in the sequence
            A.add(i);
            rec(A, N, M, Q, a, b, c, d);
            A.remove(A.size() - 1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();  // Read the value of N
        int M = sc.nextInt();  // Read the value of M
        int Q = sc.nextInt();  // Read the value of Q
        int[] a = new int[Q];  // Read the list a
        int[] b = new int[Q];  // Read the list b
        int[] c = new int[Q];  // Read the list c
        int[] d = new int[Q];  // Read the list d
        for (int i = 0; i < Q; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
            c[i] = sc.nextInt();
            d[i] = sc.nextInt();
        }
        List<Integer> A = new ArrayList<>();  // Initialize the list A
        rec(A, N, M, Q, a, b, c, d);  // Call the rec function with the input values
        System.out.println(res);  // Print the result
        return;
    }
}

Translate the above Java code to C++ and end with comment "