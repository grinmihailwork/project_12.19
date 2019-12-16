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

bool findElement(struct Node *node, double elem) {
  if (node != NULL) {
    if (node->data == elem) {
      return true;
    } else {
      return findElement(node->next, elem);
    }
  } return false;
}

int countElement(struct Node *node, double elem) {
   if (node == NULL) return 0;
   if (node->data == elem) {
      return 1 + countElement(node->next, elem);
   } else {
      return countElement(node->next, elem);
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

void changeElement(struct Node *node, double elem1, double elem2) {
  if (node != NULL) {
     if (node->data == elem1) {
       node->data = elem2;
     }
     changeElement(node->next, elem1, elem2);
  }
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
  //CREATING DATA STRUCTURE
  struct Node* head = NULL;

  //FILLING LINKED LIST WITH DATA
  push(&head, 20.0f);
  push(&head, 10.0f);
  push(&head, 15.0f);
  push(&head, 60.0f);
  push(&head, 30.0f);
  push(&head, 15.0f);
  push(&head, 50.0f);
  push(&head, 10.0f);

  cout << "Your list is:\n";
  displayList(head);
  std::cout << "\n";

  //EX 1
  if (findElement(head, 1.0f)) {
    cout << "Number is in linked LIST" << '\n';
  } else {
    cout << "Number is not in linked LIST" << '\n';
  }

  //EX 2
  cout << "The number occurs " << countElement(head, 15.0f) << " times" << "\n";

  //EX 3
  cout << "Biggest number is " << findMaximum(head) << "\n";

  //EX 4
  changeElement(head, 15.0f, 9.0f);
  std::cout << "Changing number to number" << '\n';
  displayList(head);

  //EX 5
  std::cout << "\nWriting to file\n";
  ofstream input ("input.txt");
  writeToFile(head, input);
  input.close();

  return 0;
}
