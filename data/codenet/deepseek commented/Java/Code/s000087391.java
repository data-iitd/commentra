
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create an ArrayList to store the results
        ArrayList<Integer> result = new ArrayList<Integer>();
        // Create a Scanner object to read input from the user
        Scanner insert = new Scanner(System.in);
        // Initialize n to -1
        int n = -1;
        // Enter a loop to read input values until n is 0
        while(true) {
            // Read the value of n
            String line = insert.nextLine();
            n = Integer.parseInt(line);
            // Check if n is 0 to break the loop
            if(n==0 ){
                break;
            }
            // Read another line of input to get the array elements
            line = insert.nextLine();
            // Split the input line into an array of strings
            String array2[] = line.split(" ");
            // Convert each string to an integer and store them in an array input
            int[] input = new int[n];
            int sum = 0;
            for(int i =0; i < n; i++) {
                input[i] = (Integer.parseInt(array2[i]));
                sum+=input[i];
            }
            // Calculate the average of the array elements
            double avg = (double)sum/(double)n;
            // Count how many elements are less than or equal to the average
            int num = 0;
            for(int i =0; i < n; i++) {
                if(input[i] <= avg) {
                    num++;
                }
            }
            // Store the count in the result list
            result.add(num);
        }
        // Print the results stored in the result list, replacing -1 with "NONE"
        for(int i = 0;i < (result.size());i++) {
            if(result.get(i) == -1) {
                System.out.println("NONE");
            }
            else {
                System.out.println(result.get(i));
            }
        }
    }
}