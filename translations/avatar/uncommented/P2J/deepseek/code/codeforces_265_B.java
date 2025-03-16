import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ArrayList<Integer> l = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            l.add(scanner.nextInt());
        }
        int ans = n - 1;
        int last = 0;
        for (int i : l) {
            ans += Math.abs(last - i) + 1;
            last = i;
        }
        System.out.println(ans);
    }
}
