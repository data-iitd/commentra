
import java.util.*;

public class Main {

    public static String check(int x, int y) {
        // Check if y is even
        if(y % 2 == 0) {
            // Calculate t as half of y minus x
            int t = (int)(0.5*y) - x;
            // Check if t is non-negative and x minus t is also non-negative
            if(t >= 0 && (x-t) >= 0)
                return "Yes";
        }
        // If the conditions are not met, return "No"
        return "No";
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int x = in.nextInt();
        int y = in.nextInt();
        System.out.println(check(x, y));
    }
}

