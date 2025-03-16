import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Read the number of work items
        int n = sc.nextInt();

        // Initialize a slice to hold the work items
        Work[] ws = new Work[n];

        // Read each work item's time and limit
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int n = sc.nextInt();
            ws[i] = new Work(a, n); // Store the work item in the slice
        }

        // Sort the work items based on their limits
        Arrays.sort(ws, new Comparator<Work>() {
            @Override
            public int compare(Work w1, Work w2) {
                return w1.limit - w2.limit;
            }
        });

        // Initialize a variable to keep track of the cumulative time
        long sum = 0;

        // Check if the cumulative time exceeds the limit for any work item
        for (Work w : ws) {
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
    int time, limit;

    public Work(int time, int limit) {
        this.time = time;
        this.limit = limit;
    }
}

