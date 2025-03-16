import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

// Data represents a structure holding a string.
class Data implements Comparable<Data> {
    String x;

    Data(String x) {
        this.x = x;
    }

    @Override
    public int compareTo(Data other) {
        return this.x.compareTo(other.x);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int N = sc.nextInt();
        int L = sc.nextInt();
        List<Data> s = new ArrayList<>();

        for (int i = 0; i < N; i++) {
            s.add(new Data(sc.next()));
        }

        // Sort the list
        Collections.sort(s);

        // Concatenate the strings
        StringBuilder ans = new StringBuilder();
        for (Data data : s) {
            ans.append(data.x);
        }

        System.out.println(ans.toString());
        sc.close();
    }
}

// <END-OF-CODE>
