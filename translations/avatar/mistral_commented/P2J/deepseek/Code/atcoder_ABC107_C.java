import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Taking the number of elements N and the number of queries K as input
        int N = scanner.nextInt();
        int K = scanner.nextInt();

        // Creating an empty list to store positive numbers and another empty list to store negative numbers
        List<Integer> lst = new ArrayList<>();
        List<Integer> lst_p = new ArrayList<>();
        List<Integer> lst_m = new ArrayList<>();

        // Taking the list of numbers as input
        for (int i = 0; i < N; i++) {
            lst.add(scanner.nextInt());
        }

        // Iterating through the list to find positive and negative numbers
        for (int num : lst) {
            // If the number is zero, decrement the number of queries K
            if (num == 0) {
                K--;
            }
            // If the number is positive, add it to the list of positive numbers
            else if (num > 0) {
                lst_p.add(num);
            }
            // If the number is negative, add it to the list of negative numbers
            else if (num < 0) {
                lst_m.add(num);
            }
        }

        // Initializing variables p and m to 0 and setting the initial values of x and y
        int p = 0, m = 0, x = 0, y = lst_m.size() - 1;
        int lastx = lst_p.size();
        int lasty = lst_m.size();

        // Function to check the minimum number of moves required to make the sum of the first k elements equal to or less than 0
        int result = check(K, lst_p, lst_m, lastx, lasty);

        // Printing the minimum number of moves required to make the sum of the first K elements equal to or less than 0
        System.out.println(result);
    }

    public static int check(int k, List<Integer> lst_p, List<Integer> lst_m, int lastx, int lasty) {
        // Initializing the answer as a large number
        int ans = Integer.MAX_VALUE;

        // Iterating through all possible combinations of taking elements from positive and negative lists
        for (int j = 0; j <= k; j++) {
            // If the index j is greater than the length of the list of positive numbers or if the number of elements to be taken from negative list is greater than the number of negative elements, then skip this iteration
            if (j > lastx || k - j > lasty) {
                continue;
            }

            // If j is 0, then p is initialized to 0
            int p = j == 0 ? 0 : lst_p.get(j - 1);

            // If k - j is 0, then m is initialized to 0
            int m = k - j == 0 ? 0 : lst_m.get(lasty - (k - j));

            // Updating the answer with the minimum of the current answer and the sum of the absolute difference of p and m and the sum of p and m
            ans = Math.min(ans, 2 * p + Math.abs(m));
            ans = Math.min(ans, p + 2 * Math.abs(m));
        }

        // Returning the answer
        return ans;
    }
}
