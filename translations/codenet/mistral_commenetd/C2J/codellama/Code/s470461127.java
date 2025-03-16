
public class Main {
    public static void main(String[] args) {
        // Declare two integer variables x and y
        int x, y;
        x = 0; y = 0;

        // Read two integers from the user using scanf function and store them in variables x and y respectively
        Scanner sc = new Scanner(System.in);
        x = sc.nextInt();
        y = sc.nextInt();

        // Print the product of x and y and the sum of 2 times x and 2 times y using printf function
        System.out.println(x * y + " " + (2*x) + " " + (2*y));
    }
}

