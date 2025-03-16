import java.util.*;

class calArea {
    // Method to calculate the area of a rectangle given its width and height
    int Area(int w, int h) {
        int area = w * h; // Calculate area
        return area; // Return the calculated area
    }
}

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object for user input
        Scanner sc = new Scanner(System.in);
        // Initialize a list to store the dimensions of the rectangles
        List<Integer> arr = new ArrayList<>();
        
        // Loop to read 4 integers from user input (width and height for two rectangles)
        for (int i = 0; i < 4; i++) {
            arr.add(Integer.parseInt(sc.next())); // Parse input and add to the list
        }
        
        // Create an instance of calArea to calculate areas
        calArea ab = new calArea();
        // Calculate the area of the first rectangle
        int area1 = ab.Area(arr.get(0), arr.get(1));
        // Calculate the area of the second rectangle
        int area2 = ab.Area(arr.get(2), arr.get(3));
        
        // Compare the two areas and print the larger one or either if they are equal
        if (area1 > area2) {
            System.out.println(area1); // Print area1 if it is larger
        } else if (area1 < area2) {
            System.out.println(area2); // Print area2 if it is larger
        } else if (area1 == area2) {
            System.out.println(area1); // Print either area if they are equal
        }   
    }
}
