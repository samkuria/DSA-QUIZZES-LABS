def rotate_array(arr,steps):
    steps=steps%len(arr)
    return arr[-steps:] + arr[:-steps]

nums=[90,90,91,92,93,96,96,98]
rotate_list=rotate_array(nums,3)
print("ROTATED LIST:",rotate_list)