
import java.util.Scanner;

public class s401511324{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = sc.nextInt();
        }
        int cnt = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (l[j] < l[i]) {
                    int tmp = l[i];
                    l[i] = l[j];
                    l[j] = tmp;
                }
            }
        }
        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (l[i] + l[j] > l[k]) {
                        cnt++;
                    } else {
                        break;
                    }
                }
            }
        }
        System.out.println(cnt);
    }
}
