import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Take the number of rows as input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        // Initialize a list to store the rows
        List<List<String>> s = new ArrayList<>();

        // Read each row and append it to the list 's'
        for (int i = 0; i < n; i++) {
            String line = scanner.nextLine();
            String[] elements = line.split(" ");
            s.add(Arrays.asList(elements));
        }

        // Initialize flags and empty lists 'd1' and 'd2'
        int flag = 0;
        List<String> d1 = new ArrayList<>();
        List<String> d2 = new ArrayList<>();
        Set<String> rem = new HashSet<>();

        // Iterate through each element in the list 's'
        for (int i = 0; i < n; i++) {
            // Iterate through each element in the same row
            for (int j = 0; j < n; j++) {
                // If the current indices are the same, append the element to 'd1'
                if (i == j) {
                    d1.add(s.get(i).get(j));
                }
                // If the current indices are reverse of each other, append the element to 'd2'
                if (i == n - j - 1) {
                    d2.add(s.get(i).get(j));
                }
                // If the current indices are not the same and not reverse, add the element to 'rem' set
                if (i != j && i != n - j - 1) {
                    rem.add(s.get(i).get(j));
                }
            }
        }

        // Check if the size of 'rem' set is not equal to 1
        if (rem.size() != 1) {
            // If the condition is true, print 'NO' and exit
            System.out.println("NO");
            return;
        }
        // Check if 'd1' and 'd2' lists are equal
        else if (!d1.equals(d2)) {
            // If the condition is true, print 'NO' and exit
            System.out.println("NO");
            return;
        }
        // Check if all elements in 'd1' are the same
        else if (new HashSet<>(d1).size() != 1) {
            // If the condition is true, print 'NO' and exit
            System.out.println("NO");
            return;
        }
        // Check if all elements in 'd1' are present in 'rem' set
        else if (rem.equals(new HashSet<>(d1))) {
            // If the condition is true, print 'NO' and exit
            System.out.println("NO");
            return;
        }
        // If all the above conditions are false, print 'YES'
        else {
            System.out.println("YES");
        }
    }
}
// <END-OF-CODE>
