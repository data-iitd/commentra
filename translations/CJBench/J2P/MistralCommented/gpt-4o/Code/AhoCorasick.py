from collections import defaultdict, deque

class Node:
    def __init__(self):
        self.child = {}  # Initialize an empty dictionary for child nodes
        self.suffix_link = None  # Initialize a null suffix link
        self.output_link = None  # Initialize a null output link
        self.pattern_ind = -1  # Initialize a -1 for pattern index

class Trie:
    def __init__(self, patterns):
        self.root = Node()  # Initialize the root Node
        self.patterns = patterns  # Store the patterns
        self.build_trie()  # Build the Trie data structure
        self.build_suffix_and_output_links()  # Build suffix and output links

    def build_trie(self):
        for i, pattern in enumerate(self.patterns):
            curr = self.root  # Initialize current Node as root
            for c in pattern:  # Iterate through each character in the pattern
                curr = curr.child.setdefault(c, Node())  # Create a new child Node if it doesn't exist
            curr.pattern_ind = i  # Set the pattern index when reaching the end of the pattern

    def build_suffix_and_output_links(self):
        self.root.suffix_link = self.root  # Initialize the suffix link of the root Node as itself
        queue = deque()  # Initialize a Queue for BFS traversal
        for child in self.root.child.values():  # Add all children to the Queue
            child.suffix_link = self.root  # Initialize the suffix link of each child as the root
            queue.append(child)
        
        while queue:  # Perform BFS traversal
            current = queue.popleft()  # Dequeue a Node
            for ch, child in current.child.items():  # Iterate through each child
                suffix = current.suffix_link  # Initialize suffix as the suffix link of the current Node
                while suffix != self.root and ch not in suffix.child:  # Find the common suffix Node
                    suffix = suffix.suffix_link
                if ch in suffix.child:  # If a suffix Node is found
                    suffix = suffix.child[ch]  # Update suffix to the found suffix Node
                child.suffix_link = suffix  # Set the suffix link of the current child Node
                if suffix.pattern_ind != -1:  # If the suffix Node has a pattern index
                    child.output_link = suffix  # Set the output link of the current child Node to the suffix Node
                else:  # Otherwise, set the output link to the output link of the suffix Node
                    child.output_link = suffix.output_link
                queue.append(child)  # Add the current child Node to the Queue for further traversal

    def search(self, text):
        matches = defaultdict(list)  # Initialize an empty dictionary to store the results
        for pattern in self.patterns:  # Initialize an empty list to store the matches for each pattern
            matches[pattern] = []
        
        current = self.root  # Initialize the current Node as the root
        for i in range(len(text)):  # Iterate through each character in the text
            ch = text[i]  # Get the current character
            while current != self.root and ch not in current.child:  # Find the common prefix Node
                current = current.suffix_link
            if ch in current.child:  # If a child Node is found
                current = current.child[ch]  # Update the current Node to the found child Node
            
            temp = current  # Initialize a temporary Node to traverse the output links
            while temp:  # Traverse the output links
                if temp.pattern_ind != -1:  # If a pattern Node is found
                    matches[self.patterns[temp.pattern_ind]].append(i - len(self.patterns[temp.pattern_ind]) + 1)  # Add the match index
                temp = temp.output_link  # Update the temporary Node to the next output Node
        
        return matches  # Return the dictionary containing the pattern matches

# Main method to read input and call the Trie search method
if __name__ == "__main__":
    text = input()  # Read the text from input
    pattern_count = int(input())  # Read the number of patterns from input
    patterns = [input().strip() for _ in range(pattern_count)]  # Read each pattern from input
    trie = Trie(patterns)  # Create a new Trie object with the given patterns
    result = trie.search(text)  # Call the search method to find the pattern matches in the text
    print("Pattern matches:")  # Print the header for the output
    for pattern in patterns:  # Iterate through each pattern
        print(f"{pattern}: {result[pattern]}")  # Print the pattern and its matches

# <END-OF-CODE>
