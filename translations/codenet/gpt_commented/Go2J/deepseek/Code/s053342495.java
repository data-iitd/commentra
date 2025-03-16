public class Main {
    public static void main(String[] args) {
        // Declare a variable to hold the day of the month
        int day;

        // Read an integer input from the user representing the day
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        day = scanner.nextInt();

        // Use a switch statement to determine the holiday based on the day
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
