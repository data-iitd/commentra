
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Integer> L = new ArrayList<Integer>();
        // Initialize an empty list L to store the results.
        String input = sc.nextLine();
        // Take the first input from the user.
        int r = 1;
        // Initialize the variable r to 1.
        for (String k : input.split(" ")) {
            // Split the first input into a list of strings and iterate over each string.
            for (int i = 0; i < Integer.parseInt(k); i++) {
                // For each string, multiply the string '1' by the integer value of the string and append the result to the list L.
                L.add(r);
            }
            r++;
            // Increment r by 1 for the next iteration.
        }
        input = sc.nextLine();
        // Take the second input from the user.
        for (String j : input.split(" ")) {
            // Split the second input into a list of strings and iterate over each string.
            System.out.println(L.get(Integer.parseInt(j) - 1));
            // For each string, print the element at the index specified by the integer value of the string minus one from the list L.
        }
    }
}
