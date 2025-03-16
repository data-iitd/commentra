public class Main {
    public static void main(String[] args) {
        // Read four integers x, y, a, and b from the input
        Scanner scanner = new Scanner(System.in);
        int x = scanner.nextInt();
        int y = scanner.nextInt();
        int a = scanner.nextInt();
        int b = scanner.nextInt();

        // Calculate the LCM of x and y
        int lcm = lcm(x, y);

        // Compute the number of integers in the range from a to b that are divisible by lcm
        // and print the result
        System.out.println(b / lcm - (a - 1) / lcm);
    }

    public static int lcm(int a, int b) {
        // Calculate the greatest common divisor (GCD) of a and b using the Euclidean algorithm
        while (a % b != 0) {
            int temp = a;
            a = b;
            b = temp % b;
        }
        return b;
    }
}
