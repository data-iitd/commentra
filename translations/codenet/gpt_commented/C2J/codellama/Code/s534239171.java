
public class Average {
    public static void main(String[] args) {
        // Declare variables to hold two integers and their average
        int a, b, n;

        // Read two integers from user input
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();

        // Calculate the average of the two integers
        n = (a + b) / 2;

        // Print the calculated average
        System.out.println(n);
    }
}

