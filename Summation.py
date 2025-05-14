def summation(arr):
    return sum(arr)

def maximum(arr):
    if not arr: 
        return None
    return max(arr)

def main():
   
    n = int(input("Enter the number of elements in the array: "))
    
   
    arr = []
    
    
    print(f"Enter {n} integers:")
    for i in range(n):
        num = int(input(f"Element {i+1}: "))
        arr.append(num)
    
    
    print("\nResults:")
    print(f"Sum of array elements: {summation(arr)}")
    
    max_val = maximum(arr)
    if max_val is not None:
        print(f"Maximum value in array: {max_val}")
    else:
        print("Array is empty, no maximum value")

if __name__ == "__main__":
    main()