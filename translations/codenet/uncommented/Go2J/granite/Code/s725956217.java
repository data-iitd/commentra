
import java.util.*;

class s725956217 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        int[] a = new int[N];
        int[] b = new int[N];
        for (int i = 0; i < N; i++) {
            a[i] = sc.nextInt();
            b[i] = sc.nextInt();
        }
        int[][] s = new int[N][2];
        for (int i = 0; i < N; i++) {
            s[i][0] = a[i];
            s[i][1] = b[i];
        }
        Arrays.sort(s, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });
        int total = 0;
        for (int i = 0; i < N; i++) {
            int n = Math.min(s[i][1], M);
            total += n * s[i][0];
            M -= n;
            if (M == 0) {
                break;
            }
        }
        System.out.println(total);
    }
}
