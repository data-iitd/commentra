import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the standard input stream
        Scanner scanner = new Scanner(System.in);

        // Declare a variable named x of type int
        int x;

        // Read an integer value from the standard input and assign it to the variable x
        x = scanner.nextInt();

        // Print the result of x cubed (x*x*x)
        System.out.println(x * x * x);
    }
}

