import java.util.Scanner;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        Vector<Integer> foods = new Vector<Integer>();

        for (int i = 0; i < m; i++) {
            foods.add(0);
        }

        for (int i = 0; i < n; i++) {
            int k = sc.nextInt();

            for (int j = 0; j < k; j++) {
                int temp = sc.nextInt();
                temp--;

                foods.set(temp, foods.get(temp) + 1);
            }
        }

        int ans = 0;
        for (int elem : foods) {
            if (elem == n) {
                ans++;
            }
        }

        System.out.println(ans);
    }
}

