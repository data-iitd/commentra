public class Main {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume newline left-over

        for (int i = 0; i < n; i++) {
            String s = scanner.nextLine();
            java.util.Set<String> st = new java.util.HashSet<>();
            st.add(s);

            for (int j = 1; j < s.length(); j++) {
                StringBuilder ss = new StringBuilder();
                for (int k = 0; k < j; k++) {
                    ss.append(s.charAt(k));
                }
                String res = ss.reverse().toString();

                StringBuilder ss2 = new StringBuilder();
                for (int k = j; k < s.length(); k++) {
                    ss2.append(s.charAt(k));
                }
                String res2 = ss2.reverse().toString();

                String t = res;
                String t2 = res2;
                st.add(t + t2);
                st.add(t2 + t);

                st.add(t + res2);
                st.add(res2 + t);

                st.add(res + t2);
                st.add(t2 + res);

                st.add(res + res2);
                st.add(res2 + res);
            }

            System.out.println(st.size());
        }
    }
}
