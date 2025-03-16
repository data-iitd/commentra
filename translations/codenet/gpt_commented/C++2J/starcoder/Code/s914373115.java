public class Main {
    public static void main(String[] args) {
        // Call function B to execute its logic
        B();
    }

    public static void B() {
        long x, sum; // Declare variables for input and sum
        Scanner sc = new Scanner(System.in);
        x = sc.nextLong(); // Read input value x from the user
        int i; // Declare a counter variable
        sum = 100; // Initialize sum to 100

        // Loop until sum is less than x
        for (i = 0; sum < x; ++i) {
            // Increase sum by 1% of its current value
            sum += sum / 100;
        }

        // Output the number of iterations needed to exceed or meet x
        System.out.println(i);
    }
}
