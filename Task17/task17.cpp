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
void push(struct Node** head, int node_data) {
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
     cout << "null";
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
  push(&list2, 15.0f);
  push(&list2, 20.0f);
  push(&list2, 20.0f);
  push(&list2, 50.0f);
  push(&list2, 60.0f);
  push(&list2, 60.0f);

  struct Node* sorted = NULL;

  while (list1 != NULL && list2 != NULL) {
    if (list1->data > list2->data) {
      push(&sorted, list1->data);
      list1 = list1->next;
    } else {
      push(&sorted, list2->data);
      list2 = list2->next;
    }
  }
  while (list1 != NULL) {
    push(&sorted, list1->data);
    list1 = list1->next;
  }
  while (list2 != NULL) {
    push(&sorted, list2->data);
    list2 = list2->next;
  }
  
  displayList(sorted);

  return 0;
}
