import java.util.*; // Importing the Scanner class for input

public class Main {
    static long min; // Declaring a static variable to keep track of the minimum result

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Creating a Scanner object for input
        min = Long.MAX_VALUE; // Initializing min to the maximum possible long value
        ArrayList<Long> arr = new ArrayList<>(); // Creating an ArrayList to store the numbers

        // Reading four numbers and adding them to the ArrayList
        for (int i = 0; i < 4; i++) {
            arr.add(sc.nextLong());
        }

        // Reading three operations and storing them in an array
        String[] ops = new String[3];
        for (int i = 0; i < 3; i++) {
            ops[i] = sc.next();
        }

        // Calling the recursive function to find the minimum result
        util(arr, ops, 0);

        // Outputting the minimum result
        System.out.println(min);
    }

    // Recursive function to find the minimum result by applying operations
    public static void util(ArrayList<Long> arr, String[] ops, int idx) {
        if (idx == 3) { // Base case: when all operations are applied
            min = Math.min(min, arr.get(0)); // Update min with the current result
            return;
        }

        // Iterating through the array to apply operations between two numbers
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                ArrayList<Long> a = new ArrayList<>(); // Temporary ArrayList to store remaining numbers
                for (int k = 0; k < arr.size(); k++) {
                    if (k != j && k != i) {
                        a.add(arr.get(k)); // Adding remaining numbers to the temporary ArrayList
                    }
                }

                long res; // Variable to store the result of the operation
                if (idx < 3 && ops[idx].equals("+")) {
                    res = arr.get(i) + arr.get(j); // Applying addition
                } else {
                    res = arr.get(i) * arr.get(j); // Applying multiplication
                }

                a.add(res); // Adding the result to the temporary ArrayList
                util(a, ops, idx + 1); // Recursively calling util with the updated ArrayList and index
            }
        }
    }
}
