#pragma once

#include <iostream>
using namespace std;

struct ArrayNode {
  int data;
  int index;
  ArrayNode* next;
  ArrayNode* prev;
  
  ArrayNode(int data, int index)
  : data(data)
  , index(index)
  , next(nullptr)
  , prev(nullptr)
  {}
};

class ArrayLinkedList {
public:
  ArrayLinkedList(int array_length)
  : Head(nullptr)
  , Tail(nullptr)
  , array_length(array_length)
  {}

  void set_value(int value, int index) {
    if(index < 0 || index >= array_length) return;

    ArrayNode* node = new ArrayNode(value, index);
    if(!Head)
      Head = Tail = node;
    
    else {
      // check if index already exists
      for(ArrayNode* cur=Head; cur; cur = cur->next) {
        if(cur->index == index) {
          cur->data = value;
          return;
        }
      }
      
      // insert in sorted order
      ArrayNode* cur = Head;
      while(cur && cur->index < index) {
        cur = cur->next;
      }
      if(!cur) {
        // we reached the end, append at the end
        link(Tail, node);
        Tail = node;
      }
      else if(cur == Head) {
        // insert at the front
        link(node, Head);
        Head = node;
      }
      else {
        link(cur->prev, node);
        link(node, cur);
      }
    }
  }

  int get_value(int index) {
    ArrayNode* cur = Head;
    for(; cur; cur = cur->next) {
      if(cur->index == index) {
        return cur->data;
      }
    }
    return 0;
  }


  void add(ArrayLinkedList& array2) {
      ArrayNode* cur1 = Head;
      ArrayNode* cur2 = array2.Head;

      while (cur1 || cur2) {
          if (cur1 && (!cur2 || cur1->index < cur2->index)) {
              // cur1 has smaller index → keep as is
              cur1 = cur1->next;
          }
          else if (cur2 && (!cur1 || cur2->index < cur1->index)) {
              // cur2 has smaller index → insert new node into this list
              set_value(cur2->data, cur2->index);
              cur2 = cur2->next;
          }
          else {
              // indices are equal → add values
              cur1->data += cur2->data;
              cur1 = cur1->next;
              cur2 = cur2->next;
          }
      }
  }



  void print_array() {
    ArrayNode* cur = Head;
    for(int i = 0; i < array_length; i++) {
      if(cur && cur->index == i) {
        cout << cur->data << " ";
        cur=cur->next;
      }
      else
        cout << "0 ";
    }
    cout << endl;
  }

  void print_array_nonzero() {
    ArrayNode* cur = Head;
    for(int i = 0; i < array_length && cur; i++) {
      if(cur->index == i) {
        cout << cur->data << " ";
        cur=cur->next;
      }
    }
    cout << endl;
  }

private:
  ArrayNode* Head;
  ArrayNode* Tail;
  int array_length;

  void link(ArrayNode* first, ArrayNode* second) {
    if(first) first->next = second;
    if(second) second->prev = first;
  }

  void embed_after(ArrayNode* node, int value, int index) {
    ArrayNode* my_node = new ArrayNode(value, index);

    link(my_node, node->next);

    link(node, my_node);

    if(node == Tail)
      Tail = my_node;
  }
};
