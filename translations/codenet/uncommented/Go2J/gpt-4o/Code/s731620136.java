import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        String S = sc.next();

        if (N < 4) {
            System.out.println(0);
            return;
        }

        int nr = 0, nb = 0, ng = 0;
        for (char c : S.toCharArray()) {
            if (c == 'R') {
                nr++;
            } else if (c == 'B') {
                nb++;
            } else if (c == 'G') {
                ng++;
            }
        }

        int same = 0;
        for (int a = 1; a < N; a++) {
            int i = 0;
            int j = 1 * a;
            int k = 2 * a;
            if (k >= N) {
                break;
            }
            while (k < N) {
                if (S.charAt(i) != S.charAt(j) && S.charAt(i) != S.charAt(k) && S.charAt(j) != S.charAt(k)) {
                    same++;
                }
                i++;
                j++;
                k++;
            }
        }

        int tot = nr * nb * ng;
        System.out.println(tot - same);
    }
}
// <END-OF-CODE>
