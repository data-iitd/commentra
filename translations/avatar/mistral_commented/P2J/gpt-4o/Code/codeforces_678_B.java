import java.util.Scanner;

public class LeapYearChecker {
    
    // Function to check if a year is a leap year
    public static String leapYear(int n) {
        // Check if the year is a leap year by checking if it satisfies the conditions
        if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
            // If the conditions are met, return "y" to indicate that the year is a leap year
            return "y";
        } else {
            // If the conditions are not met, return "n" to indicate that the year is not a leap year
            return "n";
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Take an integer input from the user
        int n = scanner.nextInt();
        
        // Initialize a variable 'd' to keep track of the day of the week for the given year
        String d = "f";
        
        // Check if the given year is a leap year
        String ans;
        if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
            // If the year is a leap year, set the answer to "ly"
            ans = "ly";
        } else {
            // If the year is not a leap year, set the answer to "nly"
            ans = "nly";
        }

        // Keep updating the day of the week and the year until we find the correct answer
        while (true) {
            // Check if the given year is a leap year
            if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
                // If the year is a leap year, update the day of the week accordingly
                switch (d) {
                    case "m":
                        d = "w";
                        n++;
                        break;
                    case "t":
                        d = "th";
                        n++;
                        break;
                    case "w":
                        d = "f";
                        n++;
                        break;
                    case "th":
                        d = "sa";
                        n++;
                        break;
                    case "f":
                        d = "s";
                        n++;
                        break;
                    case "sa":
                        d = "m";
                        n++;
                        break;
                    case "s":
                        d = "t";
                        n++;
                        break;
                }
            } else {
                // If the year is not a leap year, update the day of the week accordingly
                switch (d) {
                    case "m":
                        d = "t";
                        n++;
                        break;
                    case "t":
                        d = "w";
                        n++;
                        break;
                    case "w":
                        d = "th";
                        n++;
                        break;
                    case "th":
                        d = "f";
                        n++;
                        break;
                    case "f":
                        d = "sa";
                        n++;
                        break;
                    case "sa":
                        d = "s";
                        n++;
                        break;
                    case "s":
                        d = "m";
                        n++;
                        break;
                }
            }

            // Check if we have found the correct answer
            if (d.equals("f") && ans.equals("ly") && leapYear(n).equals("y")) {
                // If we have found the correct answer, break out of the loop
                break;
            } else if (d.equals("f") && ans.equals("nly") && leapYear(n).equals("n")) {
                // If we have found the correct answer, break out of the loop
                break;
            }
        }

        // Print the result
        System.out.println(n);
        
        scanner.close();
    }
}

// <END-OF-CODE>
