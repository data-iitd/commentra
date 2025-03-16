import java.util.*; // Importing necessary classes from the java.util package

public class Main {
    public static void main(String[] args) {
        // Creating a Scanner object to read input from the console
        Scanner sc = new Scanner(System.in);
        
        // Reading the number of elements to be processed
        int n = sc.nextInt();
        
        // Initializing a list to store the input numbers
        List<Long> list = new ArrayList<>();
        
        // Reading n long integers from input and adding them to the list
        for (int i = 0; i < n; i++) {
            list.add(sc.nextLong());
        }
        
        // Initializing a list to store odd numbers and a variable to hold the sum
        List<Long> odd = new ArrayList<>();
        long sum = 0;
        
        // Iterating through the list to separate even and odd numbers
        for (long i : list) {
            if (i % 2 == 0) {
                // If the number is even, add it to the sum
                sum += i;
            } else {
                // If the number is odd, add it to the odd list
                odd.add(i);
            }
        }
        
        // Sorting the list of odd numbers in ascending order
        Collections.sort(odd);
        
        // Adding all odd numbers to the sum
        for (long i : odd) {
            sum += i;
        }
        
        // If the count of odd numbers is odd, subtract the smallest odd number from the sum
        if (odd.size() % 2 != 0) {
            sum -= odd.get(0);
        }
        
        // Printing the final calculated sum
        System.out.println(sum);
    }
}
