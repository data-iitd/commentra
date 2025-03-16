
public class Main {
    public static void main(String[] args) {
        // Declare two integer variables x and y
        int x, y;

        // Read an integer value from the user and store it in variable x
        Scanner sc = new Scanner(System.in);
        x = sc.nextInt();

        // Calculate the cube of x and store the result in variable y
        y = x * x * x;

        // Print the result (the cube of x) to the console
        System.out.println(y);

        // Return 0 to indicate successful completion of the program
        return 0;
    }
}
