#!/usr/bin/python 2.7
import math
import fileinput
import mmap

# Implement Tarantula using gcov, and describe the process of using it to
# localize a bug in Dominion. Write this up as tarantula.txt, and include any  
# relevant code or files. This will require:
#      1) generating gcov files for each test somehow (these could be random
#         tests defined by their seeds)
#      2) attaching information on whether these tests pass or fail to each
#         test somehow
#      3) parsing the gcov files and using the tarantula formula.

parsed = open('parsed_utr.out', 'w+')

with open('utresults/unittestresults.out', 'r') as f:
#    print 'FILED OPENED: ', f.name, "\n"
    #content = [x.strip('\n') for x in f.readlines()]
    # Reads text until the end of the block
    content = f.read().splitlines()
    for line in content:
        if line.strip() == 'Starting game.':
            break
#        print "Read line: ", (line)
        parsed.write(line)
        parsed.write('\n')

#    for line in content:    
#        if line.strip() == 'GCOV AFTER PLAYING A GAME':
#            break
#        print "Read line: ", (line)

# Close opened files
f.close()
parsed.close()

failures = open('failed.out', 'w+')
start_print = False

parsed = open('parsed_utr.out')
pcontent = parsed.read().splitlines()
s = mmap.mmap(parsed.fileno(), 0, access=mmap.ACCESS_READ)
if s.find('FAILED ASSERTION') != -1:
    for aline in pcontent:
        if start_print or 'FAILED ASSERTION' in aline:
            failures.write(aline)
            failures.write('\n')
            # print aline
            start_print = True
            if "Creating 'dominion.c.gcov'" in aline:
                start_print = False

# Close opened files
parsed.close()
failures.close()

spliced = []
ft = []

failures = open('failed.out', 'r')
fcontent = failures.read().splitlines()
n = mmap.mmap(failures.fileno(), 0, access=mmap.ACCESS_READ)
if n.find('Testing') != -1:
    for mline in fcontent:
        if 'Testing' in mline:
            spliced =  mline.split()
            ft.append(spliced[1])
print ft

# Closed opened file
failures.close()

# auggggggggh

