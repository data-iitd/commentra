import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// Read the number of values to be processed
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();

		// Initialize a slice to hold the float64 values
		float[] values = new float[N];

		// Read N float64 values from standard input
		for (int i = 0; i < N; i++) {
			values[i] = sc.nextFloat();
		}

		// Sort the slice of float64 values in ascending order
		sort(values);

		// Variable to hold the generated average value
		float generated;

		// Calculate the average of each pair of adjacent values
		for (int i = 0; i < N-1; i++) {
			generated = (values[i] + values[i+1]) / 2;
			// Update the next value in the slice with the generated average
			values[i+1] = generated;
		}

		// Print the last generated average value
		System.out.println(generated);
	}

	public static void sort(float[] values) {
		for (int i = 0; i < values.length; i++) {
			for (int j = i + 1; j < values.length; j++) {
				if (values[i] > values[j]) {
					float temp = values[i];
					values[i] = values[j];
					values[j] = temp;
				}
			}
		}
	}
}

