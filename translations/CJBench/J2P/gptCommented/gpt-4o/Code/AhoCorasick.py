from collections import defaultdict, deque

class Node:
    def __init__(self):
        self.child = {}  # Map to hold child nodes for each character
        self.suffix_link = None  # Suffix link for pattern matching
        self.output_link = None  # Output link for patterns that end at this node
        self.pattern_ind = -1  # Index of the pattern if this node represents the end of a pattern

class Trie:
    def __init__(self, patterns):
        self.root = Node()  # Root node of the Trie
        self.patterns = patterns  # Array of patterns to be searched
        self.build_trie()  # Build the Trie structure
        self.build_suffix_and_output_links()  # Build suffix and output links for efficient searching

    def build_trie(self):
        for i, pattern in enumerate(self.patterns):
            curr = self.root  # Start from the root for each pattern
            for c in pattern:
                # Create child nodes for each character in the pattern
                curr = curr.child.setdefault(c, Node())
            # Mark the end of the pattern with its index
            curr.pattern_ind = i

    def build_suffix_and_output_links(self):
        self.root.suffix_link = self.root  # Root's suffix link points to itself
        queue = deque()  # Queue for BFS

        # Initialize suffix links for the direct children of the root
        for child in self.root.child.values():
            child.suffix_link = self.root  # Direct children point to root
            queue.append(child)  # Add to queue for processing

        # Process nodes in the queue to establish suffix and output links
        while queue:
            current = queue.popleft()  # Get the current node from the queue
            for ch, child in current.child.items():
                suffix = current.suffix_link  # Start with the current node's suffix link

                # Follow suffix links until a matching child is found or root is reached
                while suffix != self.root and ch not in suffix.child:
                    suffix = suffix.suffix_link

                # If a matching child is found, update the suffix link
                if ch in suffix.child:
                    suffix = suffix.child[ch]
                child.suffix_link = suffix  # Set the suffix link for the child

                # Set the output link based on the suffix node
                if suffix.pattern_ind != -1:
                    child.output_link = suffix  # If suffix is a pattern end, set output link
                else:
                    child.output_link = suffix.output_link  # Otherwise, inherit output link
                queue.append(child)  # Add child to the queue for further processing

    def search(self, text):
        matches = defaultdict(list)  # Map to store matches for each pattern
        for pattern in self.patterns:
            matches[pattern]  # Initialize list for each pattern
        current = self.root  # Start from the root of the Trie

        # Iterate through each character in the text
        for i, ch in enumerate(text):
            # Follow suffix links if the character is not found in the current node's children
            while current != self.root and ch not in current.child:
                current = current.suffix_link
            # If the character is found, move to the corresponding child node
            if ch in current.child:
                current = current.child[ch]
            temp = current  # Temporary node for output link traversal

            # Traverse through output links to find all patterns that end at this position
            while temp is not None:
                if temp.pattern_ind != -1:
                    # Add the starting index of the found pattern to the matches
                    matches[self.patterns[temp.pattern_ind]].append(i - len(self.patterns[temp.pattern_ind]) + 1)
                temp = temp.output_link  # Move to the next output link
        return matches  # Return the map of matches

# Main function to run the program
if __name__ == "__main__":
    text = input()  # Read the text to search patterns in
    pattern_count = int(input())  # Read the number of patterns

    # Array to hold the patterns
    patterns = [input() for _ in range(pattern_count)]  # Read each pattern

    # Create a Trie with the given patterns
    trie = Trie(patterns)
    # Search for patterns in the text
    result = trie.search(text)

    # Print the results of the pattern matches
    print("Pattern matches:")
    for pattern in patterns:
        print(f"{pattern}: {result[pattern]}")  # Display each pattern and its matches
