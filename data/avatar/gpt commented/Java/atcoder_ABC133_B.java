import java.lang.Math; 
import java.util.Scanner; 

public class Main { 
    public static void main(String[] args) { 
        // Create a Scanner object to read input from the user
        Scanner sc = new Scanner(System.in); 
        
        // Read the number of vectors (N) and their dimensionality (D)
        int N = sc.nextInt(); 
        int D = sc.nextInt(); 
        
        // Initialize a 2D array to store the vectors
        int[][] vectors = new int[N][D]; 
        
        // Read each vector's components from the input
        for (int i = 0; i < N; i++) { 
            for (int j = 0; j < D; j++) { 
                vectors[i][j] = sc.nextInt(); 
            } 
        } 
        
        // Initialize a counter for the number of pairs with integer distances
        int answer = 0; 
        
        // Calculate the pairwise distances between all vectors
        for (int i = 0; i < N - 1; i++) { 
            for (int j = i + 1; j < N; j++) { 
                int dist = 0; 
                
                // Calculate the squared distance between vector i and vector j
                for (int d = 0; d < D; d++) { 
                    int x = (vectors[i][d] - vectors[j][d]); 
                    dist += (x * x); 
                } 
                
                // Calculate the Euclidean distance
                double sq = Math.sqrt(dist); 
                
                // Check if the distance is an integer (within a small epsilon)
                answer += (Math.abs(sq - Math.floor(sq)) < 0.001 ? 1 : 0); 
            } 
        } 
        
        // Output the total count of pairs with integer distances
        System.out.println(answer); 
    } 
}
