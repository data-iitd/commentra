import java.util.ArrayList; // Importing the ArrayList class for dynamic arrays
import java.util.List; // Importing the List interface for a generic list
import java.util.Scanner; // Importing the Scanner class for reading input

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in); // Initialize Scanner object to read input
        int N = scan.nextInt(); // Read the number of elements N
        long x = scan.nextLong(); // Read the cost multiplier x

        List<Long> srimeList = new ArrayList<>(); // Create a list to store the elements
        for (int i = 0; i < N; i++) {
            srimeList.add(scan.nextLong()); // Read N long integers and add to srimeList
        }

        List<Long[]> costList = new ArrayList<>(); // Create a list of Long arrays to store costs
        for (int i = 0; i < N; i++) {
            costList.add(new Long[N]); // Initialize each array in costList with size N
        }

        // Fill costList with the minimum costs for each element in srimeList
        for (int i = 0; i < N; i++) {
            costList.get(i)[0] = srimeList.get(i); // Initialize the first element of the cost array
            for (int castNum = 1; castNum < N; castNum++) {
                costList.get(i)[castNum] = Math.min(costList.get(i)[castNum - 1], srimeList.get((i - castNum + N) % N));
            }
        }

        List<Long> result = new ArrayList<>(); // Create a list to store the final results
        for (int i = 0; i < N; i++) {
            final int j = i; // Use a final variable to avoid lambda issues
            result.add(i * x + costList.stream().mapToLong(costArray -> costArray[j]).sum());
        }

        // Print the minimum cost found
        System.out.println(result.stream().mapToLong(i -> i).min().getAsLong());
    }
}
