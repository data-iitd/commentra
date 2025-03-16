import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][] ans = new int[N][];
        for (int i = 0; i < N; i++) {
            int A = sc.nextInt();
            int idx = binarySearch(A, ans);
            if (idx == ans.length) {
                ans[idx] = new int[]{A};
            } else {
                ans[idx][1] = A;
            }
        }
        System.out.println(ans.length);
    }

    public static int binarySearch(int key, int[][] ans) {
        int bad = -1, good = ans.length;
        while (good - bad > 1) {
            int mid = (bad + good) / 2;
            if (ans[mid][ans[mid].length - 1] < key) {
                good = mid;
            } else {
                bad = mid;
            }
        }
        return good;
    }
}

