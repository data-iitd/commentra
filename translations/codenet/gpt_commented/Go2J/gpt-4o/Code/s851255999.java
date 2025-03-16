import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

// Entry point of the program
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of work items
        int n = scanner.nextInt();
        
        // Initialize an array to hold the work items
        Work[] works = new Work[n];
        
        // Read each work item's time and limit
        for (int i = 0; i < n; i++) {
            int time = scanner.nextInt();
            int limit = scanner.nextInt();
            works[i] = new Work(time, limit); // Store the work item in the array
        }
        
        // Sort the work items based on their limits
        Arrays.sort(works, Comparator.comparingInt(w -> w.limit));
        
        // Initialize a variable to keep track of the cumulative time
        long sum = 0;
        
        // Check if the cumulative time exceeds the limit for any work item
        for (Work w : works) {
            sum += w.time; // Add the current work item's time to the sum
            if (sum > w.limit) {
                System.out.println("No"); // If the sum exceeds the limit, print "No"
                return;
            }
        }
        
        // If all work items are within their limits, print "Yes"
        System.out.println("Yes");
    }
}

// Define a class to represent a work item with time and limit
class Work {
    int time;
    int limit;

    Work(int time, int limit) {
        this.time = time;
        this.limit = limit;
    }
}

// <END-OF-CODE>
