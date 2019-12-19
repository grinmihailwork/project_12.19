#include <iostream>
#include <fstream>
#include <tgmath.h>
#include <list>
using namespace std;

// A linked list node
struct Node
{
   double power;
   double number;
   struct Node *next;
};

//insert a new node in front of the list
void push(struct Node** head, double node_data1, double node_data2) {
   struct Node* newNode = new Node;
   newNode->power = node_data1;
   newNode->number = node_data2;
   newNode->next = (*head);
   (*head) = newNode;
}


void append(struct Node** head, double node_data1, double node_data2) {
  struct Node* newNode = new Node;
  struct Node *last = *head;
  newNode->power = node_data1;
  newNode->number = node_data2;
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
      cout << node->power << "#" << node->number << "--->";
      displayList(node->next);
   } else {
     cout << "null\n";
   }
}

bool equality(struct Node* a, struct Node* b) {
  while (a != NULL && b != NULL) {
        if ((a->power != b->power) || (a->number != b->number)) return false;
        a = a->next;
        b = b->next;
    }
    return (a == NULL && b == NULL);
}

double count(struct Node* list, double x) {
  double answer = 0;
  while (list != NULL) {
    answer += list->number * pow(x, list->power);
    list = list->next;
  }
  return answer;
}

Node* derivative(struct Node* list) {
  struct Node* newList = NULL;
  while (list != NULL) {
    append(&newList, list->power-1, list->number * list->power);
    list = list->next;
  }
  return newList;
}

void beautyList(struct Node* list, char lt) {
  while (list->next != NULL) {
    if (list->number < 0) cout << "(";
    if (list->power == 0.0) {
      cout << list->number;
    } else {
      cout << list->number << lt << "**" << list->power;
    }
    if (list->number < 0) cout << ")";
    std::cout << "+";
    list = list->next;
  }
  if (list->number < 0) cout << "(";
  if (list->power == 0.0) {
    cout << list->number;
  } else {
    cout << list->number << lt << "**" << list->power;
  }
  if (list->number < 0) cout << ")";
  std::cout << "\n";
}

int main() {

  struct Node* list1 = NULL;
  push(&list1, 0.0, 3.0);
  push(&list1, 4.0, 4.0);
  push(&list1, 5.0, 5.0);

  displayList(list1);

  struct Node* list2 = NULL;
  push(&list2, 0.0, 3.0);
  push(&list2, 4.0, 4.0);
  push(&list2, 5.0, 5.0);

  displayList(list2);

  //1
  if (equality(list1, list2)) {
    cout << "lists are equal" << '\n';
  } else {
    std::cout << "Lists are not equal" << '\n';
  }

  //2
  cout << "Y = " << count(list1, 1) << "\n";

  //3
  cout << "Derivative of list: ";
  beautyList(derivative(list1), 'x');

  //4
  cout << "Beauty view of polynomial: ";
  beautyList(list1, 'y');

  //5
  double l[100];
  int itt = 0;
  string s;
  ifstream myfile ("input.txt");
  if (myfile.is_open()) {
    getline(myfile, s);
    string tmp = "";
    for (char sss: s) {
      if ((sss == 'x' || sss == '^' || sss == '+' || sss == '-') && tmp != "") {
        l[itt] = stod(tmp);

        itt++;
        tmp = "";
      }
      if (!(sss == 'x' || sss == '^')) {
        tmp += sss;
      }

    }
    Node* newList = NULL;
    for (int i = itt; i >= 0; i-=2) {
      push(&newList, l[i], l[i-1]);
    }
    beautyList(newList, 'x');

    myfile.close();
  }



  return 0;
}
