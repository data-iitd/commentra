

import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;

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
        for (int i = 0; i < N; i++) {
            Number_i[i] = i;
        }
        int[] Number_iMN = new int[N];
        for (int i = 0; i < N; i++) {
            Number_iMN[i] = i * M / N;
        }
        int[] Number_j = new int[M];
        for (int j = 0; j < M; j++) {
            Number_j[j] = j;
        }
        Set<Integer> Kaburi_j = new HashSet<>();
        for (int j : Number_iMN) {
            Kaburi_j.add(j);
        }
        Set<Integer> Kaburi_i = new HashSet<>();
        for (int j : Number_j) {
            if (Kaburi_j.contains(j)) {
                Kaburi_i.add(j * N / M);
            }
        }
        int counter = 0;
        int Flag = 0;
        int Kaburi_Size = Kaburi_i.size();
        while (counter <= Kaburi_Size - 1) {
            if (list_S[Kaburi_i.toArray()[counter].intValue()]!= list_T[Kaburi_j.toArray()[counter].intValue()]) {
                Flag = 1;
                break;
            }
            counter++;
        }
        if (Flag == 1) {
            System.out.println(-1);
        } else {
            System.out.println(N * M / gcd(N, M));
        }
    }

    public static int gcd(int a, int b) {
        while (b > 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
}

Translate the above Java code to C++ and end with comment "