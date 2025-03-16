public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the input values
        int h1, h2, m1, m2, k;

        // Read input values: start time (h1:m1), end time (h2:m2), and a duration k
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        h1 = scanner.nextInt();
        m1 = scanner.nextInt();
        h2 = scanner.nextInt();
        m2 = scanner.nextInt();
        k = scanner.nextInt();

        // Calculate the total minutes from the start time to the end time
        int ans = (h2 * 60 + m2) - (h1 * 60 + m1);
        
        // Output the result after subtracting the duration k from the total minutes
        System.out.println(ans - k);
    }
}
