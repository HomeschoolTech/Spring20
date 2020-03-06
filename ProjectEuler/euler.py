def triplet():
    summ = 0
    a = 0
    b = 0
    c = 0
    summ_sq = 0
    while(c < 1000):
        while(b < 1000):
            while(a < 1000):
                summ = a + b + c
                if summ == 1000:
                    summ_sq = a*a + b*b
                    if summ_sq == c*c:
                        return a*b*c
                    summ_sq = 0
                else: summ = 0
                a = a + 1
            b = b + 1
        c = c + 1

x = triplet()
print(x)
