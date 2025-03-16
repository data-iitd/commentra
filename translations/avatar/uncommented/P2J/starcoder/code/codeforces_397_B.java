class CodeforcesTask397BSolution {
    public static void main(String[] args) {
        new CodeforcesTask397BSolution().solve();
    }
    public void solve() {
        int t = Integer.parseInt(reader.readLine());
        for (int i = 0; i < t; i++) {
            int[] query = reader.readLine().split(" ");
            int k = Integer.parseInt(query[0]) / Integer.parseInt(query[1]);
            System.out.println(k * Integer.parseInt(query[2]) >= Integer.parseInt(query[0])? "Yes" : "No");
        }
    }
}
