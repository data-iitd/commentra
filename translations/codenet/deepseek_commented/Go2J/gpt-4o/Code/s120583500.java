import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in); // Step 1: The program starts by taking a string input from the user.
        String s = scanner.nextLine();

        int count = 0; // Step 2: It initializes a counter to keep track of the lengths of consecutive valid characters.
        List<Integer> counter = new ArrayList<>();

        if (s.isEmpty()) { // Step 3: It checks if the input string is empty and returns immediately if it is.
            return;
        }
        counter.add(0); // Step 4: It splits the input string into individual characters.

        for (char c : s.toCharArray()) { // Step 5: It iterates through each character in the split string, incrementing the count for valid characters and resetting the count for invalid characters.
            if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
                count++;
            } else {
                counter.add(count);
                count = 0;
            }
        }

        counter.add(count); // Step 6: It appends the final count to the counter array and sorts the array.
        Collections.sort(counter);
        System.out.println(counter.get(counter.size() - 1)); // Step 7: Finally, it prints the maximum value in the sorted counter array.
    }
}
// <END-OF-CODE>
