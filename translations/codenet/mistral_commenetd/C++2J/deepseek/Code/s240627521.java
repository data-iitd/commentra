import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Variable to store the number of elements in the vector
        List<Long> A = new ArrayList<>(); // Declare and initialize a list A of size N with default-constructed elements
        for(int i=0;i<N;++i) { // Iterate through the range [0, N) and read each element into the list
            A.add(scanner.nextLong());
        }
        Collections.sort(A, Collections.reverseOrder()); // Sort the list A in descending order
        int index = 0; // Variable to store the index of the second smallest element
        long max = Long.MAX_VALUE; // Initialize the maximum difference to an infinite value
        for(int i=1;i<N;++i) { // Iterate through the range [1, N)
            if(max > Math.abs(A.get(0) - 2 * A.get(i))) { // Check if the current difference is greater than the maximum difference
                max = Math.abs(A.get(0) - 2 * A.get(i)); // Update the maximum difference if it is
                index = i; // Update the index of the second smallest element
            }
        }
        System.out.println(A.get(0) + " " + A.get(index)); // Output the smallest and second smallest elements
    }
}

