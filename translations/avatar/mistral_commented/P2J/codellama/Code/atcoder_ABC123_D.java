// Read input: four integers x, y, z, and k followed by x * y integers each for lists a, b, and c
Scanner sc = new Scanner(System.in);
int x = sc.nextInt();
int y = sc.nextInt();
int z = sc.nextInt();
int k = sc.nextInt();

// Initialize an empty list ab to store the sum of each element from list a with each element from list b
ArrayList<Integer> ab = new ArrayList<>();

// Iterate through each element in list a for i, and for each element in list b for j, append their sum to list ab
for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
        ab.add(a[i] + b[j]);
    }
}

// Sort list ab in descending order
Collections.sort(ab, Collections.reverseOrder());

// Initialize an empty list abc to store the sum of each element from list ab with each element from list c
ArrayList<Integer> abc = new ArrayList<>();

// Iterate through each valid index i in the range of min(k, x * y), and for each index j in the range of z, append their sum to list abc
for (int i = 0; i < Math.min(k, x * y); i++) {
    for (int j = 0; j < z; j++) {
        abc.add(ab.get(i) + c[j]);
    }
}

// Sort list abc in descending order
Collections.sort(abc, Collections.reverseOrder());

// Iterate through the first k elements of list abc and print each element
for (int i = 0; i < k; i++) {
    System.out.println(abc.get(i));
}

