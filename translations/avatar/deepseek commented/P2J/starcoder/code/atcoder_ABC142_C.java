
import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input the number of elements (N)
        int N = sc.nextInt();

        // Input the elements and create a list of tuples
        List<Integer> A = new ArrayList<Integer>();
        for (int i = 0; i < N; i++) {
            A.add(sc.nextInt());
        }

        // Sort the list of tuples based on the integer values
        Collections.sort(A, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                return a - b;
            }
        });

        // Extract the indices from the sorted list of tuples
        List<Integer> A_ = new ArrayList<Integer>();
        for (int i = 0; i < N; i++) {
            A_.add(A.get(i));
        }

        // Print the indices in the required format
        for (int i = 0; i < N - 1; i++) {
            System.out.print(A_.get(i) + " ");
        }
        System.out.println(A_.get(N - 1));
    }
}

