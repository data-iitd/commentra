public class Main {
    public static void main(String[] args) {
        // Read an integer value from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();

        // Read a string value from the user
        scanner.nextLine(); // Consume newline left-over
        String s = scanner.nextLine();

        // Check if n is odd
        if (n % 2 != 0) {
            System.out.println('No');
        }
        // Check if the first half of the string is equal to the second half
        else if (s.substring(0, n / 2).equals(s.substring(n / 2, n))) {
            System.out.println('Yes');
        }
        // If the first half is not equal to the second half, print 'No'
        else {
            System.out.println('No');
        }
