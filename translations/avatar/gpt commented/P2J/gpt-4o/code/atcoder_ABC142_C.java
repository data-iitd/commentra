import java.util.*;

public class SortIndices {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of elements from user input
        int N = Integer.parseInt(scanner.nextLine());
        
        // Read the elements from user input, creating a list of pairs (index, value)
        List<Pair> A = new ArrayList<>();
        String[] inputs = scanner.nextLine().split(" ");
        for (int i = 0; i < N; i++) {
            A.add(new Pair(i + 1, Integer.parseInt(inputs[i])));
        }
        
        // Sort the list of pairs based on the value
        Collections.sort(A, Comparator.comparingInt(pair -> pair.value));
        
        // Extract the indices from the sorted pairs into a new list
        List<Integer> A_ = new ArrayList<>();
        for (Pair pair : A) {
            A_.add(pair.index);
        }
        
        // Print the indices of the sorted values, separated by spaces
        for (int i = 0; i < A_.size() - 1; i++) {
            System.out.print(A_.get(i) + " ");  // Print each index followed by a space
        }
        
        // Print the last index without a trailing space
        System.out.println(A_.get(A_.size() - 1));
        
        scanner.close();
    }
    
    // Helper class to store index and value pairs
    static class Pair {
        int index;
        int value;
        
        Pair(int index, int value) {
            this.index = index;
            this.value = value;
        }
    }
}
//<END-OF-CODE>
