// Read input from the user
Scanner sc = new Scanner(System.in);
String n = sc.next();

// Define a list of string representations of powers of ten
List<String> a = new ArrayList<String>();
a.add("10");
a.add("100");
a.add("1000");
a.add("10000");
a.add("100000");

// Convert the input string into a list of integers and calculate the sum
List<Integer> l = new ArrayList<Integer>();
for (int i = 0; i < n.length(); i++) {
    l.add(Integer.parseInt(n.substring(i, i + 1)));
}
int new = 0;
for (int i = 0; i < l.size(); i++) {
    new += l.get(i);
}

// Check if the input is one of the predefined values in the list 'a'
if (a.contains(n)) {
    // If the input matches one of the predefined values, print 10
    System.out.println(10);
} else {
    // If the input does not match, print the calculated sum
    System.out.println(new);
}

