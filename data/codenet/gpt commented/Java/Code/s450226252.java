import java.util.Scanner;

class Main {
    public static void main(String[] args) {
    
        // Create a Scanner object to read input from the standard input (console)
        Scanner stdIn = new Scanner(System.in);
        
        // Read a short integer value from the user input
        short r = stdIn.nextShort();
        
        // Check if the input value is less than 1200
        if (r < 1200) {
            // If true, print "ABC" and exit the program
            System.out.println("ABC");
            return;
        }
        
        // Check if the input value is less than 2800
        if (r < 2800) {
            // If true, print "ARC" and exit the program
            System.out.println("ARC");
            return;
        }
        
        // If the input value is 2800 or greater, print "AGC"
        System.out.println("AGC");
    }
}
