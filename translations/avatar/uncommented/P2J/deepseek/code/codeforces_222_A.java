import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        List<Integer> elems = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            elems.add(scanner.nextInt());
        }

        if (allSame(elems)) {
            System.out.println(0);
            return;
        }

        if (k == 1) {
            System.out.println(-1);
            return;
        }

        if (!allSame(elems.subList(k - 1, elems.size()))) {
            System.out.println(-1);
            return;
        }

        int target = elems.get(elems.size() - 1);
        List<Integer> toDelete = new ArrayList<>(elems.subList(0, k - 1));
        while (!toDelete.isEmpty() && toDelete.get(toDelete.size() - 1) == target) {
            toDelete.remove(toDelete.size() - 1);
        }

        System.out.println(toDelete.size());
    }

    private static boolean allSame(List<Integer> arr) {
        for (int i = 1; i < arr.size(); i++) {
            if (!arr.get(i).equals(arr.get(0))) {
                return false;
            }
        }
        return true;
    }
}
