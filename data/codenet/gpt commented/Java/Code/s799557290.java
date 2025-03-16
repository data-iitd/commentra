import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Read the number of problems (a) and the number of submissions (b)
        int a = sc.nextInt();
        int b = sc.nextInt();
        
        // Initialize an array to track whether each problem has been accepted (AC)
        boolean ju[] = new boolean[100001];
        // Initialize an array to count the number of wrong answers (WA) for each problem
        int pe[] = new int[100001];
        
        // Initialize counters for accepted problems (ac) and total wrong answers (wa)
        int wa = 0;
        int ac = 0;
        
        // Process each submission
        for(int i = 0; i < b; i++) {
            // Read the problem number and the result of the submission
            int n = sc.nextInt();
            String res = sc.next();
            
            // If the result is "WA" and this problem has not been accepted yet
            if(res.equals("WA") && ju[n - 1] != true) {
                // Increment the wrong answer count for this problem
                pe[n - 1]++;
            }
            
            // If the result is "AC", mark this problem as accepted
            if(res.equals("AC")) {
                ju[n - 1] = true;
            }
        }
        
        // Calculate the total number of accepted problems and the total wrong answers
        for(int i = 0; i < a; i++) {
            if(ju[i]) {
                // Increment the accepted problem count
                ac++;
                // Add the number of wrong answers for this accepted problem to the total
                wa += pe[i];
            }
        }
        
        // Output the total number of accepted problems and total wrong answers
        System.out.println("" + ac + " " + wa);
    }
}
