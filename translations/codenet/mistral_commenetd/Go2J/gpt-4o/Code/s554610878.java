import java.util.Scanner;

public class Main {
    // Initialize week array with 7 days of the week
    private static final String[] week = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

    public static void main(String[] args) {
        // Create a scanner to read input
        Scanner scanner = new Scanner(System.in);

        // Read input string from scanner
        String s = getString(scanner);

        // Find index of the given day in week array
        int index = -1;
        for (int i = 0; i < week.length; i++) {
            if (week[i].equals(s)) {
                index = i;
                break;
            }
        }

        // If the given day is not present in the week array, throw an exception
        if (index == -1) {
            throw new IllegalArgumentException("Invalid day of the week");
        }

        // Calculate the number of days until Sunday and print the result
        int daysUntilSunday = 7 - index;
        System.out.println(daysUntilSunday);
    }

    // Function to read a single line of input as string
    private static String getString(Scanner scanner) {
        return scanner.nextLine();
    }
}

// <END-OF-CODE>
