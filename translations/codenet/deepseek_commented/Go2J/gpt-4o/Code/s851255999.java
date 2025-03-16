import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of works
        int n = scanner.nextInt();
        
        // Create an array of work structs with a length of n
        Work[] works = new Work[n];
        
        // Read the time and limit for each work and store them in the array
        for (int i = 0; i < n; i++) {
            int time = scanner.nextInt();
            int limit = scanner.nextInt();
            works[i] = new Work(time, limit);
        }
        
        // Sort the array of works based on the limit field
        Arrays.sort(works, Comparator.comparingInt(w -> w.limit));
        
        // Initialize a sum variable to keep track of the cumulative time
        long sum = 0;
        
        // Iterate over the sorted array of works, adding the time of each work to the sum
        for (Work w : works) {
            sum += w.time;
            
            // Check if the cumulative time exceeds the limit of the current work
            if (sum > w.limit) {
                System.out.println("No");
                return;
            }
        }
        
        // If the loop completes without the sum exceeding any limit, print "Yes"
        System.out.println("Yes");
    }
}

class Work {
    int time;
    int limit;

    Work(int time, int limit) {
        this.time = time;
        this.limit = limit;
    }
}

// <END-OF-CODE>
