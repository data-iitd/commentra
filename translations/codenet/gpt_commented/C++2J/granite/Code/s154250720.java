
import java.util.Scanner;
import java.util.Arrays;

public class s154250720{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n; // Variable to hold the number of elements
        
        // Continuously read input until EOF
        while(sc.hasNextInt()) {
            n = sc.nextInt();
            
            // Arrays to hold input values and sorted values
            int[] maps = new int[n+10];
            int[] num = new int[n+10];
            
            // Read n integers into the maps array and copy to num array
            for(int i=1; i<=n; i++) {
                maps[i] = sc.nextInt();
                num[i] = maps[i];
            }

            // Sort the maps array to find the median
            Arrays.sort(maps, 1, n+1);
            
            // Calculate the index for the median element
            int m = n/2;

            // For each element in the original array, determine and print the appropriate value
            for(int i=1; i<=n; i++) {
                // If the current number is less than or equal to the median
                if(num[i]<=maps[m])
                    // Print the next higher number (the one after the median)
                    System.out.println(maps[m+1]);
                else
                    // Print the median value
                    System.out.println(maps[m]);
            }
        }
    }
}
