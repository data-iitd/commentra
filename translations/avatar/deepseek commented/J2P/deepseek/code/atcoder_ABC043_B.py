import sys
import io
import os
import re

class LightScanner:
    def __init__(self, input_stream):
        self.input_stream = input_stream
    
    def string(self):
        if not hasattr(self, 'tokenizer'):
            self.tokenizer = re.split(r'\s+', self.input_stream.readline().decode().strip())
        if not self.tokenizer:
            self.tokenizer = re.split(r'\s+', self.input_stream.readline().decode().strip())
        result = self.tokenizer[0]
        self.tokenizer = self.tokenizer[1:]
        return result

class BUnhappyHackingABCEdit:
    def solve(self, test_number, in_instance, out_instance):
        s = in_instance.string()
        result = []
        for c in s:
            if c == '0':
                result.append('0')
            elif c == '1':
                result.append('1')
            elif c == 'B' and result:
                result.pop()
        out_instance.write(''.join(result) + '\n')

def main():
    input_stream = sys.stdin
    output_stream = sys.stdout
    in_instance = LightScanner(input_stream)
    out_instance = io.TextIOWrapper(output_stream)
    solver = BUnhappyHackingABCEdit()
    solver.solve(1, in_instance, out_instance)
    out_instance.flush()

if __name__ == "__main__":
    main()

