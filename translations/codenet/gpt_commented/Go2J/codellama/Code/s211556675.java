
package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        int ma = max(A, B, C);
        int rest = 0;

        if (ma == A) {
            rest += B + C;
        } else if (ma == B) {
            rest += A + C;
        } else {
            rest += A + B;
        }

        for (int i = 0; i < K; i++) {
            ma *= 2;
        }

        System.out.println(ma + rest);
    }

    public static int max(int... nums) {
        int m = nums[0];
        for (int i = 1; i < nums.length; i++) {
            if (m < nums[i]) {
                m = nums[i];
            }
        }
        return m;
    }
}

