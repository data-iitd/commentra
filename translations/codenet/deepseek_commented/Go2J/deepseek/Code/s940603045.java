public class Main {
    public static void main(String[] args) {
        // Read input string
        String N = scanner.nextLine();
        char[] b = N.toCharArray(); // Convert string to char array
        int n = 0; // Initialize sum of digits

        // Calculate sum of digits
        for (int i = 0; i < b.length; i++) {
            n += Character.getNumericValue(b[i]);
        }
        int m = Integer.parseInt(N); // Convert input string to integer
        if (m % n == 0) { // Check if the number is divisible by the sum of its digits
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
