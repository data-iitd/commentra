import java.util.Scanner;

public class IntegerDistancePairs {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of points (n) and the number of dimensions (d)
        int n = scanner.nextInt();
        int d = scanner.nextInt();
        
        // Declare a 2D array to store the coordinates of the points
        int[][] point = new int[n + 1][d + 1];
        
        // Input the coordinates for each point
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= d; j++) {
                point[i][j] = scanner.nextInt();
            }
        }
        
        // Initialize a counter for the number of pairs with integer distance
        int count = 0;
        
        // Iterate through all unique pairs of points
        for (int i = 1; i <= n - 1; i++) {
            for (int j = i + 1; j <= n; j++) {
                
                // Calculate the squared distance between point i and point j
                int sum = 0;
                for (int k = 1; k <= d; k++) {
                    sum += (point[i][k] - point[j][k]) * (point[i][k] - point[j][k]);
                }
                
                // Compute the Euclidean distance
                double kyori = Math.sqrt(sum);
                
                // Check if the distance is an integer
                if (Math.ceil(kyori) == Math.floor(kyori)) {
                    count++; // Increment the count if the distance is an integer
                }
            }
        }
        
        // Output the total count of pairs with integer distance
        System.out.println(count);
        
        scanner.close();
    }
}

// <END-OF-CODE>
