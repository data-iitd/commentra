public class Main {
    public static void main(String[] args) {
        // Step 3: Declare variables to store input values
        int a, b, c, d, e, k;

        // Step 4: Read input values from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();
        e = scanner.nextInt();
        k = scanner.nextInt();

        // Step 5: Calculate the difference between e and a and check if it is less than or equal to k
        if (e - a <= k) {
            System.out.println("Yay!");
        } else {
            System.out.println(":(");
        }

        // Step 7: Return 0 to indicate successful execution
    }
}
