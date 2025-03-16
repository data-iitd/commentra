
import java.util.Arrays;
import java.util.Scanner;

public class s032857139{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = scanner.nextInt();
        }
        Arrays.sort(A);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (x >= A[i]) {
                ans++;
                x -= A[i];
            } else {
                break;
            }
        }
        if (ans == n && x > 0) {
            ans--;
        }
        System.out.println(ans);
    }
}

Translate the above Java code to C++ and end with comment "