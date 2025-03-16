import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    static final int SIZE = (int) (1e5 * 2) + 13; // Define the size of the vector

    static List<Integer> a = new ArrayList<>(); // Initialize an empty list 'a' to store the frequency count of each element
    static List<Integer> cnt = new ArrayList<>(Collections.nCopies(SIZE, 0)); // Initialize a list 'cnt' of size 'SIZE' to store the frequency count of each element

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Declare an integer 'n' to read input
        int k = scanner.nextInt(); // Declare an integer 'k' to read input

        for (int i = 0; i < n; ++i) { // Loop through the input elements
            int x = scanner.nextInt(); // Declare an integer 'x' to read an element from the standard input
            cnt.set(x, cnt.get(x) + 1); // Increment the frequency count of the element 'x' in the list 'cnt'
        }

        for (int i = 0; i < cnt.size(); ++i) { // Loop through all elements in the list 'cnt'
            if (cnt.get(i) > 0) // If the frequency count of an element is greater than zero
                a.add(cnt.get(i)); // Add the frequency count to the list 'a'
        }

        int ans = 0; // Initialize an integer 'ans' to store the sum of the first 'k' frequency counts

        Collections.sort(a); // Sort the list 'a' in ascending order

        int m = a.size() - k; // Calculate the index of the last frequency count to be considered

        for (int i = 0; i < m; ++i) { // Loop through the first 'k' frequency counts and add them to the variable 'ans'
            ans += a.get(i);
        }

        System.out.println(ans); // Print the result 'ans' to the standard output
    }
}
