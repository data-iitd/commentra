
import java.util.*;
import java.io.*;

class atcoder_ABC123_C {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[5];
        for (int i = 0; i < 5; i++) {
            a[i] = sc.nextInt();
        }
        Arrays.sort(a);
        System.out.println((int)Math.ceil((double)n / a[0]) + 4);
    }
}
