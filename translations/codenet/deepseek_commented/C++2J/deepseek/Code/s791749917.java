import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        long H = scanner.nextLong();
        long W = scanner.nextLong(); // Step 1: Reading the values of H and W from the standard input.

        long ans;
        if (H == 1 || W == 1) {
            ans = 1; // Step 2: Handling the special case where either H or W is 1.
        } else {
            long m = H * W; // Step 3: Calculating the total area of the grid.
            if (m % 2 == 0) ans = m / 2; // Step 4: If the area is even, half of it is the answer.
            else ans = m / 2 + 1; // Step 5: If the area is odd, half of it plus one is the answer.
        }
        System.out.println(ans); // Step 6: Outputting the calculated minimum number of cells to be painted.
    }
}
