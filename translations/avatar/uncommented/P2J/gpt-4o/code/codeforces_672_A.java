import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        List<Integer> li = new ArrayList<>();
        int ind = 0;

        for (int i = 1; i < 371; i++) {
            int p = i, q = i;
            int count = 0;

            // Count the number of digits
            while (p != 0) {
                p /= 10;
                count++;
            }

            if (count == 1) {
                li.add(i);
            }

            if (count == 2 || count == 3) {
                List<Integer> temp = new ArrayList<>();
                while (q != 0) {
                    int x = q % 10;
                    q /= 10;
                    temp.add(x);
                }
                // Add the digits in reverse order
                for (int j = temp.size() - 1; j >= 0; j--) {
                    li.add(temp.get(j));
                }
            }
        }

        // Remove the last two elements
        li.remove(li.size() - 1);
        li.remove(li.size() - 1);

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        System.out.println(li.get(n - 1));
    }
}
// <END-OF-CODE>
