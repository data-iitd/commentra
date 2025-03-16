import java.util.ArrayList; // Importing ArrayList class from java.util package
import java.util.List; // Importing List interface
import java.util.Scanner; // Importing Scanner class for reading input

public class Main {
    // Main method is the entry point of the program
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in); // Creating a new Scanner object to read input from the console

        int N; // Variable to store the number of elements in the array
        long x; // Variable to store the multiplier

        // Reading input from the console
        N = scan.nextInt();
        x = scan.nextLong();

        List<Long> srimeList = new ArrayList<>(N); // Creating an ArrayList of size N to store the elements

        // Reading elements of the array and adding them to the ArrayList
        for (long i = 0; i < N; i++) {
            srimeList.add(scan.nextLong());
        }

        List<Long[]> costList = new ArrayList<>(); // Creating an ArrayList to store the cost arrays

        // Creating cost arrays of size N x N for each element in the original array
        for (int i = 0; i < N; i++) {
            costList.add(new Long[N]);
        }

        // Filling the cost arrays with the minimum cost for each index and each cast number
        for (int i = 0; i < N; i++) {
            costList.get(i)[0] = srimeList.get(i); // Setting the first element of the cost array to the original element
            for (int castNum = 1; castNum < N; castNum++) {
                costList.get(i)[castNum] = Math.min(costList.get(i)[castNum - 1], srimeList.get((i - castNum + N) % N));
            }
        }

        List<Long> result = new ArrayList<>(); // Creating an ArrayList to store the final result

        // Calculating the result for each index and adding it to the ArrayList
        for (int i = 0; i < N; i++) {
            long temp = i * x; // Multiplying the index with the multiplier
            for (Long cost : costList.get(i)) { // Iterating through the cost array and adding the costs
                temp += cost;
            }
            result.add(temp);
        }

        // Printing the minimum result
        System.out.println(result.stream().mapToLong(i -> i).min().getAsLong());
    }
}
