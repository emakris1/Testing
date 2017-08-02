#!/usr/bin/python2

ver_str = 'VER_STR:'

for v in ver_str:
    print '{:>2}'.format(v),

print ""

for v in ver_str:
    ver_str_hex = hex(ord(v))
    print '{:>2}'.format(ver_str_hex[2:]),
