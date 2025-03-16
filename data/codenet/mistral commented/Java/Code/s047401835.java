
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scanner = new Scanner(System.in);

        // Read the first integer `N` from the console
        int N = scanner.nextInt();

        // Create an empty ArrayList named `numbers` to store the next `N` integers
        List<Integer> numbers = new ArrayList<>();

        // Use a for loop to read `N` integers from the console and add them to the `numbers` list
        for (int i = 0; i < N; i++) {
            numbers.add(Integer.parseInt(scanner.next()));
        }

        // Initialize a counter `count` to 0
        int count = 0;

        // Use a do-while loop to perform the following operations until the size of the `numbers` list is not equal to `N` anymore
        do {
            // Use a Java stream to filter the even numbers from the `numbers` list
            List<Integer> evenNumbers = numbers.stream()
                    .filter(i -> (i % 2) == 0)
                    .collect(Collectors.toList());

            // Use the map operation to square each even number
            List<Integer> squaredEvenNumbers = evenNumbers.stream()
                    .map(i -> i * i)
                    .collect(Collectors.toList());

            // Use the collect operation to store the resulting list in the `numbers` list
            numbers = squaredEvenNumbers;

            // If the size of the `numbers` list is equal to `N`, increment the counter `count`
            if (numbers.size() == N) count++;
        } while(numbers.size() != N);

        // Print the value of the counter `count` to the console
        System.out.println(count);
    }
}