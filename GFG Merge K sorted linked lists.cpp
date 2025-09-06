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
    struct compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data; // min-heap by node->data
        }
    };
    
    Node* mergeKLists(vector<Node*>& arr) {
        priority_queue<Node*, vector<Node*>, compare> pq;
        
        // Push the head of each list
        for (auto list : arr) {
            if (list) pq.push(list);
        }
        
        Node* dummy = new Node(0);
        Node* tail = dummy;
        
        // Build the merged list
        while (!pq.empty()) {
            Node* node = pq.top();
            pq.pop();
            
            tail->next = node;
            tail = tail->next;
            
            if (node->next) {
                pq.push(node->next);
            }
        }
        
        return dummy->next;
    }
};
