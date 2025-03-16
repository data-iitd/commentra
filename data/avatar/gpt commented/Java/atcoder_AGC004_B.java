import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read input from the console
        Scanner scan = new Scanner(System.in);
        
        // Read the number of elements (N) and a long value (x) from input
        int N = scan.nextInt();
        long x = scan.nextLong();
        
        // Initialize a list to store the prime numbers
        List<Long> srimeList = new ArrayList<>(N);
        
        // Read N long values into the srimeList
        for (long i = 0; i < N; i++) {
            srimeList.add(scan.nextLong());
        }
        
        // Initialize a 2D list to store costs
        List<Long[]> costList = new ArrayList<>();
        
        // Create a 2D array for costs, where each row corresponds to an element in srimeList
        for (int i = 0; i < N; i++) {
            costList.add(new Long[N]);
        }
        
        // Populate the costList with minimum values based on the srimeList
        for (int i = 0; i < N; i++) {
            // Set the first column of costList to the corresponding values from srimeList
            costList.get(i)[0] = srimeList.get(i);
            // Calculate the minimum costs for each subsequent column
            for (int castNum = 1; castNum < N; castNum++) {
                costList.get(i)[castNum] = Math.min(costList.get(i)[castNum - 1], srimeList.get((i - castNum + N) % N));
            }
        }
        
        // Initialize a list to store the final results
        List<Long> result = new ArrayList<>();
        
        // Calculate the result for each index based on the costs and the value of x
        for (int i = 0; i < N; i++) {
            final int j = i; // Final variable for lambda expression
            result.add(i * x + costList.stream().mapToLong(costArray -> costArray[j]).sum());
        }
        
        // Print the minimum value from the result list
        System.out.println(result.stream().mapToLong(i -> i).min().getAsLong());
    }
}
