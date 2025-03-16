// This line takes two integers, n and k, as input from the user.
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
int k = sc.nextInt();

// This line prints the sum of the first k smallest numbers from the list of integers input in the next line.
System.out.println(Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer::parseInt).sorted().limit(k).sum());

