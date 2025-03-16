
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.stream.IntStream;

public class Main {

	public static void main(String[] args) {
		// Try-with-resources statement to ensure proper closing of the Scanner object
		try (Scanner scanner = new Scanner(System.in)) {
			// Read the first integer input
			int n = scanner.nextInt();

			// Create an empty HashSet to store unique integers
			Set<Integer> set = new HashSet<>();

			// Use IntStream.range(0, n) to generate an IntStream of integers from 0 to n-1
			IntStream.range(0, n)
				// Use forEach method to iterate through each integer and add it to the set
				.forEach(i -> set.add(scanner.nextInt()));

			// Print the size of the set
			System.out.println("The set contains " + set.size() + " unique integers.");
		}
		// If any exception occurs during the execution of the try block, it will be caught here
		catch (Exception e) {
			System.out.println("An error occurred: " + e.getMessage());
		}
	}
}