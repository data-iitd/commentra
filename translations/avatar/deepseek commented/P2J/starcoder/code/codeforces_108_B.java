
import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // Take input from the user
        sc.nextLine();
        // Read the input, split it into a list of integers, and store it in 'a'
        List<Integer> a = Arrays.asList(sc.nextLine().split(" ")).stream().map(Integer::parseInt).collect(Collectors.toList());
        // Sort the list 'a'
        Collections.sort(a);
        // Iterate through the sorted list starting from the second element
        for (int i = 1; i < a.size(); i++) {
            // Check if the current element is not equal to the previous element
            // and if the current element is less than twice the previous element
            if (a.get(i)!= a.get(i - 1) && a.get(i) < a.get(i - 1) * 2) {
                // If the condition is met, return 'YES'
                System.out.println("YES");
                return;
            }
        }
        // If the loop completes without finding a match, return 'NO'
        System.out.println("NO");
    }
}
