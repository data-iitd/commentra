import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt(); // Read the number of elements in the array A
        List<Long> A = new ArrayList<>();
        for(int i=0;i<N;++i) A.add(scanner.nextLong()); // Read the elements of the array A
        Collections.sort(A, Collections.reverseOrder()); // Sort the array A in descending order
        long max = Long.MAX_VALUE; // Initialize max with a large value
        int index = -1;
        for(int i=1;i<N;++i) { // Iterate through the array to find the optimal pair
            if(max>Math.abs(A.get(0)-2*A.get(i))) { // Check if the current difference is smaller than the previous minimum
                max = Math.abs(A.get(0)-2*A.get(i)); // Update the minimum difference
                index = i; // Store the index of the current element
            }
        }
        System.out.println(A.get(0) + " " + A.get(index)); // Output the first and the found optimal pair
    }
}
