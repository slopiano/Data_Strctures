#include <iostream>
using namespace std;

class Chunk {
 public:
  int info;
  Chunk *next;

  Chunk() {
    info = 0;
    next = NULL;
  }
};

class LinkedList {
 public:
  Chunk *head;
  int count;

  LinkedList() {
    head = NULL;
    count = 0;
  }
  void insertAtPos(int value, int pos) {
    if (pos > 0 && pos <= count + 1) {
      Chunk *temp;
      temp = new Chunk;
      temp->info = value;

      if (pos == 1) {
        temp->next = head;
        head = temp;
        count++;
        cout << "added ya Boi into position 1" << endl;
      } else {
        Chunk *helper = head;
        for (int i = 1; i <= pos - 2; i++) {
          helper = helper->next;
        }
        temp->next = helper->next;
        helper->next = temp;
        count++;
        cout << "just added " << value << " at position " << pos << endl;
      }
    } else {
      cout << "that aint no position son!!!!!! " << endl;
    }
  }
  void deleteAtPos(int pos) {
    if (pos > 0 && pos <= count + 1) {
      Chunk *temp;
      temp = new Chunk;

      if (pos == 1) {
        temp = head;
        head = head->next;
        delete temp;
        count--;
        cout << "deleted ya Boi at position 1" << endl;
      } else {
        Chunk *chase, *follow;
        chase = follow = head;
        for (int i = 1; i < pos; i++) {
          follow = chase;
          chase = chase->next;
        }
        follow->next = chase->next;
        delete chase;
        cout << "just deleted that position" << endl;
      }
    } else {
      cout << "that aint no position son!!!!!!" << endl;
    }
  }
  void reverseLinkedLists() {
    if (count <= 1) {
      cout << "it can't be reversed" << endl;
    } else {
      Chunk *temp = head;
      Chunk *chase = NULL, *follow = NULL;
      while (temp != NULL) {
        follow = temp->next;
        temp->next = chase;
        chase = temp;
        temp = follow;
      }
      head = chase;
      // cout << follow->info << " " << temp->info;
    }
  }

  void display() {
    Chunk *temp;
    temp = head;
    cout << "head-->";
    while (temp != NULL) {
      cout << temp->info << "--->";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
  void removeEveryOtherNode() {
    if (head == NULL) {
      return;
    }
    Chunk *follow = head;
    Chunk *chase = head->next;
    while (follow != NULL && chase != NULL) {
      follow->next = chase->next;
      free(chase);
      follow = follow->next;
      count--;
      if (follow != NULL) {
        chase = follow->next;
      }
    }
  }
};

int main() {
  LinkedList LL;
  int value, position, choice;
  LL.insertAtPos(5, 1);
  LL.insertAtPos(5, 1);
  LL.insertAtPos(4, 1);
  LL.insertAtPos(4, 1);
  LL.insertAtPos(3, 1);
  LL.insertAtPos(3, 1);
  LL.insertAtPos(1, 1);
  LL.insertAtPos(1, 1);

  while (1) {
    cout << "press 1 to add" << endl;
    cout << "press 2 to delete" << endl;
    cout << "press 3 to display" << endl;
    cout << "press 4 to reverse the list" << endl;
    cout << "press 5 to fix sephora" << endl;
    cout << "press anything else to exit" << endl;
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "add what?" << endl;
        cin >> value;
        cout << "At what position" << endl;
        cin >> position;
        LL.insertAtPos(value, position);
        break;

      case 2:
        cout << "what position do you want to delete" << endl;
        cin >> position;
        LL.deleteAtPos(position);
        break;

      case 3:
        LL.display();
        break;

      case 4:
        LL.reverseLinkedLists();
        break;

      case 5:
        LL.removeEveryOtherNode();
        break;

      default:
        cout << "Bye" << endl;
        exit(1);
    }
  }
}