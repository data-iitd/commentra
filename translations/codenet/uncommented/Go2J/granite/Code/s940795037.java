
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;

public class s940795037{
    public static void main(String[] args) {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        int n = sc.nextInt();
        double ans = 0.0;
        for (int i = 0; i < n; i++) {
            int tmp = 1 / sc.nextInt();
            ans += 1.0 / tmp;
        }
        System.out.println(1 / ans);
    }
}

