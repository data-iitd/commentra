
import java.util.*;

public class atcoder_ABC167_D{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int K = sc.nextInt();
        int[] L = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            L[i] = sc.nextInt();
        }
        int[] path = new int[N + 1];
        int ind = 0;
        int count = 0;
        int x = 1;
        int t = -1;
        boolean flag = false;
        Map<Integer, Integer> Hash = new HashMap<>();

        for (int i = 0; i <= N; i++) {
            int ne = L[x];
            if (Hash.containsKey(ne)) {
                flag = true;
                t = Hash.get(ne);
                break;
            }
            path[ind] = ne;
            ind++;
            Hash.put(ne, ind);
            x = ne;
        }

        if (flag) {
            int[] loop = new int[N + 1];
            for (int i = t; i <= N; i++) {
                loop[i - t] = path[i];
            }
            if (K < ind + 1) {
                System.out.println(path[K - 1]);
            } else {
                K = K - ind - 1;
                K = K % (N - t + 1);
                System.out.println(loop[K]);
            }
        } else {
            System.out.println(path[K - 1]);
        }
    }
}
