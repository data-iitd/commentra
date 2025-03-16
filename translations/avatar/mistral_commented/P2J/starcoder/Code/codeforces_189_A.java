import java.util.*;

public class CutRibbon {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Take input as a list of integers, where the first integer represents the length of the ribbon
        List<Integer> arr = new ArrayList<Integer>();
        for (int i = 0; i < 4; i++) {
            arr.add(sc.nextInt());
        }

        // Assign the length of the ribbon to a variable
        int length = arr.get(0);

        // Sort the next three elements of the list in ascending order
        Collections.sort(arr.subList(1, 4));

        // Check if the length of the ribbon is divisible by the first element of the sorted list
        if (length % arr.get(0) == 0) {
            // If it is, print the number of pieces required and return
            System.out.println(length / arr.get(0));
            return;
        }

        // Initialize an answer variable to keep track of the maximum number of pieces that can be cut
        int ans = 0;

        // If the first two elements of the sorted list are equal
        if (arr.get(0) == arr.get(1)) {
            // Initialize a variable k to keep track of the number of pieces required
            int k = 0;

            // Loop to find the maximum number of pieces that can be cut from the ribbon
            for (int i = 0; i <= length / arr.get(2); i++) {
                // Check if the remaining length after subtracting i * arr.get(2) is divisible by arr.get(0)
                int check = length - i * arr.get(2);
                if (check >= 0 && check % arr.get(0) == 0) {
                    // If it is, update the answer and k
                    k = check / arr.get(0);
                    ans = Math.max(ans, k + i);
                }
            }
        }

        // If the first two elements of the sorted list are not equal
        else {
            // Initialize a variable k to keep track of the number of pieces required
            int k = 0;

            // Double loop to find the maximum number of pieces that can be cut from the ribbon
            for (int i = 0; i <= length / arr.get(2); i++) {
                for (int j = 0; j <= length / arr.get(1); j++) {
                    // Check if the remaining length after subtracting i * arr.get(2) and j * arr.get(1) is divisible by arr.get(0)
                    int check = length - i * arr.get(2) - j * arr.get(1);
                    if (check >= 0 && check % arr.get(0) == 0) {
                        // If it is, update the answer and k
                        k = check / arr.get(0);
                        ans = Math.max(ans, k + i + j);
                    }
                }
            }
        }

        // Print the final answer and return
        System.out.println(ans);
        return;
    }
}

