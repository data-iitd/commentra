
import java.util.* ;

// Create a Scanner object to read input from the console
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Initialize a Scanner object

        // Read the first integer from the input
        int n = sc.nextInt();

        // Check if the input is 1, if so, print the only integer and exit the program
        if (n == 1) {
            System.out.println(sc.nextInt()); // Print the only integer
            System.exit(0); // Exit the program
        }

        // Initialize an ArrayList to store the integers
        ArrayList<Integer> a = new ArrayList<>();

        // Read the rest of the integers and add them to the ArrayList
        for (int i = 0; i < n; i++) {
            a.add(sc.nextInt());
        }

        // Sort the ArrayList in ascending order
        Collections.sort(a);

        // Check if the last integer in the ArrayList is 0, if so, print 0 and exit the program
        if (a.get(a.size() - 1) == 0) {
            System.out.println(0); // Print 0
            System.exit(0); // Exit the program
        }

        // Initialize the answer variable
        int ans = 0;

        // Use a while loop to keep applying the function to the ArrayList until it contains only one element
        while (true) {
            if (a.size() == 1) {
                ans = a.get(0); // Assign the only remaining integer to the answer variable
                break; // Exit the loop
            }
            a = func(a); // Apply the function to the ArrayList and assign the result back to it
        }

        // Print the answer
        System.out.println(ans);
    }

    // Define a private static function to apply the logic to the ArrayList
    private static ArrayList<Integer> func(ArrayList<Integer> A) {
        ArrayList<Integer> a = A; // Create a copy of the ArrayList to modify it without affecting the original one
        int min = 0;

        // Iterate through the ArrayList and apply the logic to each integer
        for (int i = 0; i < a.size(); i++) {
            if (a.get(i) == 0) { // If the current integer is 0, remove it and decrease the index of the for loop
                a.remove(i);
                i--;
            } else {
                if (min != 0) { // If there is already a minimum value, apply the modulo operation and check if the result is 1
                    a.set(i, a.get(i) % min);
                    if (a.get(i) == 1) { // If the result is 1, print 1 and exit the program
                        System.out.println(1);
                        System.exit(0);
                    }
                } else { // If there is no minimum value yet, assign the current integer as the minimum value
                    min = a.get(i);
                }
            }
        }

        // Sort the ArrayList in ascending order and return it
        Collections.sort(a);
        return a;
    }
}

