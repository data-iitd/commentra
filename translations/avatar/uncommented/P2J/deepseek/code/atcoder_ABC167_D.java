import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] L = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            L[i] = scanner.nextInt();
        }
        L[0] = -1;

        List<Integer> path = new ArrayList<>();
        Map<Integer, Integer> hash = new HashMap<>();
        int ind = 0;
        int x = 1;
        int t = -1;
        boolean flag = false;

        path.add(1);
        hash.put(1, 0);

        while (true) {
            int ne = L[x];
            if (hash.containsKey(ne)) {
                flag = true;
                t = hash.get(ne);
                break;
            }
            path.add(ne);
            ind++;
            hash.put(ne, ind);
            x = ne;
        }

        if (flag) {
            List<Integer> loop = path.subList(t, path.size());
            if (K < path.size()) {
                System.out.println(path.get(K));
            } else {
                K = K - path.size();
                K = K % loop.size();
                System.out.println(loop.get(K));
            }
        } else {
            System.out.println(path.get(K - 1));
        }
    }
}
