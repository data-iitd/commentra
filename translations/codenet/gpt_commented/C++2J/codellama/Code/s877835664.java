
import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] A = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            A[i] = sc.nextInt();
        }

        int cur = 1;
        int[] dic = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            dic[i] = -1;
        }
        boolean flg = false;
        for (int i = 1; i <= K; i++) {
            if (dic[cur] < 0 || flg) {
                dic[cur] = i;
                cur = A[cur];
            } else if (!flg) {
                int tmp = K - (dic[cur] - 1);
                tmp %= i - dic[cur];
                i = K - tmp;
                flg = true;
            }
        }
        System.out.println(cur);
    }
}

