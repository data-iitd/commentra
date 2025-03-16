
import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] w = new int[n];
        for (int i = 0; i < n; i++) {
            w[i] = sc.nextInt();
        }

        int x = sc.nextInt();

        List<Integer> d = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if ((x - w[i]) / (n - 1) == w[i]) {
                d.add(i + 1);
            }
        }

        System.out.println(d.size());
        System.out.println(d.stream().map(String::valueOf).collect(Collectors.joining(" ")));
    }
}

