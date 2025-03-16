import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare an integer variable to hold the input value
        int x;

        // Read an integer value from the user and store it in variable x
        Scanner in = new Scanner(System.in);
        x = in.nextInt();

        // Calculate the cube of the input value and print the result
        System.out.println(x*x*x);

        // Return 0 to indicate that the program finished successfully
        return 0;
    }
}
