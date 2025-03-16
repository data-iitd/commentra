import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine()); // Read an integer input N (not used in further calculations)
        int[] a = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray(); // Read a list of integers from input and convert them to an array of integers

        // Calculate the total using the XOR operation across all elements in the array 'a'
        int total = Arrays.stream(a).reduce(0, (acc, ai) -> acc ^ ai);

        // For each element in the array 'a', compute the XOR with 'total' and print the results
        // The results are converted to strings and joined with a space for output
        String result = Arrays.stream(a)
                .mapToObj(ai -> String.valueOf(ai ^ total))
                .collect(Collectors.joining(" "));
        System.out.println(result);
    }
}
