
import java.util.*;

public class s554024899{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        int[] a1 = {1, 3, 5, 7, 8, 10, 12};
        int[] a2 = {4, 6, 9, 11};
        int[] a3 = {2};
        int xt = 0, yt = 0;
        for (int i = 0; i < a1.length; i++) {
            if (x == a1[i]) {
                xt = 0;
            }
            if (y == a1[i]) {
                yt = 0;
            }
        }
        for (int i = 0; i < a2.length; i++) {
            if (x == a2[i]) {
                xt = 1;
            }
            if (y == a2[i]) {
                yt = 1;
            }
        }
        for (int i = 0; i < a3.length; i++) {
            if (x == a3[i]) {
                xt = 2;
            }
            if (y == a3[i]) {
                yt = 2;
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