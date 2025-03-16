
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;

public class Main {
	public static void main (String[] args) throws IOException{
		// Initialize input stream reader and buffered reader
		InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
		BufferedReader in = new BufferedReader(reader);

		// Read the first line of input containing number of points and radius
		String[] str = in.readLine().split(" ");
		// Parse the first element of the string array as integer representing number of points
		int n = Integer.parseInt(str[0]);
		// Parse the second element of the string array as double representing the radius
		double d = Double.parseDouble(str[1]);
		// Initialize counter for points within the circle
		int cnt = 0;

		// Loop through each point
		for(int i=0; i < n; i++) {
			// Read the next line of input containing x and y coordinates of a point
			str = in.readLine().split(" ");
			// Parse the first element of the string array as double representing x coordinate
			double x = Double.parseDouble(str[0]);
			// Parse the second element of the string array as double representing y coordinate
			double y = Double.parseDouble(str[1]);
			// Check if the point is within the circle
			if(isPointWithinCircle(x, y, d)) {
				// If yes, increment the counter
				cnt++;
			}
		}
		// Print the result
		System.out.println(cnt);
	}

	// Helper method to check if a point is within a circle with given center and radius
	private static boolean isPointWithinCircle(double x, double y, double radius) {
		return Math.sqrt(x*x+y*y) <= radius;
	}
}