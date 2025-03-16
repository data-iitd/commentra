public class SheepAndWolves {
    public static void main(String[] args) {
        // Declare variables to hold the number of sheep and wolves
        int sheep;
        int wolf;

        // Read the number of sheep and wolves from user input
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        sheep = scanner.nextInt();
        wolf = scanner.nextInt();

        // Check if the number of wolves is greater than or equal to the number of sheep
        if (wolf >= sheep) {
            // If there are more wolves than sheep, it's unsafe
            System.out.println("unsafe");
        } else {
            // If there are fewer wolves than sheep, it's safe
            System.out.println("safe");
        }

        // Return 0 to indicate successful execution of the program
        scanner.close();
    }
}
