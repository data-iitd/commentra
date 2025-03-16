import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, d[] = new int[100000];
        Date a[] = new Date[500000];
        int count = 0;
        n = in.nextInt();
        for (int i = 0; i < n; i++) {
            int u, k;
            u = in.nextInt();
            k = in.nextInt();
            for (int j = 0; j < k; j++) {
                a[count] = new Date();
                a[count].back = u;
                a[count].go = in.nextInt();
                a[count].cost = in.nextInt();
                count++;
            }
        }
        root(count);
        for (int i = 0; i < n; i++)
            System.out.println(i + " " + d[i]);
    }

    public static void root(int b) {
        int i, flag = 1;
        for (i = 0; i < 100000; i++)
            d[i] = 1000000;
        d[0] = 0;
        while (flag!= 0) {
            flag = 0;
            for (i = 0; i < b; i++) {
                if (a[i].cost + d[a[i].back] < d[a[i].go]) {
                    d[a[i].go] = a[i].cost + d[a[i].back];
                    flag = 1;
                }
            }
        }
    }
}

