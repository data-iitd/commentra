import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Input the number of elements (N)
        int N = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        // Input the elements and create a list of tuples
        List<int[]> A = new ArrayList<>();
        String[] elements = scanner.nextLine().split(" ");
        for (int i = 0; i < N; i++) {
            A.add(new int[]{i + 1, Integer.parseInt(elements[i])});
        }

        // Sort the list of tuples based on the integer values
        A.sort(Comparator.comparingInt(a -> a[1]));

        // Extract the indices from the sorted list of tuples
        List<Integer> A__ = A.stream()
                             .map(a -> a[0])
                             .collect(Collectors.toList());

        // Print the indices in the required format
        for (int i = 0; i < A__.size() - 1; i++) {
            System.out.print(A__.get(i) + " ");
        }
        System.out.println(A__.get(A__.size() - 1));
    }
}
