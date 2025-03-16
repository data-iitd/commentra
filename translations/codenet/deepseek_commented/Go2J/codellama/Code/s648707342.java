
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Reads the number of arms.
        int n = sc.nextInt();

        // Defines a class to represent an arm with left and right endpoints.
        class Arm {
            int l, r;
            public Arm(int l, int r) {
                this.l = l;
                this.r = r;
            }
        }

        // Creates an array to store the arms.
        Arm[] as = new Arm[n];

        // Reads each arm's range and stores the left and right endpoints.
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int l = sc.nextInt();
            as[i] = new Arm(x - l, x + l);
        }

        // Sorts the arms based on their right endpoints.
        Arrays.sort(as, (a, b) -> a.r - b.r);

        // Initializes the answer and the right endpoint reference.
        int ans = 1;
        int r = as[0].r;

        // Iterates through the sorted arms to count non-overlapping arms.
        for (int i = 1; i < n; i++) {
            if (as[i].l >= r) {
                ans++;
                r = as[i].r;
            }
        }

        // Prints the count of non-overlapping arms.
        System.out.println(ans);
    }
}

