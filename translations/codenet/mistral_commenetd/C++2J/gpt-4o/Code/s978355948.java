import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        // Initialize variables N and X with user input
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int X = scanner.nextInt();

        // Create an ArrayList to store the elements
        ArrayList<Integer> L = new ArrayList<>(N);

        // Read elements of ArrayList L from user input
        for (int i = 0; i < N; i++) {
            L.add(scanner.nextInt());
        }

        // Initialize variable i and d to zero
        int i = 0, d = 0;

        // Loop through the ArrayList L until the sum d exceeds X
        for (; i < N && d <= X; i++) {
            // Add the current element of ArrayList L to the sum d
            d += L.get(i);
        }

        // Print the index of the last element in the ArrayList L that was added to the sum d
        System.out.println(i);
        
        scanner.close();
    }
}

// <END-OF-CODE>
