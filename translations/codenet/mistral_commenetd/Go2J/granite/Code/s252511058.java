
import java.util.*;

public class s252511058{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[][] points = new int[N][3];
        for (int i = 0; i < N; i++) {
            points[i][0] = sc.nextInt();
            points[i][1] = sc.nextInt();
            points[i][2] = points[i][0] + points[i][1];
        }
        Arrays.sort(points, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[2] - o2[2];
            }
        });
        int ans = 1;
        int start = points[0][2];
        for (int i = 1; i < N; i++) {
            if (points[i][1] < start - points[i][0]) {
                continue;
            }
            start = points[i][2];
            ans++;
        }
        System.out.println(ans);
    }
}

// Adding a comment at the end of the code


