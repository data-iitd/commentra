import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        List<Integer> L = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        
        // Take the first input from the user.
        scanner.nextLine();
        
        int r = 1; // Initialize the variable r to 1.
        String[] firstInput = scanner.nextLine().split(" ");
        
        for (String k : firstInput) {
            // Multiply the string '1' by the integer value of the string and append the result to the list L.
            int count = Integer.parseInt(k);
            for (int i = 0; i < count; i++) {
                L.add(r);
            }
            r++; // Increment r by 1 for the next iteration.
        }
        
        // Take the second input from the user.
        scanner.nextLine();
        String[] secondInput = scanner.nextLine().split(" ");
        
        for (String j : secondInput) {
            // For each string, print the element at the index specified by the integer value of the string minus one from the list L.
            System.out.println(L.get(Integer.parseInt(j) - 1));
        }
        
        scanner.close();
    }
}
// <END-OF-CODE>
