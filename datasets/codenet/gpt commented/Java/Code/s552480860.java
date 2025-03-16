import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in);
        
        // Read the first time (h1, m1) in hours and minutes
        int h1 = sc.nextInt();
        int m1 = sc.nextInt();
        
        // Read the second time (h2, m2) in hours and minutes
        int h2 = sc.nextInt();
        int m2 = sc.nextInt();
        
        // Read the value of k, which represents a duration to subtract
        int k = sc.nextInt();
        
        // Convert the first time (h1, m1) into total minutes
        int t1 = h1 * 60 + m1;
        
        // Convert the second time (h2, m2) into total minutes
        int t2 = h2 * 60 + m2;
        
        // Calculate the difference in minutes between the two times, subtracting k
        System.out.println(t2 - t1 - k);
    }
}
