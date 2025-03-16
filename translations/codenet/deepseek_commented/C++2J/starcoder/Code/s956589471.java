import java.util.*;
public class Main {
    public static void main(String[] args) {
        // Step 3: Declare variables to store input values
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();
        int e = sc.nextInt();
        int k = sc.nextInt();

        // Step 5: Calculate the difference between e and a and check if it is less than or equal to k
        System.out.println((e - a <= k? "Yay!" : ":("));

        // Step 7: Return 0 to indicate successful execution
        return 0;
    }
}
