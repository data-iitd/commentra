import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        String s = sc.next();
        int[] cumsum = new int[n];
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                cumsum[i] = s.charAt(i) == 'A' ? 1 : 0;
            } else if (i == n - 1) {
                cumsum[i] = s.charAt(i) == 'C' ? 1 : 0;
            } else {
                cumsum[i] = cumsum[i - 1] + (s.charAt(i) == 'A' ? 1 : 0);
            }
        }
        for (int i = 0; i < q; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            System.out.println(cumsum[r - 1] - cumsum[l - 1]);
        }
    }
}

