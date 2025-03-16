

import java.util.Arrays;
import java.util.Comparator;

public class atcoder_ABC142_C{
    public static void main(String[] args) {
        // Input the number of elements (N)
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        // Input the elements and create a list of tuples
        Tuple[] A = new Tuple[N];
        for (int i = 0; i < N; i++) {
            A[i] = new Tuple(i + 1, sc.nextInt());
        }

        // Sort the list of tuples based on the integer values
        Arrays.sort(A, Comparator.comparingInt(Tuple::getValue));

        // Extract the indices from the sorted list of tuples
        int[] A_ = new int[N];
        for (int i = 0; i < N; i++) {
            A_[i] = A[i].getIndex();
        }

        // Print the indices in the required format
        for (int i = 0; i < N - 1; i++) {
            System.out.print(A_[i] + " ");
        }
        System.out.println(A_[N - 1]);
    }

    static class Tuple {
        private int index;
        private int value;

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

Translate the above Java code to C++ and end with comment "