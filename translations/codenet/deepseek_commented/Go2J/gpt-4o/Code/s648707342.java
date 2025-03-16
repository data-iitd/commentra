import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    // Defines a class to represent an arm with left and right endpoints.
    static class Arm {
        int l, r;

        Arm(int l, int r) {
            this.l = l;
            this.r = r;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Reads the number of arms.
        int n = scanner.nextInt();
        
        // Creates an array to store the arms.
        Arm[] arms = new Arm[n];
        
        // Reads each arm's range and stores the left and right endpoints.
        for (int i = 0; i < n; i++) {
            int x = scanner.nextInt();
            int l = scanner.nextInt();
            arms[i] = new Arm(x - l, x + l);
        }
        
        // Sorts the arms based on their right endpoints.
        Arrays.sort(arms, Comparator.comparingInt(a -> a.r));
        
        // Initializes the answer and the right endpoint reference.
        int ans = 1;
        int r = arms[0].r;
        
        // Iterates through the sorted arms to count non-overlapping arms.
        for (int i = 1; i < n; i++) {
            if (arms[i].l >= r) {
                ans++;
                r = arms[i].r;
            }
        }
        
        // Prints the count of non-overlapping arms.
        System.out.println(ans);
        
        scanner.close();
    }
}
// <END-OF-CODE>
