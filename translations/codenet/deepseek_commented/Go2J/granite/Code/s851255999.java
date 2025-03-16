

import java.util.*;

class s851255999 {
    public static void main(String[] args) {
        // Read the number of works
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        // Create a list of work objects with a capacity of n
        List<Work> ws = new ArrayList<>(n);
        
        // Read the time and limit for each work and store them in the list
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int n = sc.nextInt();
            Work w = new Work(a, n);
            ws.add(w);
        }
        
        // Sort the list of works based on the limit field
        Collections.sort(ws);
        
        // Initialize a sum variable to keep track of the cumulative time
        long sum = 0;
        
        // Iterate over the sorted list of works, adding the time of each work to the sum
        for (Work w : ws) {
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

class Work implements Comparable<Work> {
    int time;
    int limit;
    
    public Work(int time, int limit) {
        this.time = time;
        this.limit = limit;
    }
    
    @Override
    public int compareTo(Work o) {
        return this.limit - o.limit;
    }
}

