
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        // Read the number of works
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        // Create a slice of work structs with a length of n
        work[] ws = new work[n];
        
        // Read the time and limit for each work and store them in the slice
        for(int i = 0; i < n; i++){
            int a = sc.nextInt();
            int n = sc.nextInt();
            ws[i] = new work(a, n);
        }
        
        // Sort the slice of works based on the limit field
        Arrays.sort(ws, new Comparator<work>(){
            public int compare(work a, work b){
                return a.limit - b.limit;
            }
        });
        
        // Initialize a sum variable to keep track of the cumulative time
        long sum = 0;
        
        // Iterate over the sorted slice of works, adding the time of each work to the sum
        for(work w : ws){
            sum += w.time;
            
            // Check if the cumulative time exceeds the limit of the current work
            if(sum > w.limit){
                System.out.println("No");
                return;
            }
        }
        
        // If the loop completes without the sum exceeding any limit, print "Yes"
        System.out.println("Yes");
    }
}

class work{
    int time, limit;
    work(int a, int n){
        time = a;
        limit = n;
    }
}

