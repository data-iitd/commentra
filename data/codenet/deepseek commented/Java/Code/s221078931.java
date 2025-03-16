import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	public static void main(String[] args) throws IOException {
		// Create a BufferedReader to read input from the console
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		// Initialize an array to hold 40,000 IntegralRect objects
		IntegralRect rects[] = new IntegralRect[40000];
		
		// Populate the array with IntegralRect objects for rectangles 1x1 to 200x200
		for(int i = 0; i < 200; i++){
			for(int j = 0; j < 200; j++){
				rects[i*200 + j] = new IntegralRect(i + 1, j + 1);
			}
		}
		
		// Sort the array of rectangles based on their diagonals
		Arrays.sort(rects);
		
		// Debugging output to check the sorted rectangles
//		for(int i = 0; i < 100; i++){
//			System.out.println(rects[i].height + " "+ rects[i].width +" " + rects[i].diagonal());
//		}

		// Main loop to read rectangle dimensions and find the smallest diagonal larger rectangle
		while(true){
			String[] tmpArray = br.readLine().split(" ");

			int h = Integer.parseInt(tmpArray[0]);
			int w = Integer.parseInt(tmpArray[1]);

			if(h == 0 && w == 0){
				break;
			}

			// Create a new IntegralRect object with the read dimensions
			IntegralRect tmpRect = new IntegralRect(h, w);
			int diag = tmpRect.diagonal();
//			System.out.println(diag);
			
			// Find and print the smallest rectangle with a larger diagonal
			for(int i = 0; i < rects.length ; i++){
//				System.out.println(rects[i].diagonal());
				if(rects[i].compareTo(tmpRect) > 0){
					System.out.println(rects[i].height+" "+rects[i].width);
					break;
				}
			}
		}
	}

}

class IntegralRect implements Comparable<IntegralRect> {
	int height;
	int width;
	
	// Constructor to initialize the height and width of the rectangle
	public IntegralRect(int h, int w){
		this.height = h;
		this.width = w;
	}

	// Method to calculate the diagonal of the rectangle
	public int diagonal(){
		if(height >= width){
			return Integer.MAX_VALUE;
		}
		return this.height*this.height + this.width*this.width;
	}

	// Method to compare rectangles based on their diagonals
	@Override
	public int compareTo(IntegralRect o) {
		int d1 = this.diagonal();
		int d2 = o.diagonal();
		return d1 == d2 ? this.height - o.height : d1 - d2;
	}
}
