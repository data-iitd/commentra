
import java.util.Scanner;

public class s735953430{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int X = scanner.nextInt();
        int N = scanner.nextInt();
        int[] plus = new int[256];
        int[] minus = new int[256];
        for (int i = 0; i < 256; i++) {
            plus[i] = i;
            minus[i] = -1 * i;
        }
        for (int i = 0; i < N; i++) {
            int j = scanner.nextInt();
            plus[j] = 0;
        }
        int i_min = 0;
        int min = 1000;
        for (int i = 255; i >= 0; i--) {
            if (plus[i] == 0 && i > 0) {
                continue;
            }
            int k = X - plus[i];
            if (k < 0) {
                k *= -1;
            }
            if (k <= min) {
                min = k;
                i_min = i;
            }
        }
        System.out.println(i_min);
    }
}

