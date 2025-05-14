def singlenumber(arr):
    return sum(set(arr))*2-sum(arr)

nums=[90,90,91,91,92]
single_number=singlenumber(nums)
print("The single number is:", single_number)