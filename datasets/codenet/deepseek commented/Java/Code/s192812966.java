
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Initialize Scanner to read input from the user
		Scanner scanner = new Scanner(System.in);
		
		// Read width, height, and number of obstacles
		int w = scanner.nextInt(), h = scanner.nextInt(), n = scanner.nextInt();
		
		// Initialize arrays to store obstacle coordinates and types
		int[] x = new int[n];
		int[] y = new int[n];
		int[] a = new int[n];
		
		// Initialize boundaries for the area
		int xmax = w, xmin = 0;
		int ymax = h, ymin = 0;
		
		// Read each obstacle's coordinates and type, and update boundaries
		for(int i = 0; i < n; i++) {
			x[i] = scanner.nextInt();
			y[i] = scanner.nextInt();
			a[i] = scanner.nextInt();
			switch(a[i]) {
				case 1:
					// Update minimum x boundary if necessary
					xmin = Math.max(xmin, x[i]);
					break;
				case 2:
					// Update maximum x boundary if necessary
					xmax = Math.min(xmax, x[i]);
					break;
				case 3:
					// Update minimum y boundary if necessary
					ymin = Math.max(ymin, y[i]);
					break;
				case 4:
					// Update maximum y boundary if necessary
					ymax = Math.min(ymax, y[i]);
					break;
			}
		}
		
		// Calculate final width and height, ensuring no overlap
		w = Math.max(xmax - xmin, 0);
		h = Math.max(ymax - ymin, 0);
		
		// Output the area of the remaining space
		System.out.println(w * h);
	}
}

