
import java.util.Scanner;

public class s724499011{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();
        int[] ns = new int[n];
        for (int i = 0; i < n; i++) {
            switch (s.charAt(i)) {
                case 'R':
                    ns[i] = 0;
                    break;
                case 'G':
                    ns[i] = 1;
                    break;
                case 'B':
                    ns[i] = 2;
                    break;
            }
        }

        int[][] rgb = new int[n + 1][3];
        rgb[0][0] = 0;
        rgb[0][1] = 0;
        rgb[0][2] = 0;
        for (int i = 1; i <= n; i++) {
            rgb[i][0] = rgb[i - 1][0];
            rgb[i][1] = rgb[i - 1][1];
            rgb[i][2] = rgb[i - 1][2];
            rgb[i][ns[i - 1]]++;
        }
        int sum = 0;
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                if (ns[i]!= ns[j]) {
                    int tn = 3 - ns[i] - ns[j];
                    sum += rgb[n][tn] - rgb[j + 1][tn];
                    int k = 2 * j - i;
                    if (k < n && ns[k] == tn) {
                        sum--;
                    }
                }
            }
        }
        System.out.println(sum);
    }
}
