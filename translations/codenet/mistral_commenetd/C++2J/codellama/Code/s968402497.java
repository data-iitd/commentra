
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tc = in.nextInt();
        int n = in.nextInt();
        int m = in.nextInt();
        if (n > m) {
            int temp = n;
            n = m;
            m = temp;
        }
        for (int i = 1; i <= m; i++) {
            if (i * tc >= n && i * tc <= m) {
                System.out.println("OK");
                break;
            }
        }
        if (i > m) {
            System.out.println("NG");
        }
    }
}

