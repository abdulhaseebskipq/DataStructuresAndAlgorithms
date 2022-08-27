#include <iostream>
#include <string>
#include<fstream>
using namespace std;
class Node
{
private:
  float data;
  Node *next;
  Node *prev;
public:
    Node ()
  {
    next = NULL;
    prev = NULL;
  }
  Node (float n)
  {
    data = n;
  }
  void setData (float n)
  {
    data = n;
  }
  float getData ()
  {
    return data;
  }
  void setNext (Node * ne)
  {
    next = ne;
  }
  void setPrev (Node * pe)
  {
    prev = pe;
  }
  Node *getNext ()
  {
    return next;
  }
  Node *getPrev ()
  {
    return prev;
  }
  void displayNode ()
  {
    cout << data << endl;
  }

};

class DLinkedList
{
private:
  Node * head;
  Node *last;
public:
    DLinkedList ()
  {
    head = NULL;
    last = NULL;
  }
  void addAtStart (float x)
  {
    Node *n = new Node (x);
    if (head == NULL)
      {
	head = n;
	last = n;
      }
    else
      {
	head->setPrev (n);
	n->setNext (head);
	head = n;
      }

  }
  void displayList ()
  {
    Node *temp = head;
    while (temp != NULL)
      {
	temp->displayNode ();
	temp = temp->getNext ();
      }
  }

  int number_of_nodes ()
  {
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
      {
	count++;
	temp = temp->getNext ();
      }
    return count;
  }

  int search_list (float k)
  {
    Node *temp;
    temp = head;
    int i = 0;
    while (temp != NULL)
      {
	if (temp->getData () == k)
	  return i;
	i++;
	temp = temp->getNext ();
      }
    return -1;

  }

  void addAtEnd (float a)
  {
    Node *c = new Node (a);
    if (head == NULL)
      {
	head = c;
	last = c;
	return;
      }
    last->setNext (c);
    c->setPrev (last);
    last = c;
  }
  void add_at_index (float n, int i)
  {
    Node *c = new Node (n);
    Node *temp = head;
    if (i <= 0)
      {
	addAtStart (n);
      }
    else
      {
	if (i > number_of_nodes ())
	  {
	    addAtEnd (n);
	  }
	else
	  {
	    for (int j = 0; j != (i - 1); j++)
	      {
		temp = temp->getNext ();
	      }
	    c->setNext (temp->getNext ());
	    c->setPrev (temp);
	    temp->setNext (c);
	  }
      }

  }

  void remove_first ()
  {
    head->getNext ()->setPrev (NULL);
    head = head->getNext ();
  }

  void remove_end ()
  {
    last->getPrev ()->setNext (NULL);
  }

  void remove_float (float a)
  {
    Node *temp = head;
    while (temp != NULL)
      {

	if (head->getData () == a)
	  {
	    head = head->getNext ();
	    return;
	  }
	if (temp->getData () == a)
	  {
	    temp->getPrev ()->setNext (temp->getNext ());
	    return;
	  }
	temp = temp->getNext ();
      }
    cout << "data not present" << endl;
  }

  void removeAt (int j)
  {
    Node *temp = head;
    if (j < 0 || j == number_of_nodes ())
      {
	cout << "index out of range" << endl;
	return;
      }
    else
      {
	if (j == 0)
	  {
	    remove_first ();
	  }
	else
	  {
	    if (j == (number_of_nodes () - 1))
	      {
		remove_end ();
	      }
	    else
	      {
		for (int i = 0; i < number_of_nodes (); i++)
		  {

		    if (i == j)
		      {
			remove_float (temp->getData ());
		      }
		    temp = temp->getNext ();
		  }
	      }
	  }

      }
  }
  void reverseSwap ()
  {
    Node *temp = head;
    Node *c;
    while (temp != NULL)
      {
	c = temp->getNext ();
	temp->setNext (temp->getPrev ());
	temp->setPrev (c);
	temp = c;
      }
    if (temp == NULL)
      {
	c = head;
	head = last;
	last = c;
      }
  }
  void displayReverse ()
  {
    Node *temp = last;
    while (temp != NULL)
      {
	temp->displayNode ();
	temp = temp->getPrev ();
      }

  }
  void automater ()
  {
    ifstream file;
    file.open ("text.txt");
    string m;
    int i;
    float a;
    while (!file.eof ())
      {
	file >> m;
	if (m == "AAS")
	  {
	    cout << " Add at start" << endl;
	    file >> a;
	    addAtStart (a);
	  }
	if (m == "AAE")
	  {
	    cout << " Add at end" << endl;
	    file >> a;
	    addAtEnd (a);
	  }
	if (m == "ADD")
	  {
	    cout << " Add at index" << endl;
	    file >> a;
	    file >> i;
	    add_at_index (a, i);
	  }
	if (m == "REM")
	  {
	    cout << " remove" << endl;
	    file >> a;
	    remove_float (a);
	  }
	if (m == "RAI")
	  {
	    cout << " remove ay index" << endl;
	    file >> i;
	  }
	if (m == "RAS")
	  {
	    cout << " remove at start" << endl;
	    remove_first ();
	  }
	if (m == "RAE")
	  {
	    cout << "remove at end" << endl;
	    remove_end ();
	  }
	if (m == "DIS")
	  {
	    cout << " Display " << endl;
	    displayList ();
	  }
	if (m == "DIR")
	  {
	    cout << " displayReverse" << endl;
	    displayReverse ();
	  }
	if (m == "R")
	  {
	    reverseSwap ();
	  }
      }
    file.close ();

  }

};

int
main ()
{
  DLinkedList a;
  a.addAtStart (20);
  a.addAtStart (30);
  a.addAtStart (40);
  a.addAtStart (50);
  a.automater ();
}
