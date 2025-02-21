#include <iostream>
#include <fstream>
using namespace std;
struct Node
{
int val;
Node *next;
};

int main()
{
  Node *head = new Node;
  head->next = nullptr;
  ifstream fstream;
  int input;
  fstream.open("text.txt");
  if(!fstream.is_open())
  {
    cout << "Could not open file. Terminating" << endl;
    return -1;
  }
  cout << "Hello world" << endl;
  fstream >> input;
  while(input != -1)
    {
      Node *nodeVal = new Node;
      nodeVal->val = input;
      nodeVal->next = nullptr;
      if(head == nullptr)
      {
        head = nodeVal;
      }
      else
      {
        Node *nodeTran = head;
        while(nodeTran->next != nullptr)
          {
            nodeTran = nodeTran->next;
          }
        nodeVal->val = input;
        nodeTran->next = nodeVal;
      }
      fstream >> input;
    }
  Node *deleteNode = head->next;
  head->next = deleteNode->next;
  Node *newNode = head->next;
  delete deleteNode;
  while(newNode != nullptr)
    {
      cout << newNode->val << endl;
      newNode = newNode->next;
    }
  fstream.close();
  return 0;
}