/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // helper function to reverse a segment [head..tail]
    Node* reverseSegment(Node* head, Node* tail) {
        Node* prev = tail->next;
        Node* curr = head;
        while (prev != tail) {
            Node* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return tail; // new head of this segment
    }

    Node *reverseKGroup(Node *head, int k) {
        if (!head || k == 1) return head;

        Node dummy(0);
        dummy.next = head;
        Node* prevGroupEnd = &dummy;

        while (true) {
            Node* kth = prevGroupEnd;
            // try to locate kth node
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }

            if (!kth) {
                // fewer than k nodes left → reverse them all
                Node* groupStart = prevGroupEnd->next;
                if (!groupStart) break;
                Node* last = groupStart;
                while (last->next) last = last->next;
                prevGroupEnd->next = reverseSegment(groupStart, last);
                break;
            }

            Node* groupStart = prevGroupEnd->next;
            Node* groupEnd = kth;
            Node* nextGroupStart = groupEnd->next;

            prevGroupEnd->next = reverseSegment(groupStart, groupEnd);
            prevGroupEnd = groupStart;
            prevGroupEnd->next = nextGroupStart;
        }

        return dummy.next;
    }
};
