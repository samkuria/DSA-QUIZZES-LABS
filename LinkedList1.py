class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def hasCycle(head):
    if not head or not head.next:
        return False
    
    slow = head
    fast = head.next
    
    while slow != fast:
        if not fast or not fast.next:
            return False
        slow = slow.next
        fast = fast.next.next
    
    return True


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
    print(hasCycle(head1))  

    
    head2 = createLinkedList([1, 2], 0)
    print(hasCycle(head2))  

    
    head3 = createLinkedList([1], -1)
    print(hasCycle(head3))  