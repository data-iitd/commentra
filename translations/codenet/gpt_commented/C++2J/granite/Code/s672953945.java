
// Include necessary header files
import java.util.*;

public class s672953945{
    public static void main(String[] args) {
        // Declare a list to store strings and variables for input
        List<String> list = new ArrayList<>();
        int N, L;

        // Read the number of strings (N) and the length of strings (L)
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        L = sc.nextInt();

        // Input N strings from the user and store them in the list
        for(int i = 0; i < N; i++) {
            String s = sc.next();
            list.add(s); // Add the string to the list
        }

        // Sort the list of strings in lexicographical order
        Collections.sort(list);

        // Output the sorted strings
        for(int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i)); // Print each string in the sorted order
        }
        System.out.println(); // Print a newline at the end
    }
}
