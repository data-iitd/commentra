import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine(); // Consume the newline character

        for (int i = 0; i < n; i++) {
            String s = scanner.nextLine();
            HashSet<String> st = new HashSet<>();
            st.add(s);

            for (int j = 1; j < s.length(); j++) {
                String res = s.substring(0, j);
                String res2 = s.substring(j);

                String t = new StringBuilder(res).reverse().toString();
                String t2 = new StringBuilder(res2).reverse().toString();

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

        scanner.close();
    }
}

// <END-OF-CODE>
