#include <iostream>
using namespace std;

// A linked list node
struct Node
{
   double data;
   struct Node *next;
};

//insert a new node in front of the list
void push(struct Node** head, int node_data) {
   struct Node* newNode = new Node;
   newNode->data = node_data;
   newNode->next = (*head);
   (*head) = newNode;
}

void insertAfter(struct Node* prev_node, int node_data) {
  if (prev_node == NULL) {
     cout<<"the given previous node is required,cannot be NULL";
     return;
   }
   struct Node* newNode =new Node;
   newNode->data = node_data;
   newNode->next = prev_node->next;
   prev_node->next = newNode;
}

void append(struct Node** head, int node_data) {
  struct Node* newNode = new Node;
  struct Node *last = *head;
  newNode->data = node_data;
  newNode->next = NULL;

  if (*head == NULL) {
  *head = newNode;
  return; }

  while (last->next != NULL)
  last = last->next;
  last->next = newNode;
  return;
}


void displayList(struct Node *node) {
   if (node != NULL) {
      cout << node->data << "--->";
      displayList(node->next);
   } else {
     cout << "null";
   }
}




int main() {

struct Node* head = NULL;

push(&head, 20.0f);
push(&head, 10.0f);
push(&head, 15.0f);
push(&head, 60.0f);
push(&head, 30.0f);
push(&head, 15.0f);
push(&head, 50.0f);
push(&head, 10.0f);

// cout<<"Final linked list: "<<endl;
displayList(head);

return 0;
}
