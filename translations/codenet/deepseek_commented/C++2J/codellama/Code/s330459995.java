import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Declare variables to store the dimensions of the rectangle and the circle
        int W, H, x, y, r;
        
        // Create a Scanner object to read input from the command line
        Scanner scan = new Scanner(System.in);
        
        // Read the dimensions of the rectangle and the circle from the input
        W = scan.nextInt();
        H = scan.nextInt();
        x = scan.nextInt();
        y = scan.nextInt();
        r = scan.nextInt();
        
        // Check if the circle is outside the rectangle
        if(x - r < 0 || x + r > W || y - r < 0 || y + r > H){
            // If any part of the circle is outside the rectangle, print "No"
            System.out.println("No");
        }
        else {
            // If the circle is completely inside the rectangle, print "Yes"
            System.out.println("Yes");
        }
        
        // Close the Scanner object
        scan.close();
    }
}

