// Function to check if a year is a leap year
public static String leapyear(int n) {
    // Check if the year is a leap year by checking if it satisfies the conditions
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        // If the conditions are met, return "y" to indicate that the year is a leap year
        return "y";
    } else {
        // If the conditions are not met, return "n" to indicate that the year is not a leap year
        return "n";
    }
}

// Take an integer input from the user
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();

// Initialize a variable 'd' to keep track of the day of the week for the given year
String d = "f";

// Check if the given year is a leap year
if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
    // If the year is a leap year, set the answer to "ly"
    String ans = "ly";
} else {
    // If the year is not a leap year, set the answer to "nly"
    String ans = "nly";
}

// Keep updating the day of the week and the year until we find the correct answer
while (true) {
    // Check if the given year is a leap year
    if (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0)) {
        // If the year is a leap year, update the day of the week accordingly
        if (d.equals("m")) {
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
        // If the year is not a leap year, update the day of the week accordingly
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

    // Check if we have found the correct answer
    if (d.equals("f") && ans.equals("ly") && leapyear(n).equals("y")) {
        // If we have found the correct answer, break out of the loop
        break;
    } else if (d.equals("f") && ans.equals("nly") && leapyear(n).equals("n")) {
        // If we have found the correct answer, break out of the loop
        break;
    }
}

// Print the result
System.out.println(n);

