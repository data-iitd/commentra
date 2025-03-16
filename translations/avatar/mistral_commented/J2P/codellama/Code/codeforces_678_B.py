
import java.sql.Timestamp; // Importing the Timestamp class from the java.sql package
import java.util.*; // Importing the util package

public class Main {

  // Creating a new Scanner object to read input from the standard input stream
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    // Reading an integer value from the user input
    int y = in.nextInt();

    // Checking if the given year is a leap year or not
    boolean leap = check_leap(y);

    // Initializing the sum variable to 0 and mod variable to 0
    int sum = 0;
    int mod = 0;

    // Starting the loop from the year + 1
    for (int i = y + 1; ; i++) {

      // Checking if the current year is a leap year or not
      if (check_leap(i)) {

        // If the current year is a leap year and the previous year was also a leap year,
        // then print the current year and exit the loop
        sum += 366;
        if ((leap && check_leap(i)) || (!leap && !check_leap(i))) {
          System.out.println(i);
          return;
        }

      } else {

        // If the current year is not a leap year, then add 365 to the sum
        sum += 365;

      }

      // Checking if the sum is divisible by 7
      if (sum % 7 == 0) {

        // If the current year is a leap year and the previous year was also a leap year,
        // or if the current year is not a leap year and the previous year was not a leap year,
        // then continue to the next iteration of the loop
        if ((leap && check_leap(i)) || (!leap && !check_leap(i))) {
          continue;
        }

        // If the conditions are not met, then print the current year and exit the loop
        System.out.println(i);
        return;

      }

    }

  }

  // A static method to check if a given year is a leap year or not
  static boolean check_leap(int y) {

    // Returning true if the given year is divisible by 400, or if it is divisible by 4 and not divisible by 100, but not divisible by 100 if the century is not divisible by 4
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);

  }

}

