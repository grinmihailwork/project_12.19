#include <iostream>
#include <fstream>
using namespace std;

// A linked list node
struct Node
{
   double data;
   struct Node *next;
};

//insert a new node in front of the list
void push(struct Node** head, double node_data) {
   struct Node* newNode = new Node;
   newNode->data = node_data;
   newNode->next = (*head);
   (*head) = newNode;
}



void displayList(struct Node *node) {
   if (node != NULL) {
      cout << node->data << "--->";
      displayList(node->next);
   } else {
     cout << "null\n";
   }
}

double findMaximum(struct Node *node) {
  double current = node->data;
  double next;
  if (node->next == NULL) {
    return current;
  } else {
    next = findMaximum(node->next);
  }
  if (current > next) { return current;
  } else { return next; }
}

void writeToFile(struct Node *node, ofstream &file) {
  if (node != NULL) {
     file << node->data << "-->";
     writeToFile(node->next, file);
  } else {
    file << "null";
  }
}

void merge(Node *p, Node **q)
{
    Node *p_curr = p, *q_curr = *q;
    Node *p_next, *q_next;

    // While therre are avialable positions in p
    while (p_curr != NULL && q_curr != NULL)
    {
        // Save next pointers
        p_next = p_curr->next;
        q_next = q_curr->next;

        // Make q_curr as next of p_curr
        q_curr->next = p_next; // Change next pointer of q_curr
        p_curr->next = q_curr; // Change next pointer of p_curr

        // Update current pointers for next iteration
        p_curr = p_next;
        q_curr = q_next;
    }

    *q = q_curr; // Update head pointer of second list
}

Node* mergeLists(Node* headA, Node* headB) {
    if (headA == NULL && headB == NULL) return NULL;
    else if (headA == NULL) return headB;
    else if (headB == NULL) return headA;

    if(headA->data >= headB->data)
        headA->next = mergeLists(headA->next, headB);
    else {
        Node* temp = headB;
        headB = headB->next;
        temp->next = headA;
        headA = temp;
        headA->next = mergeLists(headA->next, headB);
    }
    return headA;
}

int main() {

  struct Node* list1 = NULL;

  push(&list1, 10.0f);
  push(&list1, 10.0f);
  push(&list1, 15.0f);
  push(&list1, 15.0f);
  push(&list1, 30.0f);
  push(&list1, 40.0f);
  push(&list1, 50.0f);
  push(&list1, 50.0f);

  struct Node* list2 = NULL;

  push(&list2, 10.0f);
  push(&list2, 15.0f);
  push(&list2, 20.0f);
  push(&list2, 20.0f);
  push(&list2, 50.0f);
  push(&list2, 60.0f);


  struct Node* sorted = NULL;
  //COPY LISTS
  struct Node* current1 = list1;
  struct Node* current2 = list2;


  while (current1 != NULL && current2 != NULL) {
    if (current1->data > current2->data) {
      push(&sorted, current1->data);
      current1 = current1->next;
    } else {
      push(&sorted, current2->data);
      current2 = current2->next;
    }
  }

  while (current1 != NULL) {
    push(&sorted, current1->data);
    current1 = current1->next;
  }
  while (current2 != NULL) {
    push(&sorted, current2->data);
    current2 = current2->next;
  }

  displayList(sorted);


  displayList(mergeLists(list1, list2));
  displayList(list2);


  //
  //
  // Node *p = NULL, *q = NULL;
  //  push(&p, 3);
  //  push(&p, 2);
  //  push(&p, 1);
  //  cout<<"First Linked List:\n";
  //  displayList(p);
  //
  //  push(&q, 8);
  //  push(&q, 7);
  //  push(&q, 6);
  //  push(&q, 5);
  //  push(&q, 4);
  //  cout<<"Second Linked List:\n";
  //  displayList(q);
  //
  //  merge(p, &q);
  //
  //  cout<<"Modified First Linked List:\n";
  //  displayList(p);
  //
  //  cout<<"Modified Second Linked List:\n";
  //  displayList(q);
  //
  //
  //
  //
  //


  return 0;
}
