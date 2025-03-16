import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int id = 0;
        int l = scanner.nextInt();
        int r = scanner.nextInt();
        for (int i = 1; i < n; i++) {
            int li = scanner.nextInt();
            int ri = scanner.nextInt();
            if (li <= l && r <= ri) {
                id = i;
            } else if (li < l || r < ri) {
                id = n;
            }
            l = Math.min(l, li);
            r = Math.max(r, ri);
        }
        System.out.println(id == n ? -1 : id + 1);
    }
}
