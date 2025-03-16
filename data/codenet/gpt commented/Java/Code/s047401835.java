import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);

        // Read the number of integers to be processed
        int N = scanner.nextInt();
        // Initialize a list to store the integers
        List<Integer> numbers = new ArrayList<>();

        // Read N integers from the input and add them to the list
        for (int i = 0; i < N; i++) {
            numbers.add(Integer.parseInt(scanner.next()));
        }

        // Initialize a counter to track the number of iterations
        int count = 0;

        // Continue processing the list while its size remains equal to N
        do {
            // Filter the list to keep only even numbers and divide each by 2
            numbers = numbers.stream()
                    .filter(i -> (i % 2) == 0) // Keep only even numbers
                    .map(i -> i / 2)          // Divide each even number by 2
                    .collect(Collectors.toList()); // Collect the results back into a list
            
            // If the size of the list remains the same as the original, increment the count
            if (numbers.size() == N) count++;
        } while(numbers.size() == N); // Repeat until the size of the list changes

        // Print the total number of iterations where the list size remained constant
        System.out.println(count);
    }
}
