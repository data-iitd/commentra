
import java.util.Arrays;  // Import Arrays to facilitate sorting of tuples
import java.util.Comparator;  // Import Comparator to facilitate sorting of tuples

public class atcoder_ABC142_C{
    public static void main(String[] args) {
        // Read the number of elements from user input
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();

        // Read the elements from user input, creating a list of tuples (index, value)
        Tuple[] A = new Tuple[N];
        for (int i = 0; i < N; i++) {
            int value = scanner.nextInt();
            A[i] = new Tuple(i + 1, value);
        }

        // Sort the list of tuples based on the second item (the value) in each tuple
        Arrays.sort(A, Comparator.comparingInt(Tuple::getValue));

        // Extract the first item (the original index) from each sorted tuple into a new list
        int[] A_ = new int[N];
        for (int i = 0; i < N; i++) {
            A_[i] = A[i].getIndex();
        }

        // Print the indices of the sorted values, separated by spaces
        for (int i = 0; i < N - 1; i++) {  // Loop through all but the last index
            System.out.print(A_[i] + " ");  // Print each index followed by a space
        }

        // Print the last index without a trailing space
        System.out.println(A_[N - 1]);
    }

    // Define a Tuple class to represent a tuple of two integers
    static class Tuple {
        private final int index;
        private final int value;

        public Tuple(int index, int value) {
            this.index = index;
            this.value = value;
        }

        public int getIndex() {
            return index;
        }

        public int getValue() {
            return value;
        }
    }
}

