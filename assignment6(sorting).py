# Bubble Sort function with comparison count
def bubbleSort(l):
    swapped = False
    count = 0
    for x in range(len(l)):
        for i in range(0, len(l) - x - 1):
            count += 1
            if l[i] > l[i + 1]:
                l[i], l[i + 1] = l[i + 1], l[i]
                swapped = True
        if not swapped:
            break
    print(f"Bubble Sort Comparisons: {count}")
    return l

# Selection Sort function
def selectionSort(l):
    count = 0
    for i in range(len(l)):
        min_index = i
        for j in range(i + 1, len(l)):
            count += 1
            if l[j] < l[min_index]:
                min_index = j
        l[i], l[min_index] = l[min_index], l[i]
    print(f"Selection Sort Comparisons: {count}")
    return l

# Read and parse the list from user input
l = eval(input("Enter your unsorted list: "))
l2 = l.copy()

# Perform Bubble Sort and print the result
print("Bubble Sort Result:")
print(bubbleSort(l))

print()

# Perform Selection Sort and print the result
print("Selection Sort Result:")
print(selectionSort(l2))
