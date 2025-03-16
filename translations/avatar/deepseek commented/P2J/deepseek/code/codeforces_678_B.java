public class LeapYearFriday {
    public static void main(String[] args) {
        // Function to check if a year is a leap year
        boolean leapyear(int n) {
            if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
                return true;
            } else {
                return false;
            }
        }

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();  // Take an integer input from the user
        String d = "f";  // Initialize the variable d to "f"

        // Determine if the year is a leap year and initialize ans accordingly
        String ans;
        if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
            ans = "ly";
        } else {
            ans = "nly";
        }

        // Start an infinite loop to find the next Friday the 13th
        while (true) {
            if (leapyear(n)) {  // Check if n is a leap year
                if (d.equals("m")) {  // Update d and n based on the current day
                    d = "w";
                    n += 1;
                } else if (d.equals("t")) {
                    d = "th";
                    n += 1;
                } else if (d.equals("w")) {
                    d = "f";
                    n += 1;
                } else if (d.equals("th")) {
                    d = "sa";
                    n += 1;
                } else if (d.equals("f")) {
                    d = "s";
                    n += 1;
                } else if (d.equals("sa")) {
                    d = "m";
                    n += 1;
                } else if (d.equals("s")) {
                    d = "t";
                    n += 1;
                }
            } else {
                if (d.equals("m")) {
                    d = "t";
                    n += 1;
                } else if (d.equals("t")) {
                    d = "w";
                    n += 1;
                } else if (d.equals("w")) {
                    d = "th";
                    n += 1;
                } else if (d.equals("th")) {
                    d = "f";
                    n += 1;
                } else if (d.equals("f")) {
                    d = "sa";
                    n += 1;
                } else if (d.equals("sa")) {
                    d = "s";
                    n += 1;
                } else if (d.equals("s")) {
                    d = "m";
                    n += 1;
                }
            }

            // Check if the current day is Friday and the year is a leap year or not
            if (d.equals("f") && ans.equals("ly") && leapyear(n)) {
                break;  // Exit the loop if the condition is met
            } else if (d.equals("f") && ans.equals("nly") && !leapyear(n)) {
                break;  // Exit the loop if the condition is met
            }
        }

        System.out.println(n);  // Print the final year after finding the next Friday the 13th
    }
}
