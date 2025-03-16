import java.util.Scanner; // Importing the Scanner class for input

public class Main {
    public static void main(String[] args) {
        Scanner ob = new Scanner(System.in); // Creating a Scanner object to read input
        int n = ob.nextInt(); // Reading the number of elements in the array
        int array[] = new int[n + 1]; // Initializing an array of size n+1

        // Populating the array with integers from the user input
        for (int i = 1; i <= n; i++) {
            array[i] = ob.nextInt();
        }

        int odd = 0, even = 0, odd_ind = 0, even_ind = 0; // Initializing variables to count odd and even numbers and their indices

        // Counting the number of odd and even numbers and recording their indices
        for (int i = 1; i <= n; i++) {
            if (array[i] % 2 == 0) {
                even++;
                even_ind = i;
            } else {
                odd++;
                odd_ind = i;
            }
        }

        // Comparing the counts of odd and even numbers and printing the index of the majority
        if (odd > even) {
            System.out.println(even_ind);
        } else {
            System.out.println(odd_ind);
        }
    }
}
