/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
Node* floydDetectLoop(Node* head) {
    if (head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return slow;
        }
    }

    return NULL;
}

Node* getStartingNode(Node* head) {
    if (head == NULL)
        return NULL;

    Node* intersection = floydDetectLoop(head);

    if (intersection == NULL)
        return NULL;

    Node* slow = head;

    while (slow != intersection) {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

Node* removeLoop(Node* head) {
    if (head == NULL)
        return NULL;

    Node* startOfLoop = getStartingNode(head);

    if (startOfLoop == NULL)
        return head;

    Node* temp = startOfLoop;

    while (temp->next != startOfLoop) {
        temp = temp->next;
    }

    temp->next = NULL;
    return head;
}
