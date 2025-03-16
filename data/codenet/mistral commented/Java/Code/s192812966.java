import java.util.Scanner; // Importing the Scanner class for user input

public class Main { // Defining the Main class

	public static void main(String[] args) { // Defining the main method
		Scanner scanner = new Scanner(System.in); // Creating a new Scanner object for user input
		int w = scanner.nextInt(), h = scanner.nextInt(), n = scanner.nextInt(); // Reading the width, height, and number of shapes from user input

		// Allocating arrays for x, y coordinates and area sizes of shapes
		int[] x = new int[n];
		int[] y = new int[n];
		int[] a = new int[n];

		// Initializing the minimum and maximum x and y coordinates and the width and height of the output rectangle
		int xmin = 0, xmax = w, ymin = 0, ymax = h;

		// Reading the x, y coordinates and area sizes of shapes from user input and updating the minimum and maximum coordinates accordingly
		for(int i=0;i<n;i++){
			x[i] = scanner.nextInt();
			y[i] = scanner.nextInt();
			a[i] = scanner.nextInt();

			// Updating the minimum and maximum x and y coordinates based on the shape type
			switch(a[i]){
				case 1:
					xmin = Math.max(xmin, x[i]); // Finding the minimum x coordinate among all shapes with type 1
					break;
				case 2:
					xmax = Math.min(xmax, x[i]); // Finding the maximum x coordinate among all shapes with type 2
					break;
				case 3:
					ymin = Math.max(ymin, y[i]); // Finding the minimum y coordinate among all shapes with type 3
					break;
				case 4:
					ymax = Math.min(ymax, y[i]); // Finding the maximum y coordinate among all shapes with type 4
					break;
			}
		}

		// Calculating the width and height of the output rectangle based on the minimum and maximum coordinates
		w = Math.max(xmax-xmin, 0);
		h = Math.max(ymax-ymin, 0);

		// Printing the area of the output rectangle
		System.out.println(w*h);
	}

}
