public class Main {
    public static void main(String[] args) {
        // Read the number of work items
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();

        // Initialize a list to hold the work items
        java.util.List<Work> works = new java.util.ArrayList<>();

        // Read each work item's time and limit
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            works.add(new Work(a, b)); // Add the work item to the list
        }

        // Sort the work items based on their limits
        java.util.Collections.sort(works);

        // Initialize a variable to keep track of the cumulative time
        long sum = 0;

        // Check if the cumulative time exceeds the limit for any work item
        for (Work w : works) {
            sum += w.getTime(); // Add the current work item's time to the sum
            if (sum > w.getLimit()) {
                System.out.println("No"); // If the sum exceeds the limit, print "No"
                return;
            }
        }

        // If all work items are within their limits, print "Yes"
        System.out.println("Yes");
    }
}

// Define a class to represent a work item with time and limit
class Work implements Comparable<Work> {
    private int time;
    private int limit;

    // Constructor to initialize the work item
    public Work(int time, int limit) {
        this.time = time;
        this.limit = limit;
    }

    // Getter method for time
    public int getTime() {
        return time;
    }

    // Getter method for limit
    public int getLimit() {
        return limit;
    }

    // Implement the Comparable interface to compare work items based on their limits
    @Override
    public int compareTo(Work other) {
        return Integer.compare(this.limit, other.limit);
    }
}

