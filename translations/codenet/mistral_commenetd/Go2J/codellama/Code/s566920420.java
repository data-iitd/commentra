
public class Main {
    public static void main(String[] args) {
        // Declare a variable named "a" of type int
        int a;

        // Read a value of type int from the standard input and store it in the variable "a"
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextInt();

        // Calculate the result of the expression "a + a*a + a*a*a"
        int result = a + a*a + a*a*a;

        // Print the result to the standard output
        System.out.println(result);

        // End of code
    }
}

