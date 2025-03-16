import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read the number of test cases
        int N = Integer.parseInt(scanner.nextLine());

        // Read the array V of size N
        String[] VArray = scanner.nextLine().split(" ");
        int[] V = new int[N];
        for (int i = 0; i < N; i++) {
            V[i] = Integer.parseInt(VArray[i]);
        }

        // Read the array C of size N
        String[] CArray = scanner.nextLine().split(" ");
        int[] C = new int[N];
        for (int i = 0; i < N; i++) {
            C[i] = Integer.parseInt(CArray[i]);
        }

        // Initialize an empty list to store the differences between V and C
        List<Integer> list = new ArrayList<>();

        // Initialize variables to store the current difference and the sum of differences
        int ans = 0;
        int X = 0;
        int Y = 0;

        // Iterate through each index i from 0 to N-1
        for (int i = 0; i < N; i++) {
            // If the difference between V[i] and C[i] is positive
            if (V[i] - C[i] > 0) {
                // Update X and Y with the respective values from V and C at index i
                X = V[i];
                Y = C[i];
                // Append the difference X-Y to the list
                list.add(X - Y);
                // Update the sum of differences
                ans += X - Y;
            }
        }

        // Print the sum of all the elements in the list
        int sum = 0;
        for (int diff : list) {
            sum += diff;
        }
        System.out.println(sum);

        // Print the sum of all the differences between V and C
        System.out.println(ans);
    }
}
