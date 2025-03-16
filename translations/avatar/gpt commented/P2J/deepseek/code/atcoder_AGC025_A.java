import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String n = scanner.nextLine();

        // Define a list of string representations of powers of ten
        String[] a = {"10", "100", "1000", "10000", "100000"};

        // Convert the input string into a list of integers and calculate the sum
        int newSum = 0;
        for (char digit : n.toCharArray()) {
            newSum += Character.getNumericValue(digit);
        }

        // Check if the input is one of the predefined values in the list 'a'
        boolean isPredefined = false;
        for (String value : a) {
            if (n.equals(value)) {
                isPredefined = true;
                break;
            }
        }

        // If the input matches one of the predefined values, print 10
        if (isPredefined) {
            System.out.println(10);
        } else {
            // If the input does not match, print the calculated sum
            System.out.println(newSum);
        }
    }
}
