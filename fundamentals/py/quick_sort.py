def qsort(data):
    if len(data) <= 1:
        return data
    left, right = [],[]
    pivot = data[0]

    left = [item for item in data[1:] if pivot > item]
    right = [item for item in data[1:] if pivot < item]

    return qsort(left) + [pivot] + qsort(right)


import random

data_list = random.sample(range(100) ,10)
qsort(data_list)