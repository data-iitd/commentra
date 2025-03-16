public class TimeDifference {
    public static void main(String[] args) {
        // Define the first hour and minute variables from user input
        int h1, m1;
        String[] time1 = System.console().readLine().split(":");
        h1 = Integer.parseInt(time1[0]);
        m1 = Integer.parseInt(time1[1]);

        // Add the hour to the minute value
        m1 += h1 * 60;

        // Define the second hour and minute variables from user input
        int h2, m2;
        String[] time2 = System.console().readLine().split(":");
        h2 = Integer.parseInt(time2[0]);
        m2 = Integer.parseInt(time2[1]);

        // Add the hour to the minute value for the second set of variables
        m2 += h2 * 60;

        // Calculate the difference between the total minutes of the first and second sets of variables
        m2 = m1 - m2;

        // Calculate the remainder of the difference when divided by 1440 (24 hours * 60 minutes)
        m2 %= 1440;

        // Print the result in the format of hours and minutes
        System.out.printf("%02d:%02d\n", m2 / 60, m2 % 60);
    }
}
