import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Declare integer variables to store input values
        int h1, h2, m1, m2, k;
        
        // Read input values for h1, m1, h2, m2, and k from the standard input
        Scanner sc = new Scanner(System.in);
        h1 = sc.nextInt();
        m1 = sc.nextInt();
        h2 = sc.nextInt();
        m2 = sc.nextInt();
        k = sc.nextInt();
        
        // Calculate the difference in minutes between h2:m2 and h1:m1
        int ans = (h2 * 60 + m2) - (h1 * 60 + m1);
        
        // Print the result of subtracting k from the calculated difference
        System.out.println(ans - k);
    }
}
