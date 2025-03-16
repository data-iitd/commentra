n = Integer.parseInt(input());
List<String[]> q = new ArrayList<>();
int count = 0;
for (int i = 0; i < n; i++) {
    String[] a = input().split(" ");
    q.add(a);
}
for (String[] j : q) {
    for (String[] k : q) {
        if (k == j) {
            continue;
        } else if (j[0].equals(k[k.length - 1])) {
            count++;
        } else {
            continue;
        }
    }
}
System.out.println(count);

