#!/usr/bin/env python3
import sys

TILE = [' ', 'U', 'R', 'D', 'L', '#', 'S', 'S', 'S', 'S']

with open(sys.argv[1], 'r') as fd:
    txt = fd.read()

print(*[(TILE[ord(i) - 48] if 48 <=ord(i) < 58 else i) for i in txt], sep='')
