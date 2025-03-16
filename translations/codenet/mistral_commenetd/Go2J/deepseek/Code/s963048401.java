import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the array
        int n = scanner.nextInt();

        // Initialize an array list to store the elements
        List<Integer> as = new ArrayList<>();

        // Read the elements of the array into the as list
        for (int i = 0; i < n; i++) {
            as.add(scanner.nextInt());
        }

        // Initialize an empty list xs to store the unique elements
        List<Integer> xs = new ArrayList<>();
        xs.add(as.get(0));

        // Iterate through the array and add unique elements to the xs list
        for (int j = 1; j < n; j++) {
            // Binary search to find the index where the current element should be inserted in the xs list
            int idx = Collections.binarySearch(xs, as.get(j));

            // If the current element is not already present in the xs list, add it
            if (idx < 0) {
                idx = -(idx + 1);
                if (idx == xs.size()) {
                    xs.add(as.get(j));
                } else {
                    // Otherwise, replace the element at the found index with the current element
                    xs.set(idx, as.get(j));
                }
            }
        }

        // Print the length of the xs list
        System.out.println(xs.size());
    }
}

