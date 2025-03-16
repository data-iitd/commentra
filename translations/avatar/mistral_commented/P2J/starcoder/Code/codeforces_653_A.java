
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = sc.nextInt();
        }
        Arrays.sort(l);
        for (int i = 0; i < n; i++) {
            if (l[i] + 1 < n && l[i] + 2 < n) {
                System.out.println("YES");
                break;
            }
        } else {
            System.out.println("NO");
        }
    }
}
