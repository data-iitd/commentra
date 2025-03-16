
import java.util.Arrays;
import java.util.Scanner;

public class s954770518{
    public static void main(String[] args) {
        // Declare an array to hold 10 integers
        int[] s = new int[10];

        // Input 10 integers from the user
        Scanner scanner = new Scanner(System.in);
        for(int i = 0; i < 10; i++) {
            s[i] = scanner.nextInt();
        }

        // Sort the array of integers in ascending order
        Arrays.sort(s);

        // Print the three largest integers from the sorted array
        for(int i = 9; i > 6; i--) {
            System.out.println(s[i]);
        }
    }
}
