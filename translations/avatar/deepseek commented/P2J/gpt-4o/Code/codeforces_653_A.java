import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        int n = scanner.nextInt();  // Take an integer input for the number of elements
        List<Integer> l = new ArrayList<>();  // Create a list to store integers
        
        for (int i = 0; i < n; i++) {
            l.add(scanner.nextInt());  // Take a list of integers as input
        }
        
        Collections.sort(l);  // Sort the list of integers
        
        // Check if there exists any integer i in the list such that i + 1 and i + 2 are also in the list
        for (int i : l) {
            if (l.contains(i + 1) && l.contains(i + 2)) {  // Check if i + 1 and i + 2 are in the list
                System.out.println("YES");  // If found, print 'YES' and break the loop
                return;  // Exit the program
            }
        }
        
        System.out.println("NO");  // If no such integer is found, print 'NO'
    }
}
// <END-OF-CODE>
