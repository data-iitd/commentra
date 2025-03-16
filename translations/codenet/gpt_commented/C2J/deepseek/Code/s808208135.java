import java.util.Scanner;

public class BellmanFord {
    static final int N = 100000;
    static final int INF = 1000000;

    static class Edge {
        int go;
        int back;
        int cost;
    }

    static int n;
    static int[] d = new int[N];
    static Edge[] a = new Edge[500000];

    static void root(int b) {
        int flag = 1;

        for (int i = 0; i < n; i++) {
            d[i] = INF;
        }
        d[0] = 0;

        while (flag != 0) {
            flag = 0;
            for (int i = 0; i < b; i++) {
                if (a[i].cost + d[a[i].back] < d[a[i].go]) {
                    d[a[i].go] = a[i].cost + d[a[i].back];
                    flag = 1;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int u = scanner.nextInt();
            int k = scanner.nextInt();
            for (int j = 0; j < k; j++) {
                a[count] = new Edge();
                a[count].back = u;
                a[count].go = scanner.nextInt();
                a[count].cost = scanner.nextInt();
                count++;
            }
        }

        root(count);

        for (int i = 0; i < n; i++) {
            System.out.println(i + " " + d[i]);
        }
    }
}
