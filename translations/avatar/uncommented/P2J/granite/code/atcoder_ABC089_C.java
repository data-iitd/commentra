
import java.util.*;
import java.io.*;

class atcoder_ABC089_C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String[] S = new String[N];
        for (int i = 0; i < N; i++) {
            S[i] = sc.next();
        }
        int[] march = new int[5];
        for (int i = 0; i < N; i++) {
            char c = S[i].charAt(0);
            if (c == 'M') {
                march[0]++;
            } else if (c == 'A') {
                march[1]++;
            } else if (c == 'R') {
                march[2]++;
            } else if (c == 'C') {
                march[3]++;
            } else if (c == 'H') {
                march[4]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 4; j++) {
                for (int k = j + 1; k < 5; k++) {
                    ans += march[i] * march[j] * march[k];
                }
            }
        }
        System.out.println(ans);
    }
}

Translate the above Python code to C++ and end with comment "