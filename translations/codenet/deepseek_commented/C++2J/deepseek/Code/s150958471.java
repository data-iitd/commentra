public class Main {
    public static void main(String[] args) {
        // Declare arrays
        int[] train = new int[2];
        int[] bus = new int[2];

        // Input values
        // The values for `train` and `bus` are taken from the user.
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        train[0] = scanner.nextInt();
        train[1] = scanner.nextInt();
        bus[0] = scanner.nextInt();
        bus[1] = scanner.nextInt();

        // Calculate the sum
        // The code then calculates the sum of the minimum values from both arrays.
        int result = Math.min(train[0], train[1]) + Math.min(bus[0], bus[1]);

        // Output the result
        // Finally, the result is printed to the console.
        System.out.println(result);
    }
}
