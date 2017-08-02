#!/usr/bin/python

rows = 24
cols = 32
win_width = 12
win_height = 12
win_start_r = (rows/2) - (win_height/2)
win_end_r   = (rows/2) + (win_height/2)
win_start_c = (cols/2) - (win_width/2)
win_end_c   = (cols/2) + (win_width/2)
matrix = [['+' for x in range(cols)] for x in range(rows)]

# Modify the matrix
for r in range(win_start_r, win_end_r):
    for c in range(win_start_c, win_end_c):
        matrix[r][c] = '#'


# Print the matrix
for r in range(rows):
    for c in range(cols):
        print matrix[r][c],
    print ''
