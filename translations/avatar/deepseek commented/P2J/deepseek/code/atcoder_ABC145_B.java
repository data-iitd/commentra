public class Main {
    public static void main(String[] args) {
        // Take an integer input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();

        // Take a string input from the user
        String s = scanner.next();

        // Check if n is odd
        if (n % 2 != 0) {
            // Print 'No' if n is odd
            System.out.println('No');
        // If n is even, compare the first half of the string with the second half
        } else if (s.substring(0, n / 2).equals(s.substring(n / 2, n))) {
            // Print 'Yes' if the first half is equal to the second half
            System.out.println('Yes');
        } else {
            // Print 'No' if the first half is not equal to the second half
            System.out.println('No');
        }
    }
}
