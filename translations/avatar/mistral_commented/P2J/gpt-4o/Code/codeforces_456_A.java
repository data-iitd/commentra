import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

public class HappyAlex {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter the number of tuples: ");
        int n = Integer.parseInt(scanner.nextLine());
        
        List<int[]> m = new ArrayList<>();
        
        for (int i = 0; i < n; i++) {
            System.out.print("Enter tuple " + (i + 1) + ": ");
            String[] input = scanner.nextLine().split(" ");
            int[] tuple = new int[2];
            tuple[0] = Integer.parseInt(input[0]);
            tuple[1] = Integer.parseInt(input[1]);
            m.add(tuple);
        }
        
        // Sort the list 'm' in descending order based on the second element of the tuples
        Collections.sort(m, new Comparator<int[]>() {
            @Override
            public int compare(int[] a, int[] b) {
                return Integer.compare(b[1], a[1]);
            }
        });
        
        int[] a = m.get(0); // Initialize 'a' with the first tuple in the sorted list
        
        for (int i = 1; i < m.size(); i++) {
            int[] current = m.get(i);
            if (current[1] > a[1]) {
                System.out.println("Happy Alex");
                return; // Exit the program
            }
            a = current; // Update 'a' to the current tuple
        }
        
        // If we have gone through all the tuples without finding one whose second element is greater
        System.out.println("Poor Alex");
        
        scanner.close();
    }
}
// <END-OF-CODE>
