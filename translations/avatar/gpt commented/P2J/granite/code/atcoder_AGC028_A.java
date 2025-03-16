
import java.util.Scanner;

public class atcoder_AGC028_A{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        String S = sc.next();
        String T = sc.next();
        char[] list_S = S.toCharArray();
        char[] list_T = T.toCharArray();
        int[] Number_i = new int[N];
        int[] Number_iMN = new int[N];
        int[] Number_j = new int[M];
        int[] Kaburi_i = new int[N];
        int[] Kaburi_j = new int[M];
        int Kaburi_Size = 0;
        int counter = 0;
        int Flag = 0;

        // Calculate the scaled indices based on the ratio of M to N
        for (int i = 0; i < N; i++) {
            Number_i[i] = i;
            Number_iMN[i] = (int) (i * M / N);
        }

        // Calculate the indices in the original range based on Kaburi_j
        for (int j = 0; j < M; j++) {
            Number_j[j] = j;
            Kaburi_j[j] = (int) (j * N / M);
        }

        // Find the common indices between the scaled Number_iMN and Number_j
        for (int j = 0; j < M; j++) {
            for (int i = 0; i < N; i++) {
                if (Number_iMN[i] == Number_j[j]) {
                    Kaburi_i[Kaburi_Size] = i;
                    Kaburi_Size++;
                    break;
                }
            }
        }

        // Check if the characters at the calculated indices in S and T match
        for (int counter = 0; counter <= Kaburi_Size - 1; counter++) {
            if (list_S[Kaburi_i[counter]] == list_T[Kaburi_j[counter]]) {
                continue;  // Characters match, continue checking
            } else {
                Flag = 1;  // Set flag if a mismatch is found
                break;  // Exit the loop on mismatch
            }
        }

        // Function to calculate the greatest common divisor (GCD) of two numbers
        public static int gcd(int a, int b) {
            while (b > 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }

        // Output the result based on the flag indicating if a mismatch was found
        if (Flag == 1) {
            System.out.println(-1);  // Print -1 if there was a mismatch
        } else {
            // Print the least common multiple (LCM) of N and M
            System.out.println((int) (N * M / gcd(N, M)));
        }
    }
}
