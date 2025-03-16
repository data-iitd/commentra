import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();  // Read the number of elements in the list
        ArrayList<Integer> l = new ArrayList<>();  // Initialize an empty list to store the elements

        // Read n elements and append them to the list l
        for (int i = 0; i < n; i++) {
            l.add(scanner.nextInt());
        }

        int ans = n - 1;  // Initialize ans to n - 1, which will store the final answer
        int last = 0;  // Initialize last to 0, used to track the last element in the list

        // Iterate over each element in the list l
        for (int i : l) {
            ans += Math.abs(last - i) + 1;  // Update ans based on the current element and last element
            last = i;  // Update last to the current element
        }

        System.out.println(ans);  // Print the final answer
    }
}
