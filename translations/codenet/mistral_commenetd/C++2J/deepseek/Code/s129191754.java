import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of elements in the vector
        int n = scanner.nextInt();

        // Initialize a list to store the elements
        List<Integer> a = new ArrayList<>();

        // Read the elements of the list
        for (int i = 0; i < n; i++) {
            a.add(scanner.nextInt());
        }

        // Sort the list in ascending order
        Collections.sort(a);

        // Check if there are any consecutive elements in the sorted list
        for (int i = 0; i < n - 1; i++) {
            // If there are consecutive elements, print "NO" and exit the program
            if (a.get(i).equals(a.get(i + 1))) {
                System.out.println("NO");
                return;
            }
        }

        // If no consecutive elements were found, print "YES"
        System.out.println("YES");
    }
}

