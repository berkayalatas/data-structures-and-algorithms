def insertion_sort(arr):
    for i in range(1, len(arr)):
        current = arr[i]
        position=i

        while position >= 0 and arr[position-1] > current:
            arr[position] = arr[position-1]
            position -= 1

        arr[position] = current

    return arr 

print(insertion_sort([1,3,6,4,9,2,5,5,12]))          
#output [1, 2, 3, 4, 5, 5, 6, 9, 12]



