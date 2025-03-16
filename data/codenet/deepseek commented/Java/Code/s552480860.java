
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Step 1: Importing Scanner to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Step 2: Reading hours and minutes for the first time
        int h1 = sc.nextInt();
        int m1 = sc.nextInt();
        
        // Step 3: Reading hours and minutes for the second time
        int h2 = sc.nextInt();
        int m2 = sc.nextInt();
        
        // Step 4: Reading the duration in minutes
        int k = sc.nextInt();
        
        // Step 5: Converting both times to total minutes since midnight
        int t1 = h1 * 60 + m1;
        int t2 = h2 * 60 + m2;
        
        // Step 6: Calculating the difference in minutes and subtracting the duration
        System.out.println(t2 - t1 - k);
    }
}

