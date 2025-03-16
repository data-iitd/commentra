import java.util.*; // Importing necessary classes from the java.util package

public class Main {
    // Declaring a static list to hold integers (not used in the current code)
    public static List<Integer> P;

    public static void main(String args[]) {
        // Creating a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);
        
        // Reading the number of elements (N) from the input
        int N = scanner.nextInt();
        
        // Creating a HashMap to store the mapping of integer values to their order of input
        Map<Integer, Integer> idorder = new HashMap<>();

        // Looping through the range from 1 to N to read N integers
        for (int i = 1; i <= N; i++) {
            // Reading an integer A from the input
            int A = scanner.nextInt();
            // Storing the integer A in the map with its order of input (i)
            idorder.put(A, i);
        }

        // Looping through the range from 1 to N to print the order of each integer
        for (int i = 1; i <= N; i++) {
            // Retrieving and printing the order of the integer i from the map
            System.out.print(idorder.get(i));
            // Printing a space after each output
            System.out.print(" ");
        }
    }
}
