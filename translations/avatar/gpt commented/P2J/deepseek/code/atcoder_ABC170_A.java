import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        List<Integer> a = new ArrayList<>();
        
        // Convert each component to an integer and add to the list 'a'
        for (String s : input) {
            a.add(Integer.parseInt(s));
        }
        
        // Iterate over the list 'a' using index to get the value
        for (int i = 0; i < a.size(); i++) {
            // Check if the current value is zero
            if (a.get(i) == 0) {
                // Print the index (1-based) of the first occurrence of zero
                System.out.println(i + 1);
                // Exit the loop after finding the first zero
                break;
            }
        }
    }
}
