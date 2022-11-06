import math

def eq2(a, b, c):
    det = pow(b, 2) - 4 * a * c
    x1 = (-b - math.sqrt(det)) / 2 * a
    x2 = (-b + math.sqrt(det)) / 2 * a
    return (x1, x2)

with open("input.txt") as fi:
    G, N = list(map(lambda x: int(x), fi.readline().split()))

_, giri = eq2(1, 2 * N - 1, -2 * G);
giri = int(giri)

TOTO = giri * (giri + 1) / 2
G -= TOTO + giri * (N - 1)
TOTO += G
TOTO = int(TOTO)

with open("output.txt", "w") as fo:
    fo.write(str(TOTO))