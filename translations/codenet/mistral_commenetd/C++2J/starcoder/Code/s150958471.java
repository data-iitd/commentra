
import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Declare two arrays to store the number of passengers in each train and bus
        int[] train = new int[2];
        int[] bus = new int[2];

        // Read the number of passengers in each train from the user
        Scanner sc = new Scanner(System.in);
        train[0] = sc.nextInt();
        train[1] = sc.nextInt();

        // Comment: Read the number of passengers in the first and second train from the user

        // Read the number of passengers in each bus from the user
        bus[0] = sc.nextInt();
        bus[1] = sc.nextInt();

        // Comment: Read the number of passengers in the first and second bus from the user

        // Calculate the total number of passengers
        System.out.println((train[0] < train[1]? train[0] : train[1]) + (bus[0] < bus[1]? bus[0] : bus[1]));

        // Comment: Output the total number of passengers in both train and bus
    }
}

