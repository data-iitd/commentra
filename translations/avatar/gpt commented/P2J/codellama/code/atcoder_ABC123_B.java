
import java.util.Scanner;
import java.lang.Math;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] menu = new int[5][2];
        for (int i = 0; i < 5; i++) {
            String m = sc.next();
            int e = Integer.parseInt(m.substring(m.length() - 1));
            if (e == 0) {
                e = 10;
            }
            menu[i][0] = Integer.parseInt(m);
            menu[i][1] = e;
        }
        sc.close();
        int ans = 0;
        for (int i = 1; i < 5; i++) {
            ans += (int) Math.ceil((double) menu[i][0] / 10) * 10;
        }
        System.out.println(ans + menu[0][0]);
    }
}

