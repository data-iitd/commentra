
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        PrintWriter writer = new PrintWriter(System.out);

        int n = scanner.nextInt();

        int[] aa = new int[n+2];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            aa[i+1] = scanner.nextInt();
            sum += Math.abs(aa[i+1] - aa[i]);
        }
        sum += Math.abs(aa[n+1] - aa[n]);

        for (int i = 1; i < n+1; i++) {
            int ans = sum - Math.abs(aa[i+1]-aa[i]) - Math.abs(aa[i]-aa[i-1]) + Math.abs(aa[i+1]-aa[i-1]);
            writer.println(ans);
        }

        writer.flush();
    }
}

