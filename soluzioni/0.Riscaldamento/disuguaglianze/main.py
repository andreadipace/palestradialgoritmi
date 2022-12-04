with open("input.txt") as fi, open("output.txt", "w") as fo:
    N = int(fi.readline())
    m, M = 1, N
    for i in range(N - 1):
        c = fi.read(1)
        if c == '>':
            fo.write(f"{M} ")
            M -= 1
        else:
            fo.write(f"{m} ")
            m += 1
    fo.write(f"{m}")