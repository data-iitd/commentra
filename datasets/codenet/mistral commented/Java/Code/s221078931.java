
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException {
		// Initialize BufferedReader to read input from System.in
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		// Create an array of IntegralRect objects with given dimensions
		IntegralRect rects[] = new IntegralRect[40000];
		for (int i = 0; i < 200; i++) {
			for (int j = 0; j < 200; j++) {
				// Create a new IntegralRect object with given (i+1, j+1) dimensions
				rects[i * 200 + j] = new IntegralRect(i + 1, j + 1);
			}
		}
		// Sort the array of IntegralRect objects based on their diagonals
		Arrays.sort(rects);

		// Debugging code to print the first 100 rectangles' diagonals
//		for (int i = 0; i < 100; i++) {
//			System.out.println(rects[i].height + " " + rects[i].width + " " + rects[i].diagonal());
//		}

		// Main loop to read input and find the closest rectangle to the given dimensions
		while (true) {
			String[] tmpArray = br.readLine().split(" ");

			// Parse the input dimensions h and w from the input string
			int h = Integer.parseInt(tmpArray[0]);
			int w = Integer.parseInt(tmpArray[1]);

			// Check if the input dimensions are zero, indicating the end of input
			if (h == 0 && w == 0) {
				break;
			}

			// Create a new IntegralRect object with given dimensions h and w
			IntegralRect tmpRect = new IntegralRect(h, w);

			// Find the closest rectangle in the sorted array and print its dimensions
			for (int i = 0; i < rects.length; i++) {
				if (rects[i].compareTo(tmpRect) > 0) {
					System.out.println(rects[i].height + " " + rects[i].width);
					break;
				}
			}
		}
	}

	// IntegralRect class definition
	static class IntegralRect implements Comparable<IntegralRect> {
		int height;
		int width;

		// Constructor to initialize height and width
		public IntegralRect(int h, int w) {
			this.height = h;
			this.width = w;
		}

		// Method to calculate the diagonal of the rectangle
		public int diagonal() {
			if (height >= width) {
				return Integer.MAX_VALUE;
			}
			return height * height + width * width;
		}

		// Implement Comparable interface to compare two rectangles based on their diagonals
		@Override
		public int compareTo(IntegralRect o) {
			int d1 = this.diagonal();
			int d2 = o.diagonal();
			return d1 == d2 ? this.height - o.height : d1 - d2;
		}
	}
}

