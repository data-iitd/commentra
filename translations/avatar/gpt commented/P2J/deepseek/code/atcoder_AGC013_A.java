import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        List<Integer> A = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            A.add(scanner.nextInt());
        }
        scanner.close();

        // Remove consecutive duplicates from the list
        List<Integer> uniqueA = new ArrayList<>();
        uniqueA.add(A.get(0));
        for (int i = 1; i < N; i++) {
            if (!A.get(i).equals(A.get(i - 1))) {
                uniqueA.add(A.get(i));
            }
        }

        // Update N to the new length of A after removing duplicates
        N = uniqueA.size();

        // Initialize the index and answer counter
        int i = 1;
        int ans = 0;

        // Loop through the list to count the number of peaks and valleys
        while (i < N - 1) {
            // Check if the current element is a peak or a valley
            if (uniqueA.get(i - 1) < uniqueA.get(i) && uniqueA.get(i) > uniqueA.get(i + 1) ||
                uniqueA.get(i - 1) > uniqueA.get(i) && uniqueA.get(i) < uniqueA.get(i + 1)) {
                ans += 1; // Increment the answer for each peak/valley found
                i += 1;   // Skip the next element to avoid double counting
            }
            i += 1; // Move to the next element
        }

        // Print the total count of peaks and valleys plus one
        System.out.println(ans + 1);
    }
}
