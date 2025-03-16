import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold input values
        int a, b, c, d, e, k;

        // Read six integers from standard input
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        d = sc.nextInt();
        e = sc.nextInt();
        k = sc.nextInt();

        // Check if the difference between e and a is less than or equal to k
        // If true, print "Yay!", otherwise print ":("
        System.out.println((e - a <= k? "Yay!" : ":("));
    }
}
