import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

    // Function to read a single integer from standard input
    static int I() {
        Scanner scanner = new Scanner(System.in);
        return scanner.nextInt();
    }

    // Function to read a list of integers from standard input
    static List<Integer> LI() {
        Scanner scanner = new Scanner(System.in);
        List<Integer> list = new ArrayList<>();
        while (scanner.hasNextInt()) {
            list.add(scanner.nextInt());
        }
        return list;
    }

    public static void main(String[] args) {
        // Read the number of elements
        int N = I();

        // Read the list of integers, sort it in descending order
        List<Integer> S = LI();
        Collections.sort(S, Collections.reverseOrder());

        // Initialize a flag list to track which elements have been used
        boolean[] flag = new boolean[S.size()];

        // Initialize the current list with the largest element
        List<Integer> cur = new ArrayList<>();
        cur.add(S.get(0));

        // Mark the first element as used
        flag[0] = true;

        // Iterate N times to build the current list
        for (int i = 0; i < N; i++) {
            int j = 0;  // Index for the current list
            int jM = cur.size();  // Length of the current list

            // Try to find the next largest unused element
            for (int k = 0; k < S.size(); k++) {
                // Check if the current element is unused and smaller than the last added element
                if (!flag[k] && S.get(k) < cur.get(j)) {
                    cur.add(S.get(k));  // Add the element to the current list
                    j++;  // Move to the next index in the current list
                    flag[k] = true;  // Mark this element as used

                    // If we have added enough elements, break out of the loop
                    if (j == jM) {
                        break;
                    }
                }
            }

            // If we couldn't find a suitable element, print "No" and return
            if (j != jM) {
                System.out.println("No");
                return;
            }

            // Sort the current list in descending order for the next iteration
            Collections.sort(cur, Collections.reverseOrder());
        }

        // If we successfully built the list, print "Yes"
        System.out.println("Yes");
    }
}
