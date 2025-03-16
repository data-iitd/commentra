import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Input the number of elements (N)
        int N = scanner.nextInt();
        scanner.nextLine(); // Consume the newline
        
        // Input the elements and create a list of tuples (index, value)
        List<int[]> A = new ArrayList<>();
        String[] inputs = scanner.nextLine().split(" ");
        for (int i = 0; i < N; i++) {
            A.add(new int[]{i + 1, Integer.parseInt(inputs[i])});
        }
        
        // Sort the list of tuples based on the integer values
        Collections.sort(A, Comparator.comparingInt(a -> a[1]));
        
        // Extract the indices from the sorted list of tuples
        List<Integer> A__ = new ArrayList<>();
        for (int[] a : A) {
            A__.add(a[0]);
        }
        
        // Print the indices in the required format
        for (int i = 0; i < A__.size() - 1; i++) {
            System.out.print(A__.get(i) + " ");
        }
        System.out.println(A__.get(A__.size() - 1));
        
        scanner.close();
    }
}
// <END-OF-CODE>
