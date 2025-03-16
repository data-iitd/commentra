import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

public class Main {
    public static void main(String[] args) {
        // Declare variables for the number of elements (N) and the number of operations (M)
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        // Initialize a list to hold the elements, with a size of 100000
        List<Integer> L = new ArrayList<Integer>(100000);
        int l;

        // Read N integers from input and store them in the list L
        for (int i = 0; i < N; i++) {
            l = sc.nextInt();
            L.add(l);
        }

        // Sort the list L in ascending order
        Collections.sort(L);

        // Declare an iterator for the list
        Iterator<Integer> itr;

        // Perform M operations to modify the list L
        for (int i = 0; i < M; i++) {
            // Get the maximum element from the end of the sorted list
            int max_L = L.get(L.size() - 1);
            
            // If the maximum element is 0, break the loop as no further operations are needed
            if (max_L == 0) {
                break;
            }

            // Halve the maximum element
            max_L /= 2;

            // Find the position to insert the halved value in the sorted list
            itr = L.listIterator(L.size());
            while (itr.hasPrevious()) {
                if (itr.previous() < max_L) {
                    itr.next();
                    break;
                }
            }
            
            // Insert the halved value into the list at the found position
            itr.add(max_L);
            
            // Remove the last element (the original maximum) from the list
            L.remove(L.size() - 1);
        }

        // Calculate the sum of all elements in the list L
        long ans = 0;
        for (int i = 0; i < L.size(); i++) {
            ans += L.get(i);
        }

        // Output the final sum
        System.out.println(ans);
    }
}

