public class Main {
    public static void main(String[] args) {
        // Declare an integer variable named S
        int S;

        // Create a Scanner object to read input from the standard input stream
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        // Read an integer value from the standard input using the Scanner object
        S = scanner.nextInt();

        // Close the Scanner object
        scanner.close();

        // Check if the value of S is less than 60
        if (S < 60) {
            // If the condition is true, print the time in the format "0:0:S"
            System.out.println("0:0:" + S);
        }
        // Else if the value of S is less than 3600 (1 hour)
        else if (S < 3600) {
            // Calculate the number of minutes by dividing the value of S by 60
            // Print the time in the format "0:M:S"
            System.out.println("0:" + (S / 60) + ":" + (S % 60));
        }
        // Else if the value of S is greater than or equal to 3600
        else {
            // Calculate the number of hours by dividing the value of S by 3600
            // Calculate the number of minutes by finding the remainder of S when divided by 60
            // Calculate the number of seconds by finding the remainder of the remainder when divided by 60
            // Print the time in the format "H:M:S"
            System.out.println((S / 3600) + ":" + ((S % 3600) / 60) + ":" + ((S % 60) % 60));
        }
    }
}
