import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Function to cut the array based on a given index
    public static List<Pair> cut(List<Pair> array, int index) {
        // If the index is less than 1, return an empty list
        if (index < 1) {
            return new ArrayList<>();
        }

        // If the index is less than or equal to the first element, return it with the first element's second value
        if (index <= array.get(0).first) {
            List<Pair> result = new ArrayList<>();
            result.add(new Pair(index, array.get(0).second));
            return result;
        }

        // Iterate backwards through the array to find the appropriate cut point
        for (int i = array.size() - 1; i > 0; i--) {
            if (array.get(i - 1).first < index) {
                List<Pair> result = new ArrayList<>(array.subList(0, i));
                result.add(new Pair(index, array.get(i).second));
                return result;
            }
        }
        return array; // If no cut is made, return the original array
    }

    // Function to check if a certain condition is possible with K
    public static boolean isPossible(int K, List<Integer> A) {
        List<Pair> dp = new ArrayList<>();
        dp.add(new Pair(A.get(0), 0));

        for (int a : A.subList(1, A.size())) {
            if (a <= dp.get(dp.size() - 1).first) {
                dp = cut(dp, a);
            } else {
                dp.add(new Pair(a, 0));
            }

            boolean isAdded = false;

            for (int j = dp.size() - 1; j >= 0; j--) {
                if (dp.get(j).second < K - 1) {
                    dp = cut(dp, dp.get(j).first - 1);
                    dp.add(new Pair(dp.get(j).first, dp.get(j).second + 1));

                    if (dp.get(dp.size() - 1).first < a) {
                        dp.add(new Pair(a, 0));
                    }

                    isAdded = true;
                    break;
                }
            }

            if (!isAdded) {
                return false;
            }
        }

        return true;
    }

    // Function to perform binary search to find the maximum K
    public static int bis(int x, int y, List<Integer> A) {
        if (y == x + 1) {
            return y;
        } else if (isPossible((x + y) / 2, A)) {
            return bis(x, (x + y) / 2, A);
        } else {
            return bis((x + y) / 2, y, A);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Read input from the user
        scanner.nextLine(); // Ignore the first input
        String[] input = scanner.nextLine().split(" ");
        List<Integer> A = new ArrayList<>();

        // Parse the input into a list of integers
        for (String s : input) {
            A.add(Integer.parseInt(s));
        }

        // Filter the list to keep only non-increasing elements
        List<Integer> filteredA = new ArrayList<>();
        filteredA.add(A.get(0));
        for (int i = 1; i < A.size(); i++) {
            if (A.get(i) <= filteredA.get(filteredA.size() - 1)) {
                filteredA.add(A.get(i));
            }
        }

        // Get the length of the filtered list
        int N = filteredA.size();

        // Print the result of the binary search
        System.out.println(bis(0, N, filteredA));
    }

    // Pair class to hold two integers
    static class Pair {
        int first;
        int second;

        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}

// <END-OF-CODE>
