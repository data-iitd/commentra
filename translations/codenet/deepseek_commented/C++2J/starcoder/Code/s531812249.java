import java.util.*;
import java.io.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int ans = 0;
        ans += n * (n - 1) / 2;
        ans += m * (m - 1) / 2;
        System.out.println(ans);
    }
}

