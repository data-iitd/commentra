
import java.util.Scanner;

public class s712890349{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        scanner.nextLine();
        String S = scanner.nextLine();

        int ans = 0;
        int sum = 0;
        int zero = 0;
        int l = 0;
        char[] chars = S.toCharArray();
        int[] blocks = new int[N];
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (i == 0 || chars[i]!= chars[i - 1]) {
                blocks[count] = 1;
                count++;
            } else {
                blocks[count - 1]++;
            }
        }

        for (int r = 0; r < count; r++) {
            sum += blocks[r];

            if (chars[r] == '0') {
                zero++;
            }

            while (K < zero) {
                sum -= blocks[l];
                if (chars[l] == '0') {
                    zero--;
                }
                l++;
            }

            ans = Math.max(ans, sum);
        }

        System.out.println(ans);
    }
}

// Translate the above Java code to C++ and end with comment "