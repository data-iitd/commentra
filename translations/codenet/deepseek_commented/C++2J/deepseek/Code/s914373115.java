public class Main {
    public static void main(String[] args) {
        B();
    }

    public static void B() {
        long x, sum;
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        x = scanner.nextLong();
        int i = 0; // Initialize i to 0
        sum = 100; // Initialize sum to 100
        for (; sum < x; ++i) {
            sum += sum / 100; // Increment sum by 1%
        }
        System.out.println(i); // Output the number of iterations
    }
}
