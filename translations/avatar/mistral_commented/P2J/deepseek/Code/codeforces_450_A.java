import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements 'n' and the modulus 'm'
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine(); // Consume the newline

        // Initialize an empty list 'l' to store the elements
        List<Integer> l = new ArrayList<>();

        // Read the elements of the list 'l'
        for (int i = 0; i < n; i++) {
            l.add(scanner.nextInt());
        }

        // Initialize an empty list 'l2' to store the quotient of each element in 'l' divided by 'm'
        List<Integer> l2 = new ArrayList<>();

        // Iterate through each element 'i' in the list 'l'
        for (int i : l) {
            // Check if the element 'i' is divisible by 'm'. If yes, append the quotient (integer division) to 'l2'. If not, append the quotient plus one.
            if (i % m == 0) {
                l2.add(i / m);
            } else {
                l2.add(i / m + 1);
            }
        }

        // Find the maximum quotient in 'l2'
        int mx = l2.stream().max(Integer::compare).get();

        // Iterate through each index 'i' from 0 to 'n-1' in the list 'l2'
        int ind = -1;
        for (int i = 0; i < n; i++) {
            // Check if the quotient at index 'i' in 'l2' is equal to the maximum quotient 'mx'. If yes, store the index 'i' in the variable 'ind'.
            if (l2.get(i) == mx) {
                ind = i;
                break; // Exit the loop once the index is found
            }
        }

        // Print the index 'ind' plus one (since the indices in Java start from 0)
        System.out.println(ind + 1);
    }
}

