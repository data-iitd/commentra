import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from stdin
        Scanner sc = new Scanner(System.in);

        // Read four integers from stdin and store them in variables a, b, c, and d
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();

        // Perform multiplication operations and store the results in variables i and j
        int i = a * b;
        int j = c * d;

        // Use an if-else statement to compare the results and print the larger one
        if (i > j) {
            System.out.println(i);
        } else {
            System.out.println(j);
        }
    }
}
