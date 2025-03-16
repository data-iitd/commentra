public class Main {
    public static void main(String[] args) {
        // Call function B to execute its logic
        B();
    }

    public static void B() {
        long x, sum; // Declare variables for input and sum
        Scanner scanner = new Scanner(System.in);
        x = scanner.nextLong(); // Read input value x from the user
        int i = 0; // Declare a counter variable
        sum = 100; // Initialize sum to 100

        // Loop until sum is less than x
        while (sum < x) {
            // Increase sum by 1% of its current value
            sum += sum / 100;
            i++; // Increment the counter
        }

        // Output the number of iterations needed to exceed or meet x
        System.out.println(i);
    }
}
