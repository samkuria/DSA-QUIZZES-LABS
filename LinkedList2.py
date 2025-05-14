class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def detectCycle(head):
    if not head or not head.next:
        return None
    
    slow = head
    fast = head
    
    
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            break
    
    
    if slow != fast:
        return None
    
   
    slow = head
    while slow != fast:
        slow = slow.next
        fast = fast.next
    
    return slow 


def createLinkedList(lst, pos):
    if not lst:
        return None
    
    nodes = [ListNode(val) for val in lst]
    head = nodes[0]
    
    for i in range(len(nodes) - 1):
        nodes[i].next = nodes[i + 1]
    
    if pos != -1:  
        nodes[-1].next = nodes[pos]
    
    return head


if __name__ == "__main__":
    
    head1 = createLinkedList([3, 2, 0, -4], 1)
    cycle_start = detectCycle(head1)
    print(cycle_start.val if cycle_start else "No cycle")  

    
    head2 = createLinkedList([1, 2], 0)
    cycle_start = detectCycle(head2)
    print(cycle_start.val if cycle_start else "No cycle")  

    
    head3 = createLinkedList([1], -1)
    cycle_start = detectCycle(head3)
    print(cycle_start.val if cycle_start else "No cycle") 