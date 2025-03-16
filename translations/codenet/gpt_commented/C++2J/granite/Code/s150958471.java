
import java.util.Scanner;

public class s150958471{
    public static void main(String[] args) {
        // Declare arrays to hold the arrival times for train and bus
        int train[] = new int[2];
        int bus[] = new int[2];

        // Create a Scanner object to read input from the user
        Scanner scanner = new Scanner(System.in);

        // Input the arrival times for the train
        for (int i = 0; i < 2; i++) {
            train[i] = scanner.nextInt();
        }
        // Input the arrival times for the bus
        for (int i = 0; i < 2; i++) {
            bus[i] = scanner.nextInt();
        }

        // Calculate the minimum arrival time between the two times for train and bus,
        // and output the total minimum arrival time
        System.out.println(Math.min(train[0], train[1]) + Math.min(bus[0], bus[1]));

        // Close the Scanner object
        scanner.close();
    }
}
