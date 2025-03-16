import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    // Function to cut a list of tuples based on a given index
    public static List<int[]> cut(List<int[]> array, int index) {
        List<int[]> result = new ArrayList<>();
        if (index < 1) {
            return result;
        }
        if (index <= array.get(0)[0]) {
            result.add(new int[]{index, array.get(0)[1]});
            return result;
        }
        for (int i = array.size() - 1; i > 0; i--) {
            if (array.get(i - 1)[0] < index) {
                result.addAll(array.subList(0, i));
                result.add(new int[]{index, array.get(i)[1]});
                return result;
            }
        }
        return result;
    }

    // Function to check if a given value of K is possible by modifying the list dp
    public static boolean isPossible(int K, List<Integer> A) {
        List<int[]> dp = new ArrayList<>();
        dp.add(new int[]{A.get(0), 0});
        for (int a : A.subList(1, A.size())) {
            if (a <= dp.get(dp.size() - 1)[0]) {
                dp = cut(dp, a);
            } else {
                dp.add(new int[]{a, 0});
            }
            boolean isAdded = false;
            for (int j = dp.size() - 1; j >= 0; j--) {
                if (dp.get(j)[1] < K - 1) {
                    dp = cut(dp, dp.get(j)[0] - 1);
                    dp.add(new int[]{dp.get(j)[0], dp.get(j)[1] + 1});
                    if (dp.get(dp.size() - 1)[0] < a) {
                        dp.add(new int[]{a, 0});
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

    // Function to perform a binary search to find the maximum possible value of K
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
        // Taking input from the user and processing it to create a list of integers
        scanner.nextLine(); // Consume the first line
        String[] input = scanner.nextLine().split(" ");
        List<Integer> A = new ArrayList<>();
        for (String s : input) {
            A.add(Integer.parseInt(s));
        }

        // Modifying the list A to include only elements where the previous element is greater than or equal to the current element
        List<Integer> modifiedA = new ArrayList<>();
        modifiedA.add(A.get(0));
        for (int i = 1; i < A.size(); i++) {
            if (A.get(i - 1) >= A.get(i)) {
                modifiedA.add(A.get(i));
            }
        }

        // Storing the length of the modified list A in N
        int N = modifiedA.size();

        // Printing the result of the binary search
        System.out.println(bis(0, N, modifiedA));
    }
}

// <END-OF-CODE>
