
import java.util.*;

class calArea {
    // Define a class named calArea with a method named Area that takes two integers as arguments and returns their product as the area.
    int Area(int w, int h) {
        int area = w * h;
        return area;
    }
}

public class Main {

    public static void main(String[] args) {
        // Create a Scanner object to read input from the console.
        Scanner sc = new Scanner(System.in);
        
        // Create an empty ArrayList named arr to store the width and height of two rectangles.
        List<Integer> arr = new ArrayList<>();
        
        // Use a for loop to read four integers from the console and add them to the arr list.
        for (int i = 0; i < 4; i++) {
            arr.add(Integer.parseInt(sc.next()));
        }
        
        // Create an instance of the calArea class named ab.
        calArea ab = new calArea();
        
        // Calculate the area of the first rectangle using the Area method and store it in a variable named area1.
        int area1 = ab.Area(arr.get(0), arr.get(1));
        
        // Calculate the area of the second rectangle using the Area method and store it in a variable named area2.
        int area2 = ab.Area(arr.get(2), arr.get(3));
        
        // Use an if statement to compare the areas and print the larger one. If they are equal, print the first one (as it was calculated first).
        if (area1 > area2) {
            System.out.println(area1);
        } else if (area1 < area2) {
            System.out.println(area2);
        } else if (area1 == area2) {
            System.out.println(area1);
        }
    }
}