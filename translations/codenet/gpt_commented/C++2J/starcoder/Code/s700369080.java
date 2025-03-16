import java.util.*;

public class Main {
    public static void main(String[] args) {
        // Declare variables to hold the coordinates of two points
        long x1, x2, y1, y2;
        
        // Input the coordinates of the two points from the user
        Scanner sc = new Scanner(System.in);
        x1 = sc.nextLong();
        y1 = sc.nextLong();
        x2 = sc.nextLong();
        y2 = sc.nextLong();
        
        // Calculate the differences in x and y coordinates
        long dx = x2 - x1; // Difference in x-coordinates
        long dy = y2 - y1; // Difference in y-coordinates
        
        // Calculate the coordinates of the two new points that form a rectangle
        long x3 = x2 - dy; // x-coordinate of the third point
        long y3 = y2 + dx; // y-coordinate of the third point
        long x4 = x1 - dy; // x-coordinate of the fourth point
        long y4 = y1 + dx; // y-coordinate of the fourth point
        
        // Output the coordinates of the two new points
        System.out.println(x3 + " " + y3 + " " + x4 + " " + y4);
    }
}

