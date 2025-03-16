
import java.util.Scanner;

public class s072370813{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int[] A = new int[N];
        long sum = 0;
        long wa = 0;
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
            sum += A[i];
            wa += i + 1;
        }
        int ans = 0;
        if (sum % wa == 0) {
            int shou = (int) (sum / wa);
            int[] sa = new int[N];
            for (int i = 0; i < N; i++) {
                sa[i] = A[(i + 1) % N] - A[i] - shou;
            }
            boolean flag = true;
            for (int i = 0; i < N - 1; i++) {
                if (sa[i] <= 0 || sa[i] % N!= 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans = 1;
            }
        }
        System.out.println(ans == 1? "YES" : "NO");
    }
}
