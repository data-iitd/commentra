import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        // Read input from file instead of user input
        List<Integer> a = new ArrayList<>();
        String line;
        br.readLine(); // Skip the first line
        while ((line = br.readLine()) != null) {
            a.add(Integer.parseInt(line.trim()));
        }
        Collections.sort(a);

        // Find the largest number that leaves a remainder when divided by any number in the list
        int firstElement = a.get(0);
        boolean hasRemainder = false;
        for (int x : a) {
            if (x % firstElement != 0) {
                hasRemainder = true;
                break;
            }
        }
        System.out.println(hasRemainder ? firstElement : -1);
    }
}
// <END-OF-CODE>
