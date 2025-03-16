import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Define the number of elements in the list 'A'
        Scanner scanner = new Scanner(System.in);
        int N = Integer.parseInt(scanner.nextLine());

        // Initialize a list 'A' to hold pairs of index and value
        List<Pair> A = new ArrayList<>();

        // Read the input values and populate the list 'A'
        String[] inputs = scanner.nextLine().split(" ");
        for (int i = 0; i < N; i++) {
            A.add(new Pair(i + 1, Integer.parseInt(inputs[i])));
        }

        // Sort the list 'A' based on the second element of each pair (the value)
        Collections.sort(A, Comparator.comparingInt(pair -> pair.value));

        // Extract the first element (index) of each pair in 'A_' into a new list 'A__'
        List<Integer> A__ = new ArrayList<>();
        for (Pair pair : A) {
            A__.add(pair.index);
        }

        // Iterate through the list 'A__' (excluding the last element) and print each index
        for (int i = 0; i < A__.size() - 1; i++) {
            System.out.print(A__.get(i) + " ");
        }

        // Print the last index in 'A__'
        System.out.println(A__.get(A__.size() - 1));
    }

    // Helper class to hold index and value pairs
    static class Pair {
        int index;
        int value;

        Pair(int index, int value) {
            this.index = index;
            this.value = value;
        }
    }
}
// <END-OF-CODE>
