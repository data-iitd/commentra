import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int[] Num;
        Num = new int[11]; // Initialize an array with 11 elements
        Scanner n = new Scanner(System.in); // Create a Scanner object to read input

        // Read 10 integers from the user and store them in the array
        for (int i = 0; i < 10; i++) {
            Num[i] = n.nextInt();
        }

        // Sort the array in descending order using bubble sort
        for (int a = 9; a >= 0; a--) {
            for (int b = 0; b < a; b++) {
                if (Num[b] < Num[b + 1]) {
                    // Swap the elements if they are out of order
                    int temp = Num[b];
                    Num[b] = Num[b + 1];
                    Num[b + 1] = temp;
                }
            }
        }

        // Output the largest three numbers
        System.out.println(Num[0]); // Print the largest number
        System.out.println(Num[1]); // Print the second largest number
        System.out.println(Num[2]); // Print the third largest number
    }
}
