
import java.util.Scanner;

public class codeforces_678_B{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();  // Take an integer input from the user
        String d = "f";  // Initialize the variable d to "f"
        String ans = "";  // Initialize ans as an empty string

        // Determine if the year is a leap year and initialize ans accordingly
        if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0)) {
            ans = "ly";
        } else {
            ans = "nly";
        }

        // Start an infinite loop to find the next Friday the 13th
        while (true) {
            if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0)) {  // Check if n is a leap year
                if (d.equals("m")) {  // Update d and n based on the current day
                    d = "w";
                    n++;
                } else if (d.equals("t")) {
                    d = "th";
                    n++;
                } else if (d.equals("w")) {
                    d = "f";
                    n++;
                } else if (d.equals("th")) {
                    d = "sa";
                    n++;
                } else if (d.equals("f")) {
                    d = "s";
                    n++;
                } else if (d.equals("sa")) {
                    d = "m";
                    n++;
                } else if (d.equals("s")) {
                    d = "t";
                    n++;
                }
            } else {
                if (d.equals("m")) {
                    d = "t";
                    n++;
                } else if (d.equals("t")) {
                    d = "w";
                    n++;
                } else if (d.equals("w")) {
                    d = "th";
                    n++;
                } else if (d.equals("th")) {
                    d = "f";
                    n++;
                } else if (d.equals("f")) {
                    d = "sa";
                    n++;
                } else if (d.equals("sa")) {
                    d = "s";
                    n++;
                } else if (d.equals("s")) {
                    d = "m";
                    n++;
                }
            }

            // Check if the current day is Friday and the year is a leap year or not
            if (d.equals("f") && ans.equals("ly") && leapyear(n) == "y") {
                break;  // Exit the loop if the condition is met
            } else if (d.equals("f") && ans.equals("nly") && leapyear(n) == "n") {
                break;  // Exit the loop if the condition is met
            }
        }

        System.out.println(n);  // Print the final year after finding the next Friday the 13th
    }

    public static String leapyear(int n) {  // Function to check if a year is a leap year
        if (n % 400 == 0 || (n % 4 == 0 && n % 100!= 0)) {
            return "y";
        } else {
            return "n";
        }
    }
}

