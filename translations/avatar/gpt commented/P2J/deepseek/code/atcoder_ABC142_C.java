import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements from user input
        int N = scanner.nextInt();
        scanner.nextLine();  // Consume the newline character
        
        // Read the elements from user input, creating a list of tuples (index, value)
        String[] input = scanner.nextLine().split(" ");
        List<Tuple> A = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            A.add(new Tuple(i + 1, Integer.parseInt(input[i])));
        }
        
        // Sort the list of tuples based on the second item (the value) in each tuple
        Collections.sort(A, new Comparator<Tuple>() {
            @Override
            public int compare(Tuple t1, Tuple t2) {
                return Integer.compare(t1.value, t2.value);
            }
        });
        
        // Extract the first item (the original index) from each sorted tuple into a new list
        List<Integer> A__ = new ArrayList<>();
        for (Tuple tuple : A) {
            A__.add(tuple.index);
        }
        
        // Print the indices of the sorted values, separated by spaces
        for (int i = 0; i < A__.size() - 1; i++) {
            System.out.print(A__.get(i) + " ");
        }
        System.out.println(A__.get(A__.size() - 1));
    }
    
    // Define a Tuple class to hold the index and value
    static class Tuple {
        int index;
        int value;
        
        Tuple(int index, int value) {
            this.index = index;
            this.value = value;
        }
    }
}
