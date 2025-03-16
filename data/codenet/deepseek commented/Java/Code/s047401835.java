import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Read the integer N from the user input
        int N = scanner.nextInt();
        
        // Create an empty list to store the numbers
        List<Integer> numbers = new ArrayList();

        // Read N integers from the user input and add them to the list
        for (int i = 0; i < N; i++) {
            numbers.add(Integer.parseInt(scanner.next()));
        }

        // Initialize a counter to keep track of the number of iterations
        int count = 0;

        // Enter a loop that continues until the size of the list `numbers` changes
        do {
            // Filter out the even numbers and divide them by 2
            numbers = numbers.stream()
                    .filter(i -> (i % 2) == 0)
                    .map(i -> i / 2)
                    .collect(Collectors.toList());
            
            // Increment the counter if the size of the list remains the same
            if (numbers.size() == N) count++;
        } while(numbers.size() == N);

        // Print the count
        System.out.println(count);
    }
}
