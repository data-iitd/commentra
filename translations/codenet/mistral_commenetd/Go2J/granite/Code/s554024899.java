

import java.util.*;

public class s554024899{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        int xt = 0;
        int yt = 0;
        int[][] a = {{1, 3, 5, 7, 8, 10, 12}, {4, 6, 9, 11}, {2}};
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a[i].length; j++) {
                if (a[i][j] == x) {
                    xt = i;
                }
                if (a[i][j] == y) {
                    yt = i;
                }
            }
        }
        if (xt == yt) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}

// Translate the above Java code to C++ and end with comment "