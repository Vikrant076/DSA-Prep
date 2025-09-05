class Solution {
public:
    int lengthOfLoop(Node* head) {
        if (!head) return 0;
        
        Node *slow = head, *fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {  // loop detected
                return countLength(slow);
            }
        }
        return 0; // no loop
    }
    
private:
    int countLength(Node* nodeInLoop) {
        int count = 1;
        Node* temp = nodeInLoop->next;
        
        while (temp != nodeInLoop) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};
