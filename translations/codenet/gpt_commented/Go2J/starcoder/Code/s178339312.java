import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a variable 'x' of type int to store user input
        int x;

        // Read an integer value from standard input and store it in 'x'
        Scanner sc = new Scanner(System.in);
        x = sc.nextInt();

        // Calculate the cube of 'x' and print the result to standard output
        System.out.println(x*x*x);
    }
}
