
public class Main {
    public static void main(String[] args) {
        // Declare variables to hold two integers and the result
        int a, b, s;

        // Read two integers from user input
        Scanner sc = new Scanner(System.in);
        a = sc.nextInt();
        b = sc.nextInt();

        // Calculate the result using the formula: (a*b) - (a + b) + 1
        s = (a * b) - (a + b) + 1;

        // Output the result to the console
        System.out.println(s);
    }
}

