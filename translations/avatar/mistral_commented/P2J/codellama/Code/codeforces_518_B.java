
// We start by defining two empty dictionaries to store the frequency of each character in the strings s and t respectively
HashMap <Character, Integer> freqs = new HashMap <Character, Integer> ();
HashMap <Character, Integer> freqt = new HashMap <Character, Integer> ();

// We read the two strings s and t from the user input
Scanner sc = new Scanner (System.in);
String s = sc.nextLine ();
String t = sc.nextLine ();

// We iterate through each character in the string s and update the frequency count in the freqs dictionary
for (int i = 0; i < s.length (); i++) {
    char letra = s.charAt (i);
    if (freqs.containsKey (letra)) {
        freqs.put (letra, freqs.get (letra) + 1);
    } else {
        freqs.put (letra, 1);
    }
}

// We iterate through each character in the string t and update the frequency count in the freqt dictionary
for (int i = 0; i < t.length (); i++) {
    char letra = t.charAt (i);
    if (freqt.containsKey (letra)) {
        freqt.put (letra, freqt.get (letra) + 1);
    } else {
        freqt.put (letra, 1);
    }
}

// We initialize two counters, yay and whoops, to zero
int yay = 0;
int whoops = 0;

// We iterate through each character in the freqs dictionary and check if its frequency is greater than zero and if it is present in the freqt dictionary with a frequency greater than zero. If both conditions are true, we increment the yay counter
for (char letra : freqs.keySet ()) {
    while (freqs.get (letra) > 0 && freqt.containsKey (letra) && freqt.get (letra) > 0) {
        yay++;
        freqs.put (letra, freqs.get (letra) - 1);
        freqt.put (letra, freqt.get (letra) - 1);
    }
}

// We iterate through each character in the freqs dictionary again and check if its frequency is greater than zero. If it is, we check if its lowercase version is present in the freqt dictionary with a frequency greater than zero or if its uppercase version is present in the freqt dictionary with a frequency greater than zero. If either condition is true, we increment the whoops counter
for (char letra : freqs.keySet ()) {
    while (freqs.get (letra) > 0) {
        if (letra >= 'a' && letra <= 'z' && freqt.containsKey (letra - 'a' + 'A') && freqt.get (letra - 'a' + 'A') > 0) {
            whoops++;
            freqs.put (letra, freqs.get (letra) - 1);
            freqt.put (letra - 'a' + 'A', freqt.get (letra - 'a' + 'A') - 1);
        } else if (letra >= 'A' && letra <= 'Z' && freqt.containsKey (letra - 'A' + 'a') && freqt.get (letra - 'A' + 'a') > 0) {
            whoops++;
            freqs.put (letra, freqs.get (letra) - 1);
            freqt.put (letra - 'A' + 'a', freqt.get (letra - 'A' + 'a') - 1);
        } else {
            break;
        }
    }
}

// Finally, we print the values of yay and whoops
System.out.println (yay + " " + whoops);

