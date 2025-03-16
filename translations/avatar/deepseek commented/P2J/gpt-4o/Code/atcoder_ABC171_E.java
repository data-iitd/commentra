import java.util.*;
import java.util.stream.*;

public class Main {
    public static void main(String[] args) {
        // Step 1: Take an integer input N, which represents the number of elements in the list.
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        // Step 2: Take a list of integers as input and store them in the list 'a'.
        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            a.add(scanner.nextInt());
        }

        // Step 3: Calculate the total XOR of all elements in the list 'a'.
        int total = a.stream().reduce(0, (x, y) -> x ^ y);

        // Step 4: Create a new list where each element is the XOR of the original element and the total.
        List<String> result = a.stream()
                                .map(ai -> String.valueOf(ai ^ total))
                                .collect(Collectors.toList());

        // Print the new list as a space-separated string.
        System.out.println(String.join(" ", result));
    }
}
// <END-OF-CODE>
