import java.util.* ;  // Importing the Java Util Package for using Scanner and HashMap

public class Main {  // Main class declaration
    public static List<Integer> P; // Declaring a static list 'P' of type Integer

    public static void main(String[] args) { // Main method declaration
        Scanner scanner = new Scanner(System.in); // Creating a new Scanner object for user input
        int N; // Declaring an integer variable 'N' to store the number of elements

        // Reading the number of elements from the user input
        N = scanner.nextInt();

        Map<Integer, Integer> idorder = new HashMap<>(); // Declaring and initializing a HashMap 'idorder'

        // Reading the elements and storing their corresponding indices in the HashMap
        for (int i = 1; i <= N; i++) {
            int A = scanner.nextInt(); // Reading an element 'A' from the user input
            idorder.put(A, i); // Storing the index 'i' of the element 'A' in the HashMap
        }

        // Printing the indices of the elements in the order they were read
        for (int i = 1; i <= N; i++) {
            System.out.print(idorder.get(i) + " "); // Printing the index of the current element
        }

        scanner.close(); // Closing the Scanner object to save system resources
    }
}
