
import java.util.*;

public class s465977291{
    public static void main(String[] args) {
        // Declare variables for the number of items (n) and the distance (d)
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int d = scanner.nextInt();

        // Calculate the effective range of coverage, which is (d*2 + 1)
        double a = d * 2 + 1;

        // Calculate and output the minimum number of groups needed to cover 'n' items
        // This is done by dividing 'n' by the coverage 'a' and rounding up to the nearest whole number
        System.out.println((int)Math.ceil(n / a));
    }
}

// END-OF-CODE