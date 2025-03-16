
import java.util.*;

class s963048401 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] as = new int[n];
        for (int i = 0; i < n; i++) {
            as[i] = sc.nextInt();
        }
        List<Integer> xs = new ArrayList<>();
        xs.add(as[0]);
        for (int j = 1; j < n; j++) {
            int idx = Collections.binarySearch(xs, as[j]);
            if (idx < 0) {
                idx = ~idx;
            }
            xs.set(idx, as[j]);
        }
        System.out.println(xs.size());
    }
}

