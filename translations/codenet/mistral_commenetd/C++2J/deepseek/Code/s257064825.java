public class Main {
    public static void main(String[] args) {
        // Read input string from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        String str = scanner.nextLine();

        // Initialize sum variable to 0
        int sum = 0;

        // Iterate through each character in the string and add its ASCII value (after converting to digit) to sum
        for (char x : str.toCharArray()) {
            sum += (x - '0'); // Subtract '0' to convert ASCII value of digit character to its integer value
        }

        // Check if sum is divisible by 9
        if (sum % 9 == 0) {
            System.out.println("Yes"); // Output "Yes" if sum is divisible by 9
        } else {
            System.out.println("No"); // Output "No" otherwise
        }
    }
}
