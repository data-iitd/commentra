public class Main {
    public static void main(String[] args) {
        // Declare variables to hold input values
        int a, b, c, d, e, k;

        // Read six integers from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();
        e = scanner.nextInt();
        k = scanner.nextInt();

        // Check if the difference between e and a is less than or equal to k
        // If true, print "Yay!", otherwise print ":("
        if (e - a <= k) {
            System.out.println("Yay!");
        } else {
            System.out.println(":(");
        }
    }
}
