
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a = sc.nextInt();
        int[] s = new int[n];
        for (int i = 0; i < n; i++) {
            s[i] = sc.nextInt();
        }
        Arrays.sort(s);
        int sum = 0;
        for (int i = n - 1; i > n - a - 1; i--) {
            sum += s[i];
        }
        System.out.println(sum);
    }
}

