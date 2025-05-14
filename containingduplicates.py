def searchduplicates(arr):
    return len(arr) != len(set(arr))

nums1=[90,90,91,92,93,96,96,98]
print("Has Duplicates:",searchduplicates(nums1))
nums2=[90,91,92,93,96,98]
print("Has Duplicates:",searchduplicates(nums2))