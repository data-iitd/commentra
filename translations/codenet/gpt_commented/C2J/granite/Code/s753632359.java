
import java.util.Scanner;

public class s753632359{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int D = sc.nextInt();
        int ans = N / (2 * D + 1);
        int rem = N % (2 * D + 1);
        if (rem!= 0) {
            ans = ans + 1;
        }
        System.out.println(ans);
    }
}
