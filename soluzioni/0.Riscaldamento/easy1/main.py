with open("input.txt") as fi:
    fi.readline()
    v = fi.readline().split()
    v = list(map(lambda x: int(x), v))
    m = max(v)

with open("output.txt", "w") as fo:
    fo.write(m)
