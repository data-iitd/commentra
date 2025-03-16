
import java.util.Scanner;
import java.util.Arrays;

public class codeforces_653_A{
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] l = new int[n];
        for (int i = 0; i < n; i++) {
            l[i] = scanner.nextInt();
        }
        Arrays.sort(l);
        boolean found = false;
        for (int i = 0; i < n - 2; i++) {
            if (Arrays.binarySearch(l, l[i] + 1) >= 0 && Arrays.binarySearch(l, l[i] + 2) >= 0) {
                found = true;
                break;
            }
        }
        if (found) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
