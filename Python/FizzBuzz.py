#!/usr/bin/python

for i in range(1, 101):
    index_str = ''
    if i % 3 == 0:
        index_str += 'fizz'
    if i % 5 == 0:
        index_str += 'buzz'
    if i % 3 != 0 and i % 5 != 0:
        index_str = str(i)
    print(str(i) + ': ' + index_str)
