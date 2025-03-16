import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Declare variables to store the dimensions of the rectangle and the circle
        int W, H, x, y, r;
        
        // Read the dimensions of the rectangle and the circle from the input
        Scanner sc = new Scanner(System.in);
        W = sc.nextInt();
        H = sc.nextInt();
        x = sc.nextInt();
        y = sc.nextInt();
        r = sc.nextInt();
        
        // Check if the circle is outside the rectangle
        if(x - r < 0 || x + r > W || y - r < 0 || y + r > H){
            // If any part of the circle is outside the rectangle, print "No"
            System.out.println("No");
        }
        else {
            // If the circle is completely inside the rectangle, print "Yes"
            System.out.println("Yes");
        }
    }
}
