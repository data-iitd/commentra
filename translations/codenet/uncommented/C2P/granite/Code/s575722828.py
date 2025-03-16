
import sys

S = int(sys.stdin.read())

print "%d:%d:%d" % (S/3600, (S % 3600) / 60, S % 60)

