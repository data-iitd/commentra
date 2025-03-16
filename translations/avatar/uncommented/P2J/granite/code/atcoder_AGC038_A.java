
import java.util.*;
class atcoder_AGC038_A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int H = sc.nextInt();
        int W = sc.nextInt();
        int A = sc.nextInt();
        int B = sc.nextInt();
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (i < B) {
                    if (j < A) {
                        System.out.print("0");
                    } else {
                        System.out.print("1");
                    }
                } else {
                    if (j < A) {
                        System.out.print("1");
                    } else {
                        System.out.print("0");
                    }
                }
            }
            System.out.println();
        }
    }
}
