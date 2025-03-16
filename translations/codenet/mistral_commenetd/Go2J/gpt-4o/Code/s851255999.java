import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

// Main class
public class Main {
    // Work class to hold time and limit
    static class Work {
        int time;
        int limit;

        Work(int time, int limit) {
            this.time = time;
            this.limit = limit;
        }
    }

    // Main method is the entry point of our program
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of work structures
        int n = scanner.nextInt();
        
        // Create an array of Work objects
        Work[] works = new Work[n];
        
        // Read input data for each work structure
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int limit = scanner.nextInt();
            works[i] = new Work(a, limit);
        }
        
        // Sort the works array based on the limit field
        Arrays.sort(works, Comparator.comparingInt(w -> w.limit));
        
        // Initialize a variable named "sum" of type long and set its value to 0
        long sum = 0;
        
        // Iterate through the sorted works array
        for (Work w : works) {
            // Add the time of the current work structure to the sum variable
            sum += w.time;

            // Check if the sum exceeds the limit of the current work structure
            if (sum > w.limit) {
                // If it does, print "No" and return from the method
                System.out.println("No");
                return;
            }
        }
        
        // If the loop completes without exceeding any limit, print "Yes"
        System.out.println("Yes");
    }
}
// <END-OF-CODE>
