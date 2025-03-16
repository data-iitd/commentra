import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        scanner.nextLine(); // Consume newline

        int[] L = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        L = Arrays.stream(L).boxed().toArray(Integer[]::new);
        L = insertElement(L, -1, 0);

        List<Integer> path = new ArrayList<>();
        path.add(1);

        int ind = 0;
        int count = 0;
        int x = 1;
        int t = -1;
        boolean flag = false;

        Map<Integer, Integer> Hash = new HashMap<>();

        for (int i = 0; i <= N; i++) {
            int ne = L[x];

            if (Hash.containsKey(ne)) {
                flag = true;
                t = Hash.get(ne);
                break;
            }

            path.add(ne);
            Hash.put(ne, ind);
            ind++;
            x = ne;
        }

        if (flag) {
            List<Integer> loop = path.subList(t, path.size());

            if (path.size() < K) {
                System.out.println(path.get(K));
            } else {
                K = K - path.size();
                K = K % loop.size();
                System.out.println(loop.get(K));
            }
        } else {
            System.out.println(path.get(K - 1));
        }
    }

    public static Integer[] insertElement(Integer[] originalArray, Integer element, int index) {
        Integer[] newArray = new Integer[originalArray.length + 1];
        System.arraycopy(originalArray, 0, newArray, 0, index);
        newArray[index] = element;
        System.arraycopy(originalArray, index, newArray, index + 1, originalArray.length - index);
        return newArray;
    }
}
