import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the input values
        int h1, h2, m1, m2, k;

        // Read input values: start time (h1:m1), end time (h2:m2), and a duration k
        Scanner in = new Scanner(System.in);
        h1 = in.nextInt();
        m1 = in.nextInt();
        h2 = in.nextInt();
        m2 = in.nextInt();
        k = in.nextInt();

        // Calculate the total minutes from the start time to the end time
        int ans = h2 * 60 + m2 - (h1 * 60 + m1);
        
        // Output the result after subtracting the duration k from the total minutes
        System.out.println(ans - k);
    }
}
