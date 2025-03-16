// We start by defining two empty dictionaries to store the frequency of each character in the strings s and t respectively
Map<Character, Integer> freqs = new HashMap<> ();
Map<Character, Integer> freqt = new HashMap<> ();

// We read the two strings s and t from the user input
String s = scanner.next ();
String t = scanner.next ();

// We iterate through each character in the string s and update the frequency count in the freqs dictionary
for (char letra : s.toCharArray ()):
    if (freqs.containsKey (letra)):
        freqs.put (letra, freqs.get (letra) + 1);
    else:
        freqs.put (letra, 1);

// We iterate through each character in the string t and update the frequency count in the freqt dictionary
for (char letra : t.toCharArray ()):
    if (freqt.containsKey (letra)):
        freqt.put (letra, freqt.get (letra) + 1);
    else:
        freqt.put (letra, 1);

// We initialize two counters, yay and whoops, to zero
int yay = 0, whoops = 0;

// We iterate through each character in the freqs dictionary and check if its frequency is greater than zero and if it is present in the freqt dictionary with a frequency greater than zero. If both conditions are true, we increment the yay counter
for (char letra : freqs.keySet ()):
    while (freqs.get (letra) > 0 && freqt.containsKey (letra) && freqt.get (letra) > 0):
        yay += 1;
        freqs.put (letra, freqs.get (letra) - 1);
        freqt.put (letra, freqt.get (letra) - 1);

// We iterate through each character in the freqs dictionary again and check if its frequency is greater than zero. If it is, we check if its lowercase version is present in the freqt dictionary with a frequency greater than zero or if its uppercase version is present in the freqt dictionary with a frequency greater than zero. If either condition is true, we increment the whoops counter
for (char letra : freqs.keySet ()):
    while (freqs.get (letra) > 0):
        if (Character.isLowerCase (letra) && freqt.containsKey (Character.toUpperCase (letra)) && freqt.get (Character.toUpperCase (letra)) > 0):
            whoops += 1;
            freqs.put (letra, freqs.get (letra) - 1);
            freqt.put (Character.toUpperCase (letra), freqt.get (Character.toUpperCase (letra)) - 1);
        else if (Character.isUpperCase (letra) && freqt.containsKey (Character.toLowerCase (letra)) && freqt.get (Character.toLowerCase (letra)) > 0):
            whoops += 1;
            freqs.put (letra, freqs.get (letra) - 1);
            freqt.put (Character.toLowerCase (letra), freqt.get (Character.toLowerCase (letra)) - 1);
        else:
            break;

// Finally, we print the values of yay and whoops
System.out.println (yay + " " + whoops);

