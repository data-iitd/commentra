import java.util.Scanner;

public class LeapYearFinder {
    
    // Function to check if a year is a leap year
    public static String leapYear(int n) {
        if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
            return "y";
        } else {
            return "n";
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Enter a year: ");
        int n = scanner.nextInt();  // Take an integer input from the user
        String d = "f";  // Initialize the variable d to "f"
        
        // Determine if the year is a leap year and initialize ans accordingly
        String ans = (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) ? "ly" : "nly";

        // Start an infinite loop to find the next Friday the 13th
        while (true) {
            if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {  // Check if n is a leap year
                switch (d) {
                    case "m":
                        d = "w";
                        n += 1;
                        break;
                    case "t":
                        d = "th";
                        n += 1;
                        break;
                    case "w":
                        d = "f";
                        n += 1;
                        break;
                    case "th":
                        d = "sa";
                        n += 1;
                        break;
                    case "f":
                        d = "s";
                        n += 1;
                        break;
                    case "sa":
                        d = "m";
                        n += 1;
                        break;
                    case "s":
                        d = "t";
                        n += 1;
                        break;
                }
            } else {
                switch (d) {
                    case "m":
                        d = "t";
                        n += 1;
                        break;
                    case "t":
                        d = "w";
                        n += 1;
                        break;
                    case "w":
                        d = "th";
                        n += 1;
                        break;
                    case "th":
                        d = "f";
                        n += 1;
                        break;
                    case "f":
                        d = "sa";
                        n += 1;
                        break;
                    case "sa":
                        d = "s";
                        n += 1;
                        break;
                    case "s":
                        d = "m";
                        n += 1;
                        break;
                }
            }

            // Check if the current day is Friday and the year is a leap year or not
            if (d.equals("f") && ans.equals("ly") && leapYear(n).equals("y")) {
                break;  // Exit the loop if the condition is met
            } else if (d.equals("f") && ans.equals("nly") && leapYear(n).equals("n")) {
                break;  // Exit the loop if the condition is met
            }
        }

        System.out.println(n);  // Print the final year after finding the next Friday the 13th
        scanner.close();
    }
}

// <END-OF-CODE>
