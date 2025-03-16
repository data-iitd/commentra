import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        try (Scanner scanner = new Scanner(System.in)) {
            // Read the number of integers to be inputted
            int n = scanner.nextInt();
            
            // Initialize a HashSet to store unique integers
            Set<Integer> set = new HashSet<>();
            
            // Read 'n' integers from the input and add them to the HashSet
            IntStream.range(0, n).forEach(i -> set.add(scanner.nextInt()));
            
            // Output the size of the HashSet, which represents the count of unique integers
            System.out.println(set.size());
        }
    }
}
