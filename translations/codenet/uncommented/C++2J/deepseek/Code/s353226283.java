import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        ArrayList<Integer> vec = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            vec.add(scanner.nextInt());
        }
        Collections.sort(vec);
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i + k - 1 < n; i++) {
            int diff = vec.get(i + k - 1) - vec.get(i);
            if (diff < ans) {
                ans = diff;
            }
        }
        System.out.println(ans);
    }
}
