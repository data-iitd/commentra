public class Main {
    public static void main(String[] args) {
        // Declare an integer variable to hold the input seconds
        int in;
        // Declare variables to hold hours, minutes, and seconds
        int h, m, s;

        // Create a Scanner object to read input from the user
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read the total number of seconds from user input
        in = scanner.nextInt();

        // Calculate the number of hours by dividing total seconds by 3600
        h = in / 3600;
        // Update the input seconds to the remainder after extracting hours
        in %= 3600;

        // Calculate the number of minutes by dividing the remaining seconds by 60
        m = in / 60;
        // Update the input seconds to the remainder after extracting minutes
        in %= 60;

        // The remaining seconds are now stored in 'in'
        s = in;

        // Print the result in the format of hours:minutes:seconds
        System.out.println(h + ":" + m + ":" + s);
    }
}
