import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> li = new ArrayList<>();
        int ind = 0;

        for (int i = 1; i < 371; i++) {
            ArrayList<Integer> temp = new ArrayList<>();
            int p = i, q = i;
            int count = 0;

            // Count the number of digits in i
            while (p != 0) {
                p /= 10;
                count++;
            }

            // If i has 1 digit, append it to the list li
            if (count == 1) {
                li.add(i);
            }

            // If i has 2 digits, extract the digits and reverse them, then append to li
            if (count == 2) {
                while (q != 0) {
                    int x = q % 10;
                    q /= 10;
                    temp.add(x);
                }
                for (int j = temp.size() - 1; j >= 0; j--) {
                    li.add(temp.get(j));
                }
            }

            // If i has 3 digits, extract the digits and reverse them, then append to li
            if (count == 3) {
                while (q != 0) {
                    int x = q % 10;
                    q /= 10;
                    temp.add(x);
                }
                for (int j = temp.size() - 1; j >= 0; j--) {
                    li.add(temp.get(j));
                }
            }
        }

        // Remove the last two elements from li
        li.remove(li.size() - 1);
        li.remove(li.size() - 1);

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // Take an integer input from the user

        System.out.println(li.get(n - 1)); // Print the nth element of li based on the user's input
    }
}
// <END-OF-CODE>
