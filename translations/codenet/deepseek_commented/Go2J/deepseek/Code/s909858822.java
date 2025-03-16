public class Main {
    public static void main(String[] args) {
        // Declare two integer variables A and B
        int A, B;
        
        // Read two integers from the standard input and assign them to A and B
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        A = scanner.nextInt();
        B = scanner.nextInt();
        
        // Declare a variable to store the result
        int ans;
        
        // Check if A is between 6 and 12 inclusive
        if (6 <= A && A <= 12) {
            // Calculate the half of B and assign it to ans
            ans = B / 2;
        } else if (12 < A) {
            // Assign B to ans if A is greater than 12
            ans = B;
        } else {
            // Default case, you can set ans to 0 or any other default value
            ans = 0;
        }
        
        // Print the value of ans
        System.out.println(ans);
    }
}
