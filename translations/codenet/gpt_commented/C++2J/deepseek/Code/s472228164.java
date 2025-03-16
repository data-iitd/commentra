public class Main {
    // Function to check certain conditions based on input values x and y
    public static String check(int x, int y) {
        // Check if y is an even number
        if (y % 2 == 0) {
            // Calculate t as half of y minus x
            int t = y / 2 - x;
            
            // Check if t is non-negative and if (x - t) is also non-negative
            if (t >= 0 && (x - t) >= 0)
                return "Yes"; // Return "Yes" if both conditions are satisfied
        }
        return "No"; // Return "No" if y is odd or conditions are not satisfied
    }

    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int x = scanner.nextInt(); // Read input value for x
        int y = scanner.nextInt(); // Read input value for y

        // Call the check function and print the result
        System.out.println(check(x, y));
    }
}
