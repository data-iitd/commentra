public class Main {
    public static void main(String[] args) {
        // Declare an integer variable to store the total seconds
        int S;

        // Create a Scanner object to read user input
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read the total seconds from user input
        S = scanner.nextInt();

        // Calculate hours, minutes, and seconds from the total seconds
        // and print them in the format HH:MM:SS
        System.out.println(
           (S / 3600) + ":" + 
           ((S % 3600) / 60) + ":" + 
           (S % 60));

        // Close the scanner object
        scanner.close();
    }
}
