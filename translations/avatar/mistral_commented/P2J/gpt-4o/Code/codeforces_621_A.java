import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Take an integer 'n' as input
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        // Create a list 'lst' of 'n' integers taken as input
        List<Integer> lst = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            lst.add(scanner.nextInt());
        }

        // Sort the list 'lst' in ascending order
        Collections.sort(lst);

        // Reverse the sorted list 'lst'
        Collections.reverse(lst);

        // Initialize odd_digits counter 'od' to 0
        int od = 0;

        // Iterate through each integer 'i' in the list 'lst'
        for (int i : lst) {
            // If the integer 'i' is odd, increment 'od' counter
            if ((i & 1) == 1) {
                od++;
            }
        }

        // Initialize sum and ok variables
        int sum = 0;
        boolean ok = false;

        // Iterate through each index 'i' in the range of 'n'
        for (int i = 0; i < n; i++) {
            // If the integer at index 'i' in the list 'lst' is even, add it to the sum 'sum'
            if (lst.get(i) % 2 == 0) {
                sum += lst.get(i);
            } 
            // If the integer at index 'i' in the list 'lst' is odd and either 'ok' is true or 'od' is greater than 1
            else {
                if (ok || od > 1) {
                    sum += lst.get(i);
                    od--;
                    ok = !ok;
                }
            }
        }

        // Print the final sum
        System.out.println(sum);
    }
}
// <END-OF-CODE>
