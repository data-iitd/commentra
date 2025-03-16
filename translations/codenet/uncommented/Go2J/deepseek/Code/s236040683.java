public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int M = scanner.nextInt();
        List<List<Integer>> adjacencyList = new ArrayList<>(N);
        for (int i = 0; i < N; i++) {
            adjacencyList.add(new ArrayList<>());
        }
        for (int i = 0; i < M; i++) {
            int from = scanner.nextInt() - 1;
            int to = scanner.nextInt() - 1;
            adjacencyList.get(from).add(to);
            adjacencyList.get(to).add(from);
        }
        for (int i = 0; i < N; i++) {
            System.out.println(adjacencyList.get(i).size());
        }
    }
}
