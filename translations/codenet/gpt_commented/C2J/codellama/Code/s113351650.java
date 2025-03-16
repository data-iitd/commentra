
public class Main {

    public static void main(String[] args) {

        // Declare an integer variable 'x' to store user input
        int x;

        // Prompt the user for input and read an integer value into 'x'
        x = Integer.parseInt(args[0]);

        // Check if the input value is 0
        if (x == 0)
            // If true, print "1" to the output
            System.out.println("1");

        // Check if the input value is 1
        if (x == 1)
            // If true, print "0" to the output
            System.out.println("0");

        // Return 0 to indicate successful completion of the program
        return;
    }
}

