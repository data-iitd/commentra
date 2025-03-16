import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int M = scanner.nextInt();

        List<Integer> L = new ArrayList<>(Collections.nCopies(100000, 0));
        for (int i = 0; i < N; i++) {
            L.set(i, scanner.nextInt());
        }

        Collections.sort(L.subList(0, N));

        for (int i = 0; i < M; i++) {
            int max_L = L.get(N - 1);
            if (max_L == 0) {
                break;
            }

            max_L /= 2;
            int index = Collections.binarySearch(L.subList(0, N), max_L);
            if (index < 0) {
                index = -(index + 1); // Get the insertion point
            }
            L.add(index, max_L);
            L.remove(N); // Remove the last element
            N++; // Increase the size of the list
        }

        long ans = 0;
        for (int i = 0; i < N; i++) {
            ans += L.get(i);
        }

        System.out.println(ans);
    }
}

// <END-OF-CODE>
