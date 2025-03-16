
import java.util.Scanner;

public class s978355948{
    public static void main(String[] args) {
        // Read the number of elements N and the maximum distance X
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int X = scanner.nextInt();
        
        // Read the lengths of the segments into an array L
        int[] L = new int[N];
        for(int i = 0; i < N; i++)
            L[i] = scanner.nextInt();
        
        // Initialize the index i and the distance d
        int i;
        int d = 0;
        
        // Loop through the segments to calculate the total distance
        for(i = 0; i < N; i++){
            // Add the current segment length to the total distance
            d = d + L[i];
            
            // If the total distance exceeds X, break the loop
            if(d > X)
                break;
        }

        // Output the number of segments used
        System.out.println(i+1);
    }
}
