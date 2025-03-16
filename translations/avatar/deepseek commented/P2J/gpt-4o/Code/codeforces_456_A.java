import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Take an integer input representing the number of elements in the list `m`
        List<int[]> m = new ArrayList<>();  // Create a list of integer arrays `m`

        // Create a list of lists `m` where each sublist contains two integers
        for (int i = 0; i < n; i++) {
            int[] pair = new int[2];
            pair[0] = scanner.nextInt();
            pair[1] = scanner.nextInt();
            m.add(pair);
        }

        // Sort the list `m` in descending order based on the second element of each sublist
        Collections.sort(m, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return Integer.compare(b[1], a[1]);
            }
        });

        int[] a = m.get(0);  // Assign the first element of the sorted list `m` to the variable `a`

        // Iterate over the rest of the elements in `m` starting from the second element
        for (int i = 1; i < m.size(); i++) {
            int[] current = m.get(i);
            if (current[1] > a[1]) {  // Check if the second element of the current element `i` is greater than the second element of the variable `a`
                System.out.println("Happy Alex");  // If true, print "Happy Alex" and break out of the loop
                return;  // Exit the program
            }
            a = current;  // If false, assign the current element `i` to the variable `a`
        }

        // If the loop completes without breaking
        System.out.println("Poor Alex");  // Print "Poor Alex"
    }
}
// <END-OF-CODE>
