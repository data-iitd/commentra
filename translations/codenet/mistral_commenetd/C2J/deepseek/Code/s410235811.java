public class Main {
    public static void main(String[] args) {
        int n;
        // Declare an integer variable 'n' to store the user input.

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        // Create a Scanner object to read input from the standard input stream.

        n = scanner.nextInt();
        // Use the nextInt method of the Scanner object to read an integer value
        // from the standard input and store it in the variable 'n'.

        if(n % 2 == 0){
            System.out.println(n / 2);
            // If the number 'n' is even, print the value of 'n/2' as the output.
        }
        else{
            System.out.println((n / 2) + 1);
            // If the number 'n' is odd, print the value of '(n/2)+1' as the output.
        }

        scanner.close();
        // Close the Scanner object to free up resources.
    }
}
