import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    static int ans = 100;
    static int[][] balls;
    static int N;
    static boolean[] taken;

    public static void main(String[] args) {
        /* Initialize input reader and output writer objects */
        FastScanner I = new FastScanner(); //Input
        OutPut O = new OutPut(); //Output

        /* Read the number of balls and initialize the answer and balls array */
        N = I.nextInt();
        ans=N;
        balls = new int[N][2];

        /* Read the coordinates of each ball and sort them in ascending order of x-coordinate */
        for (int i = 0; i < N; i++) {
            balls[i][0] = I.nextInt();
            balls[i][1] = I.nextInt();
        }
        Arrays.sort(balls,(a,b)->Integer.compare(a[0], b[0]));

        /* Solve the problem twice: first with the original order of balls, and then with the reversed order */
        solve();
        for (int i = 0; i < N; i++) {
            int x = balls[i][0];
            int y = balls[i][1];
            balls[i][0]=y;
            balls[i][1]=x;
        }
        Arrays.sort(balls,(a,b)->Integer.compare(a[0], b[0]));
        solve();

        /* Print the answer */
        O.pln(ans);
    }

    public static void solve() {
        /* Iterate through all possible differences between x and y coordinates of balls */
        for (int add = 1; add<N; add++) {
            taken = new boolean[N];
            int p = balls[add][0]-balls[0][0];
            int q = balls[add][1]-balls[0][1]; //Differences

            /* Find the maximum number of connected balls that can be formed with the given differences p and q */
            ans=min(ans,check(p,q));
        }
    }

    public static int check(int p, int q) {
        int ret = 0;
        while (true) {
            boolean added=false;
            int start = 0;
            int x = -1;
            int y = -1; //Coordinates that we want next

            /* Find the first unassigned ball that can be added to the connected component */
            for (int i = 0; i < N; i++) {
                if (!taken[i]) {
                    added=true;
                    ret++;
                    start=i;
                    taken[i]=true;
                    x=balls[i][0]+p;
                    y=balls[i][1]+q;
                    break;
                }
            }

            /* If no such ball was found, exit the loop */
            if (!added) break;

            /* Add all the balls that have the same x and y coordinates as the current ball */
            for (int i = start+1; i < N; i++) {
                if (balls[i][0]==x&&balls[i][1]==y) {
                    taken[i]=true;
                    x+=p;
                    y+=q;
                }
            }
        }
        return ret;
    }
    // Helper methods for mathematical operations
    // ...
}
