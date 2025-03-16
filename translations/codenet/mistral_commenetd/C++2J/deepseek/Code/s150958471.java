public class Main {
    public static void main(String[] args) {
        // Declare two arrays to store the number of passengers in each train and bus
        int[] train = new int[2];
        int[] bus = new int[2];

        // Read the number of passengers in each train from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        train[0] = scanner.nextInt();
        train[1] = scanner.nextInt();

        // Read the number of passengers in each bus from the user
        bus[0] = scanner.nextInt();
        bus[1] = scanner.nextInt();

        // Calculate the total number of passengers
        System.out.println(Math.min(train[0], train[1]) + Math.min(bus[0], bus[1]));

        // Output the total number of passengers in both train and bus
    }
}
