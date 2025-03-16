import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Define lambda functions for input handling
        IntFunction<Integer> num_inp = () -> Integer.parseInt(scanner.nextLine());
        // This line reads a single integer input from the user

        Function<Scanner, List<Integer>> arr_inp = sc -> {
            String[] elements = sc.nextLine().split(" ");
            List<Integer> list = new ArrayList<>();
            for (String element : elements) {
                list.add(Integer.parseInt(element));
            }
            return list;
        };
        // This line reads a list input from the user, where each element is an integer

        BiFunction<Scanner, String, Iterable<Integer>> sp_inp = (sc, delimiter) -> {
            String[] elements = sc.nextLine().split(delimiter);
            List<Integer> list = new ArrayList<>();
            for (String element : elements) {
                list.add(Integer.parseInt(element));
            }
            return list;
        };
        // This line reads a list input from the user, where each element is an integer, space-separated

        // Read input from file instead of user input
        Scanner fileScanner = new Scanner(System.in);
        String[] lines = fileScanner.nextLine().split("\\n");
        List<Integer> a = new ArrayList<>();
        for (int i = 1; i < lines.length; i++) {
            a.add(Integer.parseInt(lines[i]));
        }
        Collections.sort(a);

        // Find the largest number that leaves a remainder when divided by any number in the list
        int largestNumber = a.get(0);
        boolean leavesRemainder = false;
        for (int x : a) {
            if (largestNumber % x != 0) {
                leavesRemainder = true;
                break;
            }
        }
        System.out.println(leavesRemainder ? -1 : largestNumber);
    }
}
