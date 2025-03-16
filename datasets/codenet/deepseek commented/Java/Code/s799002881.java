import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;

public class Main {
	public static void main (String[] args) throws IOException{
	    // Set up the input stream to read from the standard input with UTF-8 encoding
	    InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
	    // Create a BufferedReader to read input lines
	    BufferedReader in = new BufferedReader(reader);
	    
	    // Read the first line of input, split it by spaces, and parse the first number as 'n' and the second as 'd'
	    String[] str = in.readLine().split(" ");
	    int n = Integer.parseInt(str[0]);
	    double d = Integer.parseInt(str[1]);
	    
	    // Initialize a counter to keep track of points within the specified distance
	    int cnt = 0;

	    // Loop through 'n' times to read each point's coordinates
	    for(int i=0; i < n; i++) {
	        // Read the next line, split it by spaces, and parse the coordinates as 'x' and 'y'
	        str = in.readLine().split(" ");
	        double x = Integer.parseInt(str[0]);
	        double y = Integer.parseInt(str[1]);
	        
	        // Calculate the distance of the point from the origin
	        if(Math.sqrt(x*x+y*y)<=d) {
	            // If the distance is within 'd', increment the counter
	            cnt++;
	        }
	    }
	    
	    // Output the final count of points within the specified distance
	    System.out.println(cnt);
	}
}
