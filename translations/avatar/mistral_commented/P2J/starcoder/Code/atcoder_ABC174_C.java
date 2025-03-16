

import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int t = 0;
        for (int i = 1; i <= k; i++) {
            t = (t % k * 10 + 7) % k;
            if (t == 0) {
                System.out.println(i);
                break;
            }
        }
        if (t!= 0) {
            System.out.println(-1);
        }
    }
}

