public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();

        java.util.List<Integer> L = new java.util.ArrayList<>(100000);
        for (int i = 0; i < N; i++) {
            int l = scanner.nextInt();
            L.add(l);
        }

        java.util.Collections.sort(L);

        for (int i = 0; i < M; i++) {
            int max_L = L.get(L.size() - 1);
            if (max_L == 0) {
                break;
            }

            max_L /= 2;
            int index = java.util.Collections.binarySearch(L, max_L);
            if (index < 0) {
                index = -(index + 1);
            }
            L.add(index, max_L);
            L.remove(L.size() - 1);
        }

        long ans = 0;
        for (int num : L) {
            ans += num;
        }

        System.out.println(ans);
    }
}
