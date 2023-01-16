import sys
import csv

if (len(sys.argv) == 3):
    strands = []
    names = {}
    with open(sys.argv[1]) as file:
        for i, row in enumerate(file):
            if i == 0:
                strands = [j for j in row.strip().split(',')][1:]
            else:
                Row = row.strip().split(',')
                names[Row[0]] = [int(x) for x in Row[1:]]

    f = open(sys.argv[2], "r").read()
    final_strands = []
    for i in strands:
        consecutive_count = 0
        max_strand = -1
        j = 0
        while j < len(f):
            strand_block = f[j:(j + len(i))]
            if strand_block == i:
                consecutive_count += 1
                max_strand = max(max_strand, consecutive_count)
                j += len(i)
            else:
                consecutive_count = 0
                j += 1
        final_strands.append(max_strand)
    
    for name,dna in names.items():
        if dna == final_strands:
            print(name)
            exit(0)
        
    print("No match")
        
                
else:
    sys.exit("Usage: python dna.py data.csv sequence.txt")
