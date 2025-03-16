
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int ans = 0;
        if (A >= 6 && A <= 12) {
            ans = B / 2;
        } else if (A > 12) {
            ans = B;
        }
        System.out.println(ans);
    }
}

