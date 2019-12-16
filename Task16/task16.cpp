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

bool findElement(struct Node *node, double elem) {
  if (node != NULL) {
    if (node->data == elem) {
      return true;
    } else {
      return findElement(node->next, elem);
    }
  } return false;
}

void writeToFile(struct Node *node, ofstream &file) {
  if (node != NULL) {
     file << node->data << "-->";
     writeToFile(node->next, file);
  } else {
    file << "null\n";
  }
}

Node* find1(struct Node* list1, struct Node* list2) {
  Node* tmp = NULL;
  while (list1 != NULL) {
    if (!findElement(tmp, list1->data)) push(&tmp, list1->data);
    list1 = list1->next;
  }
  while (list2 != NULL) {
    if (!findElement(tmp, list2->data)) push(&tmp, list2->data);
    list2 = list2->next;
  }
  return tmp;
}

Node* find2(struct Node* list1, struct Node* list2) {
  Node* tmp = NULL;
  while (list1 != NULL) {
    if (!findElement(tmp, list1->data) && findElement(list2, list1->data)) push(&tmp, list1->data);
    list1 = list1->next;
  }
  return tmp;
}

Node* find3(struct Node* list1, struct Node* list2) {
  Node* tmp = NULL;
  while (list1 != NULL) {
    if (!findElement(tmp, list1->data) && !findElement(list2, list1->data)) push(&tmp, list1->data);
    list1 = list1->next;
  }
  return tmp;
}

Node* find4(struct Node* list1, struct Node* list2) {
  Node* tmp = NULL;
  while (list1 != NULL) {
    if (!findElement(tmp, list1->data) && !findElement(list2, list1->data)) push(&tmp, list1->data);
    list1 = list1->next;
  }
  while (list2 != NULL) {
    if (!findElement(tmp, list2->data) && !findElement(list1, list2->data)) push(&tmp, list2->data);
    list2 = list2->next;
  }
  return tmp;
}

int main() {

  struct Node* list1 = NULL;

  //FILLING LINKED LIST1 WITH DATA
  push(&list1, 5.0f);
  push(&list1, 10.0f);
  push(&list1, 15.0f);
  push(&list1, 20.0f);
  push(&list1, 25.0f);
  push(&list1, 30.0f);
  push(&list1, 35.0f);
  push(&list1, 40.0f);

  struct Node* list2 = NULL;

  //FILLING LINKED LIST2 WITH DATA
  push(&list2, 5.0f);
  push(&list2, 5.0f);
  push(&list2, 15.0f);
  push(&list2, 40.0f);
  push(&list2, 60.0f);
  push(&list2, 60.0f);
  push(&list2, 70.0f);
  push(&list2, 15.0f);
  push(&list2, 5.0f);
  push(&list2, 60.0f);

  ofstream output ("output.txt");
  //TASK 1
  displayList(find1(list1, list2));
  writeToFile(find1(list1, list2), output);

  //TASK 2
  displayList(find2(list1, list2));
  writeToFile(find2(list1, list2), output);

  //TASK 3
  displayList(find3(list1, list2));
  writeToFile(find3(list1, list2), output);

  //TASK 4
  displayList(find4(list1, list2));
  writeToFile(find4(list1, list2), output);

  output.close();

  return 0;
}
