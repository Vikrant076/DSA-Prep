/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        if (!head) return head;

        // Step 1: find length
        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // if k is invalid
        if (k > n) return head;

        // If both are the same node (middle element in odd length list)
        if (2*k - 1 == n) return head;

        // Step 2: find kth node from start
        Node* first = head;
        for (int i = 1; i < k; i++) {
            first = first->next;
        }

        // Step 3: find kth node from end -> (n-k+1)th from start
        Node* second = head;
        for (int i = 1; i < n-k+1; i++) {
            second = second->next;
        }

        // Step 4: swap data
        int tempVal = first->data;
        first->data = second->data;
        second->data = tempVal;

        return head;
    }
};
