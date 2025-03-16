public class SumOfNaturalNumbers {
    public static void main(String[] args) {
        // Declare variables n and sum
        int n, sum;

        // Create a Scanner object to read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read an integer value from the user and store it in the variable n
        n = scanner.nextInt();

        // Calculate the sum of the first n natural numbers
        // The formula for the sum of the first n natural numbers is n*(n+1)/2
        sum = (n * (n + 1)) / 2;

        // Print the calculated sum to the standard output
        System.out.println(sum);

        // Close the Scanner object
        scanner.close();
    }
}
