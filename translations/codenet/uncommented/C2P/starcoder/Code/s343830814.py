
#!/usr/bin/env python

import sys

buf = sys.stdin.read(512)
len = len(buf)
print buf[0] + str(len-3) + buf[len-2]

