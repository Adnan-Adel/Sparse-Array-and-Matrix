#pragma once

#include <iostream>
#include "./sparse_array.hpp"
using namespace std;


struct MatrixNode {
  ArrayLinkedList list;
  MatrixNode* next = nullptr;

  MatrixNode(int width) : list(width) {}
};


class MatrixLinkedList {
public:
  MatrixLinkedList(int matrix_width, int matrix_height)
  : Head(nullptr), Tail(nullptr),
    matrix_width(matrix_width), matrix_height(matrix_height) 
  {
    // create rows upfront
    for (int i = 0; i < matrix_height; i++) {
      add_row();
    }
  }

  void set_value(int x, int y, int value) {
    MatrixNode* cur = Head;
    while (cur && y) {
      cur = cur->next;
      y--;
    }
    if (!cur) {
      cout << "Invalid row index\n";
      return;
    }

    cur->list.set_value(value, x);
  }

  void print() {
    MatrixNode* curRow = Head;
    while (curRow) {
      curRow->list.print_array();
      cout << "\n";
      curRow = curRow->next;
    }
  }

  void add(const MatrixLinkedList& other) {
    MatrixNode* cur1 = Head;
    MatrixNode* cur2 = other.Head;

    while(cur1 && cur2) {
      cur1->list.add(cur2->list);
      cur1 = cur1->next;
      cur2 = cur2->next;
    }
  }

private:
  MatrixNode* Head;
  MatrixNode* Tail;
  int matrix_width;
  int matrix_height;

  void add_row() {
    MatrixNode* node = new MatrixNode(matrix_width);
    if (!Head) {
      Head = Tail = node;
    } else {
      Tail->next = node;
      Tail = node;
    }
  }
};
