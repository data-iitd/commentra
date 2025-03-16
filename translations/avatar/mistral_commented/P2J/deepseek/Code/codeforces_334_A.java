public class Main {
    public static void main(String[] args) {
        // Declare and initialize a variable 'n' with an integer value read from standard input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();

        // Declare and initialize two variables 'i' and 'j' with initial values 1 and 'n * n' respectively
        int i = 1, j = n * n;

        // Start the while loop with the condition 'i < j'
        while (i < j) {
            // Print the current values of 'i' and 'j' on the standard output
            System.out.println(i + " " + j);
            
            // Increment the value of 'i' by 1 in each iteration of the loop
            i++;
            
            // Decrement the value of 'j' by 1 in each iteration of the loop
            j--;
        }
    }
}
