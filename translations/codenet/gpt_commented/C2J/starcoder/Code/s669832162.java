import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the month and day values for two dates
        int m1, d1, m2, d2;

        // Read input values for the two dates (month and day)
        Scanner input = new Scanner(System.in);
        m1 = input.nextInt();
        d1 = input.nextInt();
        m2 = input.nextInt();
        d2 = input.nextInt();

        // Compare the months of the two dates
        if (m1!= m2) 
            // If the months are different, print "1"
            System.out.println("1");
        else 
            // If the months are the same, print "0"
            System.out.println("0");
    }
}
