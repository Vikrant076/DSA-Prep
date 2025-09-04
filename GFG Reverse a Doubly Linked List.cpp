class Solution {
  public:
    Node *reverse(Node *head) {
        Node* temp = nullptr;
        Node* current = head;
        
        while (current != nullptr) {
            // Swap next and prev
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            
            // Move to the next node in original order (which is prev now)
            current = current->prev;
        }
        
        // Update head to the new front of the list
        if (temp != nullptr)
            head = temp->prev;
        
        return head;
    }
};
