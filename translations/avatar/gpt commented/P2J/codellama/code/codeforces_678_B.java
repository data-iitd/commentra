public class LeapYear {
    public static void main(String[] args) {
        // Read an integer input from the user representing the year
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        // Initialize the day variable to 'f' (Friday)
        String d = "f";

        // Check if the initial year n is a leap year and set the answer accordingly
        if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
            String ans = "ly";  // 'ly' indicates leap year
        } else {
            String ans = "nly";  // 'nly' indicates non-leap year
        }

        // Infinite loop to determine the next occurrence of a specific day
        while (true) {
            // If the current year n is a leap year
            if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
                // Update the day variable and increment the year based on the current day
                if (d.equals("m")) {
                    d = "w";  // Monday to Wednesday
                    n += 1;
                } else if (d.equals("t")) {
                    d = "th";  // Tuesday to Thursday
                    n += 1;
                } else if (d.equals("w")) {
                    d = "f";  // Wednesday to Friday
                    n += 1;
                } else if (d.equals("th")) {
                    d = "sa";  // Thursday to Saturday
                    n += 1;
                } else if (d.equals("f")) {
                    d = "s";  // Friday to Sunday
                    n += 1;
                } else if (d.equals("sa")) {
                    d = "m";  // Saturday to Monday
                    n += 1;
                } else if (d.equals("s")) {
                    d = "t";  // Sunday to Tuesday
                    n += 1;
                }
            } else {
                // If the current year n is not a leap year, update the day variable accordingly
                if (d.equals("m")) {
                    d = "t";  // Monday to Tuesday
                    n += 1;
                } else if (d.equals("t")) {
                    d = "w";  // Tuesday to Wednesday
                    n += 1;
                } else if (d.equals("w")) {
                    d = "th";  // Wednesday to Thursday
                    n += 1;
                } else if (d.equals("th")) {
                    d = "f";  // Thursday to Friday
                    n += 1;
                } else if (d.equals("f")) {
                    d = "sa";  // Friday to Saturday
                    n += 1;
                } else if (d.equals("sa")) {
                    d = "s";  // Saturday to Sunday
                    n += 1;
                } else if (d.equals("s")) {
                    d = "m";  // Sunday to Monday
                    n += 1;
                }
            }

            // Check if we have reached a Friday and the leap year condition matches the answer
            if (d.equals("f") && ans.equals("ly") && leapyear(n) == "y") {
                break;  // Exit the loop if it's a leap year and it's Friday
            } else if (d.equals("f") && ans.equals("nly") && leapyear(n) == "n") {
                break;  // Exit the loop if it's not a leap year and it's Friday
            }
        }

        // Print the resulting year
        System.out.println(n);
    }

    // Determine if the given year n is a leap year
    public static String leapyear(int n) {
        if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
            return "y";  // Return 'y' if it is a leap year
        } else {
            return "n";  // Return 'n' if it is not a leap year
        }
    }
}

