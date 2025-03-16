import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

    public static void main(String[] args) throws IOException {
        // Create a BufferedReader to read input from the console
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // Initialize an array to hold IntegralRect objects
        IntegralRect rects[] = new IntegralRect[40000];
        
        // Populate the array with IntegralRect objects for all combinations of height and width from 1 to 200
        for(int i = 0; i < 200; i++){
            for(int j = 0; j < 200; j++){
                rects[i * 200 + j] = new IntegralRect(i + 1, j + 1);
            }
        }
        
        // Sort the array of IntegralRect objects based on their diagonal values
        Arrays.sort(rects);
        
        // Uncomment the following block for debugging purposes to print the first 100 rectangles
        // for(int i = 0; i < 100; i++){
        //     System.out.println(rects[i].height + " " + rects[i].width + " " + rects[i].diagonal());
        // }

        // Continuously read input until a terminating condition is met
        while(true){
            // Read a line of input and split it into height and width
            String[] tmpArray = br.readLine().split(" ");

            // Parse height and width from the input
            int h = Integer.parseInt(tmpArray[0]);
            int w = Integer.parseInt(tmpArray[1]);

            // Check for the termination condition (both height and width are zero)
            if(h == 0 && w == 0){
                break;
            }

            // Create a new IntegralRect object with the input height and width
            IntegralRect tmpRect = new IntegralRect(h, w);
            int diag = tmpRect.diagonal();
            // Uncomment the following line for debugging purposes to print the diagonal
            // System.out.println(diag);
            
            // Find the first rectangle in the sorted array that is larger than the input rectangle
            for(int i = 0; i < rects.length; i++){
                // Uncomment the following line for debugging purposes to print the diagonal of each rectangle
                // System.out.println(rects[i].diagonal());
                if(rects[i].compareTo(tmpRect) > 0){
                    // Print the height and width of the found rectangle
                    System.out.println(rects[i].height + " " + rects[i].width);
                    break;
                }
            }
        }
    }
}

// Class representing an integral rectangle with height and width
class IntegralRect implements Comparable<IntegralRect> {
    int height; // Height of the rectangle
    int width;  // Width of the rectangle
    
    // Constructor to initialize the height and width of the rectangle
    public IntegralRect(int h, int w){
        this.height = h;
        this.width = w;
    }

    // Method to calculate the diagonal of the rectangle
    public int diagonal(){
        // If height is greater than or equal to width, return a maximum value to avoid comparison
        if(height >= width){
            return Integer.MAX_VALUE;
        }
        // Return the sum of squares of height and width
        return this.height * this.height + this.width * this.width;
    }

    // Method to compare this rectangle with another rectangle based on diagonal and height
    @Override
    public int compareTo(IntegralRect o) {
        // Calculate diagonals for comparison
        int d1 = this.diagonal();
        int d2 = o.diagonal();
        // Compare based on diagonal values, and if equal, compare based on height
        return d1 == d2 ? this.height - o.height : d1 - d2;
    }
}
