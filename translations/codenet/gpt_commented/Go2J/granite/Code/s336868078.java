
import java.util.*;

public class s336868078{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int ans = solve(a, b, c);
        System.out.println(ans);
    }

    public static int solve(int a, int b, int c) {
        int temp = 0;
        if (c == a + b) {
            temp = b + c;
        } else if (c - 1 > a + b) {
            int temp_ = (c - 1) - (a + b);
            temp = b + c - temp_;
        } else {
            temp = b + c;
        }
        return temp;
    }
}

