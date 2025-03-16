import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;

public class Main {
    public static void main (String[] args) throws IOException {
        // Create a BufferedReader to read input from the standard input stream
        InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
        BufferedReader in = new BufferedReader(reader);
        
        // Read the first line of input and split it into an array of strings
        String[] str = in.readLine().split(" ");
        
        // Parse the first value as an integer 'n' (number of points)
        int n = Integer.parseInt(str[0]);
        
        // Parse the second value as a double 'd' (distance threshold)
        double d = Integer.parseInt(str[1]);
        
        // Initialize a counter to keep track of points within the distance 'd'
        int cnt = 0;

        // Loop through each point to check its distance from the origin
        for(int i = 0; i < n; i++) {
            // Read the coordinates of the point and split into an array
            str = in.readLine().split(" ");
            
            // Parse the x and y coordinates as doubles
            double x = Integer.parseInt(str[0]);
            double y = Integer.parseInt(str[1]);
            
            // Check if the distance from the origin (0,0) to the point (x,y) is less than or equal to 'd'
            if(Math.sqrt(x * x + y * y) <= d) {
                // Increment the counter if the point is within the distance
                cnt++;
            }
        }
        
        // Output the total count of points that are within the distance 'd'
        System.out.println(cnt);
    }
}
