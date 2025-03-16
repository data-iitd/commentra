import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String[] input = scanner.nextLine().split(" ");
        List<Integer> A = new ArrayList<>();
        for (String s : input) {
            A.add(Integer.parseInt(s));
        }
        A.add(0, A.get(0));
        A = A.subList(0, A.size() - 1).stream()
                .filter(i -> i >= A.get(A.size() - 1))
                .collect(ArrayList::new, ArrayList::add, ArrayList::addAll);
        int N = A.size();

        System.out.println(bis(0, N));
    }

    private static List<int[]> cut(List<int[]> array, int index) {
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

    private static boolean isPossible(List<int[]> dp, int K) {
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

    private static int bis(int x, int y) {
        if (y == x + 1) {
            return y;
        } else if (isPossible(new ArrayList<>(), (x + y) / 2)) {
            return bis(x, (x + y) / 2);
        } else {
            return bis((x + y) / 2, y);
        }
    }
}
