import collections
import sys

# Node class representing each node in the Trie
class Node:
    # Map to hold child nodes for each character
    child = collections.defaultdict(Node)
    # Suffix link to facilitate pattern matching
    suffixLink = None
    # Output link for patterns that end at this node
    outputLink = None
    # Index of the pattern if this node represents the end of a pattern
    patternInd = -1

    # Constructor to initialize a new node
    def __init__(self):
        self.suffixLink = None
        self.outputLink = None
        self.patternInd = -1

# Trie class for storing patterns and searching them in a given text
class Trie:
    # Root node of the Trie
    root = Node()
    # Array of patterns to be searched
    patterns = []

    # Constructor to initialize the Trie with patterns
    def __init__(self, patterns):
        self.patterns = patterns
        self.buildTrie() # Build the Trie structure
        self.buildSuffixAndOutputLinks() # Build suffix and output links for efficient searching

    # Method to build the Trie from the given patterns
    def buildTrie(self):
        for i in range(len(self.patterns)):
            curr = self.root # Start from the root for each pattern
            for c in self.patterns[i]:
                # Create child nodes for each character in the pattern
                curr = curr.child[c]
            # Mark the end of the pattern with its index
            curr.patternInd = i

    # Method to build suffix and output links for the Trie
    def buildSuffixAndOutputLinks(self):
        self.root.suffixLink = self.root # Root's suffix link points to itself
        queue = collections.deque() # Queue for BFS

        # Initialize suffix links for the direct children of the root
        for child in self.root.child.values():
            child.suffixLink = self.root # Direct children point to root
            queue.append(child) # Add to queue for processing

        # Process nodes in the queue to establish suffix and output links
        while len(queue) > 0:
            current = queue.popleft() # Get the current node from the queue
            for ch, child in current.child.items():
                suffix = current.suffixLink # Start with the current node's suffix link

                # Follow suffix links until a matching child is found or root is reached
                while suffix!= self.root and not suffix.child.has_key(ch):
                    suffix = suffix.suffixLink

                # If a matching child is found, update the suffix link
                if suffix.child.has_key(ch):
                    suffix = suffix.child[ch]
                child.suffixLink = suffix # Set the suffix link for the child

                # Set the output link based on the suffix node
                if suffix.patternInd!= -1:
                    child.outputLink = suffix # If suffix is a pattern end, set output link
                else:
                    child.outputLink = suffix.outputLink # Otherwise, inherit output link
                queue.append(child) # Add child to the queue for further processing

    # Method to search for patterns in the given text
    def search(self, text):
        # Map to store matches for each pattern
        matches = collections.defaultdict(list)
        for pattern in self.patterns:
            matches[pattern] = [] # Initialize list for each pattern
        current = self.root # Start from the root of the Trie

        # Iterate through each character in the text
        for i in range(len(text)):
            ch = text[i] # Current character in the text
            # Follow suffix links if the character is not found in the current node's children
            while current!= self.root and not current.child.has_key(ch):
                current = current.suffixLink
            # If the character is found, move to the corresponding child node
            if current.child.has_key(ch):
                current = current.child[ch]
            temp = current # Temporary node for output link traversal

            # Traverse through output links to find all patterns that end at this position
            while temp!= None:
                if temp.patternInd!= -1:
                    # Add the starting index of the found pattern to the matches
                    matches[self.patterns[temp.patternInd]].append(i - len(self.patterns[temp.patternInd]) + 1)
                temp = temp.outputLink # Move to the next output link

        return matches # Return the map of matches

# Main method to run the program
if __name__ == "__main__":
    # Read the text to search patterns in
    text = sys.stdin.readline().strip()
    # Read the number of patterns
    patternCount = int(sys.stdin.readline().strip())
    # Read each pattern
    patterns = []
    for i in range(patternCount):
        patterns.append(sys.stdin.readline().strip())

    # Create a Trie with the given patterns
    trie = Trie(patterns)
    # Search for patterns in the text
    result = trie.search(text)

    # Print the results of the pattern matches
    print "Pattern matches:"
    for pattern in patterns:
        print pattern + ": " + str(result[pattern]) # Display each pattern and its matches

