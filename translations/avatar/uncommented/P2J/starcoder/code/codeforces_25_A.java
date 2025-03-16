n = Integer.parseInt(input());
List<Integer> list = Arrays.stream(input().split(" ")).map(Integer::parseInt).map(x -> x % 2).collect(Collectors.toList());
if (list.stream().mapToInt(Integer::intValue).sum() == 1) {
    System.out.println(list.indexOf(1) + 1);
} else {
    System.out.println(list.indexOf(0) + 1);
}

