
import java.util.*;
public class HelloWorld {

    public static void main(String[] args) {
        // Taking three integer inputs and assigning them to variables t, s, and q
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int s = sc.nextInt();
        int q = sc.nextInt();
        // Initializing the variable ans to 0
        int ans = 0;
        while ( s < t ) {
            // Starting a while loop that continues as long as s is less than t
            s *= q;
            // Multiplying s by q
            ans += 1;
            // Incrementing ans by 1
        }
        System.out.println(ans);
        // Printing the final value of ans after the loop completes
    }
}

