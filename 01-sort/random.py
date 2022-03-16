from itertools import permutations

# 产生0-6的所有排列组合，写入numbers.txt
with open("numbers.txt", "w") as f:
    for i in permutations(range(7), 7):
        line = str(i).strip("()")
        line = line.split(",")
        line = "".join(line)
        f.write(line)
        f.write("\n")
