import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare arrays to hold the arrival times for train and bus
        int[] train = new int[2];
        int[] bus = new int[2];

        // Input the arrival times for the train
        Scanner scanner = new Scanner(System.in);
        train[0] = scanner.nextInt();
        train[1] = scanner.nextInt();

        // Input the arrival times for the bus
        bus[0] = scanner.nextInt();
        bus[1] = scanner.nextInt();

        // Calculate the minimum arrival time between the two times for train and bus,
        // and output the total minimum arrival time
        System.out.println((train[0] < train[1] ? train[0] : train[1]) + (bus[0] < bus[1] ? bus[0] : bus[1]));
    }
}

