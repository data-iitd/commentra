import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare a variable named day of type int
        int day;

        // Create a Scanner object to read input from the standard input stream
        Scanner scanner = new Scanner(System.in);

        // Read an integer value from the standard input using scanner.nextInt()
        day = scanner.nextInt();

        // Use a switch statement to determine the name of the day based on the given day number
        switch (day) {
            case 25:
                // If the day is 25, print "Christmas"
                System.out.println("Christmas");
                break;
            case 24:
                // If the day is 24, print "Christmas Eve"
                System.out.println("Christmas Eve");
                break;
            case 23:
                // If the day is 23, print "Christmas Eve Eve"
                System.out.println("Christmas Eve Eve");
                break;
            case 22:
                // If the day is 22, print "Christmas Eve Eve Eve"
                System.out.println("Christmas Eve Eve Eve");
                break;
        }
    }
}
