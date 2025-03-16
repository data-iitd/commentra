public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        if (args.length > 1) {
            reader = new BufferedReader(new FileReader(args[1]));
            if (args.length > 2) {
                writer = new BufferedWriter(new FileWriter(args[2]));
            }
        }

        int n = Integer.parseInt(reader.readLine());

        String ans = "second";
        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(reader.readLine());
            if (a % 2 == 1) {
                ans = "first";
                break;
            }
        }
        writer.write(ans);
        writer.newLine();
        writer.flush();
    }
}
