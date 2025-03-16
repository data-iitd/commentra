class CodeforcesTask397BSolution {
    public static void main(String[] args) {
        // Read input data
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        // Initialize a list to hold the results for each query
        List<String> res = new ArrayList<>();
        // Process each query to determine if the condition is met
        for (int i = 0; i < t; i++) {
            // Read each query and store it as a list of integers in the queries list
            int[] query = new int[3];
            for (int j = 0; j < 3; j++) {
                query[j] = scanner.nextInt();
            }
            // Calculate how many complete sets of query[1] fit into query[0]
            int k = query[0] / query[1];
            // Check if k multiplied by query[2] is at least query[0]
            res.add("Yes" + (k * query[2] >= query[0]? "" : "No"));
        }
        // Join the results into a single string separated by newlines
        System.out.println(String.join("\n", res));
    }
}
