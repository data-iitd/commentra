// Import the Math class and specifically the atan2 and PI constants
import java.lang.Math;

// Read the input from standard input and parse it into two variables: N (number of points) and XY (a list of tuples representing the coordinates of N points)
Scanner scanner = new Scanner(System.in);
int N = scanner.nextInt();
int[][] XY = new int[N][2];
for (int i = 0; i < N; i++) {
    XY[i][0] = scanner.nextInt();
    XY[i][1] = scanner.nextInt();
}

// Transpose the XY list so that it becomes a list of lists, where each inner list contains the x and y coordinates of a point
int[][] XYT = new int[2][N];
for (int i = 0; i < N; i++) {
    XYT[0][i] = XY[i][0];
    XYT[1][i] = XY[i][1];
}

// Iterate through each point in XY and calculate the angles between it and all other points
for (int i = 0; i < N; i++) {
    // Calculate the differences between the x and y coordinates of the current point and all other points
    double[] D = new double[N];
    for (int j = 0; j < N; j++) {
        if (i != j) {
            D[j] = Math.atan2(XYT[0][j] - XYT[0][i], XYT[1][j] - XYT[1][i]);
        }
    }

    // Append the angle between the current point and the first point (wrapped around if it's greater than pi)
    D[N] = D[0] + 2 * Math.PI;

    // Sort the angles
    Arrays.sort(D);

    // Iterate through each pair of consecutive angles and calculate the area of the corresponding sector
    for (int j = 0; j < N; j++) {
        // If the angle between two consecutive points is greater than pi, subtract pi from it and add it to the answer
        if (D[j + 1] - D[j] >= Math.PI) {
            ans += (D[j + 1] - D[j]) - Math.PI;
        }
    }
}

// Print the answer, which is the total area of the sectors divided by the total possible area (2π)
System.out.println(ans / (2 * Math.PI));

