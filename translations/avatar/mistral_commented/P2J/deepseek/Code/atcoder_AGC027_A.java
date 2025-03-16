import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int[] na = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        int n = na[0];
        int x = na[1];
        int[] a = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).sorted().toArray();
        int ans = 0;
        if (a[0] > x) {
            System.out.println(0);
            return;
        }
        for (int i : a) {
            if (i > x) {
                x = 0;
                break;
            }
            x -= i;
            ans++;
        }
        if (x != 0) {
            ans--;
        }
        System.out.println(ans);
    }
}
