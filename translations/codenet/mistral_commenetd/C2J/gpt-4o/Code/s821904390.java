import java.util.Scanner; // We import the Scanner class for reading input

public class TimeConverter { // We define a public class named TimeConverter
    public static void main(String[] args) { // The main method is the entry point of the program
        Scanner scanner = new Scanner(System.in); // We create a Scanner object to read input
        int in; // We declare an integer variable named 'in' to store the input
        int h, m, s; // We declare three integer variables named 'h', 'm', and 's' to store hours, minutes, and seconds respectively

        in = scanner.nextInt(); // We read an integer input from the standard input and store it in the 'in' variable

        h = in / 3600; // We calculate the number of hours by dividing the input by the total number of seconds in an hour (3600) and storing the quotient in 'h'
        in %= 3600; // We calculate the remaining seconds by taking the modulus of the input with 3600 and storing the result in 'in'

        m = in / 60; // We calculate the number of minutes by dividing the remaining seconds by 60 and storing the quotient in 'm'
        in %= 60; // We calculate the remaining seconds by taking the modulus of the remaining seconds with 60 and storing the result in 'in'

        s = in; // We store the remaining seconds in 's'

        System.out.printf("%d:%d:%d\n", h, m, s); // We print the hours, minutes, and seconds in the format "HH:MM:SS" using the printf function

        scanner.close(); // We close the scanner to free up resources
    }
} // End of the TimeConverter class
// <END-OF-CODE>
