import java.util.*; 

public class Main { 
    public static void main(String[] args) { 
        // Create a new instance of Main and call the solve method with a Scanner for input
        new Main().solve(new Scanner(System.in)); 
    } 
    
    private void solve(Scanner sc) { 
        // Read three integers A, B, and n from the input
        int A = sc.nextInt(), B = sc.nextInt(), n = sc.nextInt(); 
        
        // Check if A is zero
        if (A == 0) { 
            // If both A and B are zero, print 1 (indeterminate case)
            if (B == 0) 
                System.out.println(1); 
            // If A is zero and B is not, print "No solution"
            else 
                System.out.println("No solution"); 
            return; 
        } 
        
        // Check if B is not divisible by A
        if (B % A != 0) { 
            // If B is not divisible by A, print "No solution"
            System.out.println("No solution"); 
            return; 
        } 
        
        // Divide B by A to simplify the equation
        B /= A; 
        
        // Determine if B is negative
        boolean neg = B < 0; 
        
        // Check if B is negative and n is even
        if (neg && n % 2 == 0) { 
            // If both conditions are true, print "No solution"
            System.out.println("No solution"); 
            return; 
        } 
        
        // If B is negative, make it positive for further calculations
        if (neg) 
            B = -B; 
        
        // Iterate through possible values of x from 0 to B
        for (int x = 0; x <= B; x++) { 
            // Check if x raised to the power of n equals B
            if (Math.pow(x, n) == B) { 
                // If found, print the result considering the sign of B
                System.out.println(neg ? -x : x); 
                return; 
            } 
        } 
        
        // If no valid x is found, print "No solution"
        System.out.println("No solution"); 
    } 
}
