import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.stream.IntStream;

public class Main {

	// Main method is the entry point of the Java application
	public static void main(String[] args) {
		try (Scanner scanner = new Scanner(System.in)) {
			// Read the number of elements
			int n = scanner.nextInt();
			// Initialize a set to store unique elements
			Set<Integer> set = new HashSet<>();
			// Add elements to the set using a stream
			IntStream.range(0, n).forEach(i -> set.add(scanner.nextInt()));
			// Print the number of unique elements
			System.out.println(set.size());
		}
	}
}
