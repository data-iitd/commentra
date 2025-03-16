import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int n, d[], i, j, k, u, count = 0;

        n = sc.nextInt();
        d = new int[n];

        for (i = 0; i < n; i++)
        {
            u = sc.nextInt();
            k = sc.nextInt();

            for (j = 0; j < k; j++)
            {
                a[count].back = u;
                a[count].go = sc.nextInt();
                a[count].cost = sc.nextInt();
                count++;
            }
        }

        root(count);

        for (i = 0; i < n; i++)
            System.out.println(i + " " + d[i]);
    }

    public static void root(int b)
    {
        int i, flag = 1;

        for (i = 0; i < n; i++)
            d[i] = INF;

        d[0] = 0;

        while (flag!= 0)
        {
            flag = 0;

            for (i = 0; i < b; i++)
            {
                if (a[i].cost + d[a[i].back] < d[a[i].go])
                {
                    d[a[i].go] = a[i].cost + d[a[i].back];
                    flag = 1;
                }
            }
        }
    }

    public static final int INF = 1000000;
    public static Date[] a = new Date[500000];
}

