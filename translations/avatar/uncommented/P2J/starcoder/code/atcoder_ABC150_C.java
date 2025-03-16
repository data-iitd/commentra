n = Integer.parseInt(input());
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

List<List<Integer>> orig = new ArrayList<>();
for (List<Integer> l : IntStream.range(1, n + 1).boxed().collect(Collectors.permutations(n))) {
    orig.add(l);
}

List<Integer> p = Arrays.stream(input().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
List<Integer> q = Arrays.stream(input().split(" ")).map(Integer::parseInt).collect(Collectors.toList());

int pn = orig.indexOf(p);
int qn = orig.indexOf(q);

System.out.println(Math.abs(pn - qn));

