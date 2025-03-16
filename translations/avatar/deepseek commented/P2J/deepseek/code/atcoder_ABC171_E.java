import java.util.*;
import java.util.stream.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Step 1: Take an integer input N, which represents the number of elements in the list.
        int N = scanner.nextInt();

        // Step 2: Take a list of integers as input and store them in the list 'a'.
        int[] a = Arrays.stream(scanner.next().split(" ")).mapToInt(Integer::parseInt).toArray();

        // Step 3: Calculate the total XOR of all elements in the list 'a' using reduce and XOR operator.
        int total = 0;
        for (int ai : a) {
            total ^= ai;
        }

        // Step 4: Create a new list where each element is the XOR of the original element and the total.
        // Print the new list as a space-separated string.
        String result = Arrays.stream(a)
                              .mapToObj(ai -> String.valueOf(ai ^ total))
                              .collect(Collectors.joining(" "));
        System.out.println(result);
    }
}
