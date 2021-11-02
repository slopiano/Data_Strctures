#include <iostream>
using namespace std;

class TreeNode {
 public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode() {
    data = 0;
    left = NULL;
    right = NULL;
  }
};

class BST {
 public:
  TreeNode *root;
  BST() { root = NULL; }
  void addNode(int value) {
    TreeNode *temp = new TreeNode;
    temp->data = value;
    if (root == NULL) {
      root = temp;
    } else {
      TreeNode *slow, *fast;
      slow = fast = root;

      while (fast != NULL) {
        if (fast->data == value) {
          cout << "This is a duplicate, can't do it" << endl;
          return;
        }
        if (value < fast->data) {
          slow = fast;
          fast = fast->left;
        } else {
          slow = fast;
          fast = fast->right;
        }
      }
      if (value < slow->data) {
        slow->left = temp;
      } else {
        slow->right = temp;
      }
    }
  }
  int minValueRight(TreeNode *start) {
    if (start == NULL)
      return -1;
    else {
      TreeNode *temp = start;
      while (temp->left != NULL) {
        temp = temp->left;
      }
      return temp->data;
    }
  }
  void search(int key, TreeNode *start) {
    if (start == NULL) {
      cout << "can't find the value" << endl;
      return;
    } else {
      if (key == start->data) {
        return;
      } else if (key < start->data) {
        search(key, start->left);
      } else {
        search(key, start->right);
      }
    }
  }
  void preorder(TreeNode *start) {
    if (start == NULL) {
      return;
    } else {
      cout << start->data << endl;
      preorder(start->left);
      preorder(start->right);
    }
  }
  void postorder(TreeNode *start) {
    if (start == NULL) {
      return;
    } else {
      postorder(start->left);
      postorder(start->right);
      cout << start->data << endl;
    }
  }
  void inorder(TreeNode *start) {
    if (start == NULL) {
      return;
    } else {
      inorder(start->left);
      cout << start->data << endl;
      inorder(start->right);
    }
  }
  void remove(int key, TreeNode *start) {
    if (start == NULL) {
      cout << "Tree is empty" << endl;
      return;
    }
    // find the value
    TreeNode *slow, *fast;
    slow = fast = root;

    while (fast != NULL && fast->data != key) {
      if (key < fast->data) {
        slow = fast;
        fast = fast->left;
      } else {
        slow = fast;
        fast = fast->right;
      }
    }
    // find out if it fell off or if you found the value
    if (fast == NULL) {
      cout << "There aint no value sonn, can't delete and will exit" << endl;
      return;
    }
    // if code goes here, fast has address of the node and slow has the parent
    if (fast->left == NULL && fast->right == NULL) {
      if (slow->left == fast) {
        slow->left = NULL;
        cout << "going to delete " << fast->data << endl;
        delete fast;
      } else {
        slow->right = NULL;
        cout << "about to delete " << fast->data << endl;
        delete fast;
      }
    } else if (fast->left != NULL && fast->right == NULL) {
      if (slow->left == fast) {
        slow->left = fast->left;
        delete fast;
      } else {
        slow->right = fast->left;
        delete fast;
      }
    } else if (fast->left == NULL && fast->right != NULL) {
      if (slow->right == fast) {
        slow->right = fast->right;
        delete fast;
      } else {
        slow->left = fast->right;
        delete fast;
      }
    } else {
      int minVal = minValueRight(fast->right);
      fast->data = minVal;
      remove(minVal, fast->right);
    }
  }

  int height(TreeNode *start) {
    if (start == NULL) {
      return 0;
    } else {
      int left = height(start->left);
      int right = height(start->right);
      if (right > left) {
        return (right + 1);
      } else
        return (left + 1);
    }
  }
  void DeleteAll(TreeNode *start) {
    if (start == NULL) {
      return;
    } else {
      DeleteAll(start->left);
      DeleteAll(start->right);
      delete start;
    }
  }
  void maxValue(TreeNode *start) {
    if (start == NULL) {
      return;
    } else {
      TreeNode *slow;
      slow = root;
      while (slow->right != NULL) {
        slow = slow->right;
      }
      cout << slow->data << endl;
    }
  }
  void minValue(TreeNode *start) {
    if (start == NULL) {
      return;
    } else {
      TreeNode *slow;
      slow = root;
      while (slow->left != NULL) {
        slow = slow->left;
      }
      cout << slow->data << endl;
    }
  }

  void Balanced(TreeNode *start) {
    int LeftNum, RightNum;
    if (start->right == NULL) {
      RightNum = 0;
    } else {
      RightNum = height(start->right);
    }
    if (start->left == NULL) {
      LeftNum = 0;
    } else {
      LeftNum = height(start->left);
    }
    // cout << LeftNum << endl;
    // cout << RightNum << endl;
    if (abs(LeftNum - RightNum) >= 2) {
      cout << "The Tree is not balanced" << endl;
    } else
      cout << "The Tree is balanced" << endl;
  }
};

int main() {
  BST myTree;
  int choice, value;
  myTree.addNode(30);
  myTree.addNode(15);
  myTree.addNode(60);
  myTree.addNode(7);
  myTree.addNode(22);
  myTree.addNode(45);
  myTree.addNode(75);
  myTree.addNode(17);
  myTree.addNode(27);
  // myTree.addNode(28);

  while (1) {
    cout << "Press 1 to add a value" << endl;
    cout << "Press 2 to check if the tree is balanced" << endl;
    cout << "Press 3 for post-order" << endl;
    cout << "Press 4 for in-order" << endl;
    cout << "Press 5 to search a value" << endl;
    cout << "Press 6 to delete a value" << endl;
    cout << "Press 7 to find height of tree" << endl;
    cout << "Press 8 to delete entire tree" << endl;
    cout << "Press 9 to find the max value" << endl;
    cout << "Press 0 to find the min value" << endl;
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "What value?" << endl;
        cin >> value;
        myTree.addNode(value);
        break;
      case 2:
        myTree.Balanced(myTree.root);
        break;
      case 3:
        myTree.postorder(myTree.root);
        break;
      case 4:
        myTree.inorder(myTree.root);
        break;

      case 5:
        cout << "What value?" << endl;
        cin >> value;
        myTree.search(value, myTree.root);
        break;

      case 6:
        cout << "What value" << endl;
        cin >> value;
        myTree.remove(value, myTree.root);
        break;

      case 7:
        cout << "Height is " << myTree.height(myTree.root) << endl;
        break;

      case 8:
        myTree.DeleteAll(myTree.root);
        break;

      case 9:
        myTree.maxValue(myTree.root);
        break;

      case 0:
        myTree.minValue(myTree.root);
        break;

      default:
        exit(1);
    }
  }
}