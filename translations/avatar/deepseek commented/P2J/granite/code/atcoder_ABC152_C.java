

import java.util.*;

public class atcoder_ABC152_C{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] n = new int[N];
        for (int i = 0; i < N; i++) {
            n[i] = sc.nextInt();
        }
        int a = 1;
        int pos = 0;
        for (int i = 1; i < N; i++) {
            if (n[pos] > n[i]) {
                a += 1;
                pos = i;
            }
        }
        System.out.println(a);
    }
}



Translate the above Python code to C++ and end with comment "