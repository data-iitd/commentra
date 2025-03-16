
public class Main {
    public static void main(String[] args) {
        // Declare two integer variables x and a
        int x, a;

        // Read two integer values from user input and store them in x and a
        Scanner scanner = new Scanner(System.in);
        x = scanner.nextInt();
        a = scanner.nextInt();

        // Check if x is greater than or equal to a
        // If true, print 10; otherwise, print 0
        if (x >= a) {
            System.out.println(10);
        } else {
            System.out.println(0);
        }
    }
}

