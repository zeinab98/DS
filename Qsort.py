
def partition(a, l, h):
    i = (l - 1)
    x = a[h]

    for j in range(l, h):
        if a[j] <= x:

            i = i + 1
            a[i], a[j] = a[j], a[i]

    a[i + 1], a[h] = a[h], a[i + 1]
    return (i + 1)



def quickSort(a, l, h):

    size = h - l + 1
    stack = [0] * (size)


    top = -1


    top = top + 1
    stack[top] = l
    top = top + 1
    stack[top] = h


    while top >= 0:


        h = stack[top]
        top = top - 1
        l = stack[top]
        top = top - 1

        p = partition(a, l, h)

        if p - 1 > l:
            top = top + 1
            stack[top] = l
            top = top + 1
            stack[top] = p - 1

        if p + 1 < h:
            top = top + 1
            stack[top] = p + 1
            top = top + 1
            stack[top] = h

        # Driver code to test above


a = [8,6,5,1,4,3,1000,20,10]
n = len(a)
quickSort(a, 0, n - 1)
print("Sorted aay is:")
for i in range(n):
    print("%d" % a[i]),
