import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();

        int count = 0;
        List<Integer> counter = new ArrayList<>();

        if (s.isEmpty()) {
            return;
        }

        counter.add(0);
        String[] li = s.split("");

        for (String nucleotide : li) {
            if (nucleotide.equals("A") || nucleotide.equals("C") || nucleotide.equals("G") || nucleotide.equals("T")) {
                count++;
            } else {
                counter.add(count);
                count = 0;
            }
        }

        counter.add(count);
        Collections.sort(counter);

        System.out.println(counter.get(counter.size() - 1));
    }
}

