
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] as = new int[n+1];
        int[] bs = new int[n];
        for (int i = 0; i < as.length; i++) {
            as[i] = sc.nextInt();
        }
        for (int i = 0; i < bs.length; i++) {
            bs[i] = sc.nextInt();
        }
        int sum = 0;
        for (int i = 0; i <= n-1; i++) {
            int a = as[i];
            int b = bs[i];
            if (a <= b) {
                sum += a;
                b -= a;
                if (i+1 <= n) {
                    int an = as[i+1];
                    if (an <= b) {
                        sum += an;
                        as[i+1] = 0;
                    } else {
                        sum += b;
                        as[i+1] -= b;
                    }
                }
            } else {
                sum += b;
            }
        }
        System.out.println(sum);
    }
}

