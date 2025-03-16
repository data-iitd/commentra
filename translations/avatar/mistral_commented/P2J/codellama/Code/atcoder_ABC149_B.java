// Define a list 'cookies' by using list comprehension
List<Integer> cookies = new ArrayList<>();
for (String x : input.split(" ")) {
    cookies.add(Integer.parseInt(x));
}

// Calculate the difference between the number of cookies given to the first and second child
int leftOver = cookies.get(0) - cookies.get(2);

// Set the 'takahashi' variable to the maximum value between 0 and the 'leftOver' variable
int takahashi = Math.max(0, leftOver);

// Print the result using string concatenation
System.out.print(takahashi + " " +
                 (takahashi > 0 ? cookies.get(1) :
                  Math.max(0, cookies.get(1) - Math.abs(leftOver))));

