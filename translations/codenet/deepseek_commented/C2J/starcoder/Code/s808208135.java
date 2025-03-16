import java.util.*;

public class Main
{
    // Define a structure to store connection details
    static class Date
    {
        int go, back, cost;
    }

    // Define the maximum number of nodes and the distance array
    static int n, d[] = new int[N];
    static Date a[] = new Date[500000];

    // Declare the root function
    static void root(int b)
    {
        int i, flag = 1;

        // Initialize all distances to INF except the root node (node 0)
        for (i = 0; i < n; i++)
            d[i] = INF;
        d[0] = 0;

        // Use a while loop to update distances based on connections
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

    public static void main(String[] args)
    {
        // Declare variables for iteration and input
        int i, j, k, u, count = 0;

        // Read the number of nodes
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();

        // Read each node's connections and store them in the array 'a'
        for (i = 0; i < n; i++)
        {
            u = sc.nextInt();
            k = sc.nextInt();
            for (j = 0; j < k; j++)
            {
                a[count] = new Date();
                a[count].back = u;
                a[count].go = sc.nextInt();
                a[count].cost = sc.nextInt();
                count++;
            }
        }

        // Call the root function to initialize distances
        root(count);

        // Print the shortest distances from the root node to each node
        for (i = 0; i < n; i++)
            System.out.println(i + " " + d[i]);
    }
}

