
import java.util.Scanner;

public class s054878611{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int result = solution(n, a);
        System.out.println(result);
    }

    public static int solution(int n, int[] a) {
        int[] memo = new int[100002];
        for (int num : a) {
            memo[num]++;
            memo[num + 1]++;
            memo[num + 2]++;
        }
        int out = 0;
        for (int num : memo) {
            if (num > 0) {
                out = Math.max(out, num);
            }
        }
        return out;
    }
}

Translate the above Java code to C++ and end with comment "