// Copyright 2024 CSCE240-003
// Define a Linked List template
#include<iostream>
using std::cout;
using std::endl;

#ifndef _LLIST_H_
#define _LLIST_H_

template<class T>  // this is a template structure type, T applies to the
                   // entire definition
struct MyNode {
  MyNode() { next = nullptr; }
  explicit MyNode(T v, MyNode<T> * n = nullptr) {
    val = v;
    next = n;
  }
  T val;
  MyNode<T> * next;
};

template<class T>
class LList {
 public:
  LList() { head = tail = nullptr; }

  ~LList() { ClearList(); }

  void ClearList() {
    while ( RemoveFromHead() ) { }
  }

  void AddToHead(T v) {
    if ( head == nullptr )  // if the list is empty, the new element is both
                            // the first and last element
      head = tail = new MyNode<T>(v, head);
    else
      head = new MyNode<T>(v, head);
  }

  void AddToTail(T v) {
    if ( head == nullptr ) {
      head = tail = new MyNode<T>(v, nullptr);
    } else {
      tail->next = new MyNode<T>(v, nullptr);
      tail = tail->next;
    }
  }

  bool RemoveFromHead() {
    // make the head point to the second node and release the memory for
    // the first note
    if ( head == nullptr )  // if the list is empty, there's nothing to remove
      return false;
    MyNode<T> * previous_head = head;
    if ( head == tail )  // if there's one element in the list, then removing
      tail = nullptr;    // it should change both the head and the tail to null
    head = head->next;
    delete previous_head;
    return true;
  }

  bool RemoveFromTail() {
    if ( head == nullptr )  // empty list nothing to do
      return false;
    if ( head == tail ) {  // single element list, will now be empty
      delete tail;
      head = tail = nullptr;
      return true;
    }
    MyNode<T> * temp = head;
    while ( temp->next != tail )
      temp = temp->next;
    delete tail;  // free up the previous tail
    tail = temp;  // tail points to the node before it
    tail->next = nullptr;  // make the tails pointer point into the void
    return true;
  }

  void Print() const {
    MyNode<T> * temp = head;
    while ( temp != nullptr ) {
      cout << temp->val << " ";
      temp = temp->next;
    }
    cout << endl;
  }

 private:
  MyNode<T> * head;  // points to the first node in the linked list
  MyNode<T> * tail;  // points to the last node in the linked list
};


#endif
