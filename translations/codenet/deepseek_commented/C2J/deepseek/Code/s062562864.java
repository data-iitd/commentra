public class Main {
    public static void main(String[] args) {

        // Declare integer variables to store input values and intermediate results
        int a, b, c, d, i, j;

        // Create a Scanner object to read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read four integers from the user
        a = scanner.nextInt();
        b = scanner.nextInt();
        c = scanner.nextInt();
        d = scanner.nextInt();

        // Perform multiplication operations and store the results in i and j
        i = a * b;
        j = c * d;

        // Use an if-else statement to compare the results and print the larger one
        if (i > j) {
            System.out.println(i);
        } else {
            System.out.println(j);
        }

        // Close the Scanner object
        scanner.close();
    }
}
