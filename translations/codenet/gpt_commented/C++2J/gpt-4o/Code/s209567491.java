import java.util.Scanner;

public class ChocolateConsumption {
    public static void main(String[] args) {
        // Declare variables for number of friends (N), days (D), and initial chocolates (X)
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int D = scanner.nextInt();
        int X = scanner.nextInt();

        // Array to hold the chocolate consumption rate for each friend
        int[] A = new int[101];
        
        // Input the chocolate consumption rates for each friend
        for (int i = 0; i < N; i++) {
            A[i] = scanner.nextInt();
        }

        // Initialize the total number of chocolates with the initial amount
        int num_of_chocolate = 0;

        // Loop through each friend to calculate the number of chocolates they will consume
        for (int i = 0; i < N; i++) {
            // Counter for the number of days
            int counter = 0;

            // Calculate how many chocolates can be consumed within the given days
            for (int j = 0; ; j++) {
                // Calculate the total days required to consume chocolates
                int days = j * A[i] + 1;
                // If the calculated days are within the limit, increment the counter
                if (days <= D) {
                    counter++;
                } else {
                    // Break the loop if the days exceed the limit
                    break;
                }
            }
            // Add the count of chocolates consumed by this friend to the total
            num_of_chocolate += counter;
        }

        // Add the initial chocolates to the total count
        num_of_chocolate += X;

        // Output the total number of chocolates
        System.out.println(num_of_chocolate);
        
        scanner.close();
    }
}

// <END-OF-CODE>
