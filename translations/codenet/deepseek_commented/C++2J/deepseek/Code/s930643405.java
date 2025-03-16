public class Main {
    public static void main(String[] args) {
        // Read the initial number and the number of unavailable digits
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();

        // Define an array to keep track of unavailable digits
        boolean[] d = new boolean[10];

        // Mark the unavailable digits
        for (int i = 0; i < k; ++i) {
            int a = scanner.nextInt();
            d[a] = true;
        }

        // Loop until a valid number is found
        while (true) {
            // Copy the current number to a temporary variable and initialize the check flag
            int x = n;
            boolean hantei = true;

            // Check each digit of the number
            while (x > 0) {
                // If a digit is unavailable, set the check flag to false and break the loop
                if (d[x % 10]) {
                    hantei = false;
                    break;
                }
                // Move to the next digit
                x /= 10;
            }

            // If the number is valid, print it and break the loop
            if (hantei) {
                System.out.println(n);
                break;
            }

            // Increment the number and check again
            n++;
        }
    }
}
