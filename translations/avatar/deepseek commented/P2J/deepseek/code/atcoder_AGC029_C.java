import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Taking input from the user and processing it to create a list of integers
        scanner.nextLine();
        List<Integer> A = new ArrayList<>();
        String[] input = scanner.nextLine().split(" ");
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
        
        // Function to cut a list of tuples based on a given index
        List<int[]> cut(List<int[]> array, int index) {
            if (index < 1) {
                return new ArrayList<>();
            }
            if (index <= array.get(0)[0]) {
                List<int[]> result = new ArrayList<>();
                result.add(new int[]{index, array.get(0)[1]});
                return result;
            }
            for (int i = array.size() - 1; i > 0; i--) {
                if (array.get(i - 1)[0] < index) {
                    List<int[]> result = new ArrayList<>(array.subList(0, i));
                    result.add(new int[]{index, array.get(i)[1]});
                    return result;
                }
            }
            return array;
        }
        
        // Function to check if a given value of K is possible by modifying the list dp
        boolean is_possible(int K) {
            List<int[]> dp = new ArrayList<>();
            dp.add(new int[]{modifiedA.get(0), 0});
            for (int a : modifiedA.subList(1, modifiedA.size())) {
                if (a <= dp.get(dp.size() - 1)[0]) {
                    dp = cut(dp, a);
                } else {
                    dp.add(new int[]{a, 0});
                }
                boolean is_added = false;
                for (int j = dp.size() - 1; j >= 0; j--) {
                    if (dp.get(j)[1] < K - 1) {
                        dp = cut(dp, dp.get(j)[0] - 1);
                        dp.add(new int[]{dp.get(j)[0], dp.get(j)[1] + 1});
                        if (dp.get(dp.size() - 1)[0] < a) {
                            dp.add(new int[]{a, 0});
                        }
                        is_added = true;
                        break;
                    }
                }
                if (!is_added) {
                    return false;
                }
            }
            return true;
        }
        
        // Function to perform a binary search to find the maximum possible value of K
        int bis(int x, int y) {
            if (y == x + 1) {
                return y;
            } else if (is_possible((x + y) / 2)) {
                return bis(x, (x + y) / 2);
            } else {
                return bis((x + y) / 2, y);
            }
        }
        
        // Printing the result of the binary search
        System.out.println(bis(0, N));
    }
}
