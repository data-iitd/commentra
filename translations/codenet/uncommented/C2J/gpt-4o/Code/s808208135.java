import java.util.Scanner;

class Date {
    int go, back, cost;

    Date(int back, int go, int cost) {
        this.back = back;
        this.go = go;
        this.cost = cost;
    }
}

public class Main {
    static final int N = 100000;
    static final int INF = 1000000;
    static int n;
    static int[] d = new int[N];
    static Date[] a = new Date[500000];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int count = 0;

        n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            int u = scanner.nextInt();
            int k = scanner.nextInt();
            for (int j = 0; j < k; j++) {
                int go = scanner.nextInt();
                int cost = scanner.nextInt();
                a[count++] = new Date(u, go, cost);
            }
        }
        root(count);
        for (int i = 0; i < n; i++) {
            System.out.println(i + " " + d[i]);
        }
        scanner.close();
    }

    static void root(int b) {
        for (int i = 0; i < n; i++) {
            d[i] = INF;
        }
        d[0] = 0;

        boolean flag = true;
        while (flag) {
            flag = false;
            for (int i = 0; i < b; i++) {
                if (a[i].cost + d[a[i].back] < d[a[i].go]) {
                    d[a[i].go] = a[i].cost + d[a[i].back];
                    flag = true;
                }
            }
        }
    }
}

// <END-OF-CODE>
