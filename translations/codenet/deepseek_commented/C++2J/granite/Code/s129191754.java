
import java.util.*; // Import necessary classes for input/output operations and other utilities

public class s129191754{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Create a scanner object for input
        int n = sc.nextInt(); // Read an integer n
        List<Integer> a = new ArrayList<>(); // Create a list to store the integers
        for (int i = 0; i < n; i++) {
            a.add(sc.nextInt()); // Read n integers and add them to the list
        }
        Collections.sort(a); // Sort the list in ascending order
        for (int i = 0; i < n - 1; i++) {
            if (a.get(i).equals(a.get(i + 1))) { // Check for duplicates
                System.out.println("NO"); // If duplicates are found, print "NO" and exit
                return;
            }
        }
        System.out.println("YES"); // If no duplicates are found, print "YES"
    }
}
