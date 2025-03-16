public class Main {
    public static void main(String[] args) {
        // Declare two integer variables A and B to hold input values
        int A, B;
        
        // Read two integers from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        A = scanner.nextInt();
        B = scanner.nextInt();
        
        // Declare a variable to hold the result
        int ans;
        
        // Check if A is between 6 and 12 (inclusive)
        if (6 <= A && A <= 12) {
            // If A is in the range, set ans to half of B
            ans = B / 2;
        } else if (12 < A) {
            // If A is greater than 12, set ans to the value of B
            ans = B;
        } else {
            // If A is less than 6, set ans to 0 (or any default value)
            ans = 0;
        }
        
        // Print the result
        System.out.println(ans);
    }
}
