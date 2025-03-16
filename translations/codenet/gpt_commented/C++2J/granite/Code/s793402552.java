
import java.util.*;

public class s793402552{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int num = a * (int)Math.pow(10, String.valueOf(b).length()) + b;
        int i;
        for (i = 1; i <= 100100; i++) {
            if (i * i == num) break;
        }
        if (i > 100100) {
            System.out.println("No");
        } else {
            System.out.println("Yes");
        }
    }
}
