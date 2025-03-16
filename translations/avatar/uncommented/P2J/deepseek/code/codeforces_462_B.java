import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        String s = scanner.next();
        int[] count = new int[26];
        for (char c : s.toCharArray()) {
            count[c - 'A']++;
        }
        java.util.Arrays.sort(count);
        int res = 0;
        for (int i = 25; i >= 0; i--) {
            if (count[i] >= k) {
                res += k * k;
                System.out.println(res);
                return;
            }
            k -= count[i];
            res += count[i] * count[i];
        }
        System.out.println(res);
    }
}
