#include <iostream>
using namespace std;

// Node class definition
class Node {
public:
    Node *previous; // Pointer to the previous node
    int data;       // Data stored in the node
    Node *next;     // Pointer to the next node
};

// Function to insert a new node at a given position
Node* Insert(int pos, int x, Node *head) {
    Node *t = new Node; // Create a new node
    t->data = x;        // Set the data for the new node

    if (pos == 0) { // Insertion at the head
        t->previous = NULL;
        t->next = head;
        if (head != NULL) {
            head->previous = t; // Update the previous head's pointer
        }
        head = t; // Update head to the new node
    } else { // Insertion at other positions
        Node *p = head;
        for (int i = 0; i < pos - 1 && p != NULL; i++) {
            p = p->next; // Traverse to the position
        }
        if (p != NULL) {
            t->previous = p;
            t->next = p->next;
            if (p->next) {
                p->next->previous = t; // Update the next node's previous pointer
            }
            p->next = t; // Link the new node
        }
    }
    return head; // Return the updated head
}

// Function to display the linked list
void display(Node *head) {
    Node *p = head;
    while (p != NULL) {
        cout << p->data << " "; // Print the data
        p = p->next; // Move to the next node
    }
    cout << endl; // New line after displaying all elements
}

// Main function
int main() {
    Node *first = NULL; // Initialize the head of the list
    int n, x, pos;
    cout << "Enter the number of elements in the list: ";
    cin >> n; // Input number of elements
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << (i + 1) << ": ";
        cin >> x; // Input element data
        first = Insert(i, x, first); // Insert element into the list
    }
    display(first); // Display the linked list
    return 0; // End of program
}
