import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        solve();
    }

    private static void solve() throws IOException {
        Scanner scanner = new Scanner(System.in);
        List<String> l = new ArrayList<>();

        for (int i = 0; i < 3; i++) {
            l.add(f(scanner.nextLine()));
        }

        Set<String> permutations = new HashSet<>();
        permute(l, 0, permutations);

        int t = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < t; i++) {
            String input = f(scanner.nextLine());
            if (permutations.contains(input)) {
                System.out.println("ACC");
            } else {
                System.out.println("WA");
            }
        }
    }

    private static void permute(List<String> arr, int index, Set<String> result) {
        if (index == arr.size() - 1) {
            result.add(String.join("", arr));
            return;
        }

        for (int i = index; i < arr.size(); i++) {
            Collections.swap(arr, index, i);
            permute(arr, index + 1, result);
            Collections.swap(arr, index, i); // backtrack
        }
    }

    private static String f(String s) {
        StringBuilder r = new StringBuilder();
        for (char i : s.toCharArray()) {
            if (i != '-' && i != ';' && i != '_') {
                r.append(Character.toLowerCase(i));
            }
        }
        return r.toString();
    }
}
