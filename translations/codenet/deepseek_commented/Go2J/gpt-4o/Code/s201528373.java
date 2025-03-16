import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the number of elements, the target sum, and the list of integers
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        List<Integer> l = new ArrayList<>();

        // Read n integers from the standard input and append them to the list l
        for (int i = 0; i < n; i++) {
            int tmpL = scanner.nextInt();
            l.add(tmpL);
        }

        // Initialize variables to keep track of the sum and the result
        int tmpSum = 0;
        int rs = 0;

        // Iterate over the list l, updating the sum and checking the condition
        for (int i = 0; i < l.size(); i++) {
            tmpSum += l.get(i);
            // If the sum is less than or equal to x, update the result
            if (tmpSum <= x) {
                rs = i + 2;
            } else {
                break;
            }
        }

        // Print the result
        System.out.println(rs);
    }
}

// <END-OF-CODE>
