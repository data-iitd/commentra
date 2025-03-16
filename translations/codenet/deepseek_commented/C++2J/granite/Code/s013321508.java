
import java.util.*;

public class s013321508{

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt(); // Reading two integers, N and M.
        int M = sc.nextInt();

        List<Integer> L = new ArrayList<>(); // Initializing a list L with a size of 100,000.
        int l;
        for (int i = 0; i < N; i++) {
            l = sc.nextInt(); // Reading N integers and populating the list L.
            L.add(l);
        }

        Collections.sort(L); // Sorting the list L in ascending order.

        ListIterator<Integer> itr; // Declaring an iterator for the list L.

        for (int i = 0; i < M; i++) { // Performing M operations.
            int max_L = L.get(L.size() - 1); // Finding the largest element in the list.
            if (max_L == 0) {
                break; // If the largest element is 0, break the loop.
            }

            max_L /= 2; // Halving the largest element.
            itr = Collections.binarySearch(L, max_L); // Finding the position to insert the halved value.
            L.add(itr, max_L); // Inserting the halved value back into the list.
            L.remove(L.size() - 1); // Removing the largest element from the list.
        }

        long ans = L.stream().mapToLong(i -> i).sum(); // Calculating the sum of all elements in the list L.

        System.out.println(ans); // Printing the result.

    }

}

