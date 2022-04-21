#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    // Напишите здесь свой код ...
    if (size_ < 2) {
      return;
    }
    if (size_ == 2) {
      back_->next = front_;
      front_->next = nullptr;
      front_ = back_;
      back_ = front_->next;
      return;
    }
    Node* curr = front_;
    Node* currN = curr->next;
    Node* currNN = currN->next;

    for (int i = 0; i < size_ - 2; ++i) {
      currN->next = curr;
      curr = currN;
      currN = currNN;
      currNN = currNN->next;
    }
    currN->next = curr;
    back_ = front_;
    back_->next = nullptr;
    front_ = currN;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    // Напишите здесь свой код ...
    if (front_ != nullptr) {
      Node* curr_node = front_;
      Node* prev_node = nullptr;
      reverse_recursive_helper(curr_node, prev_node);
    }
  }

  // вспомогательный метод для реализации рекурсии
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    // Напишите здесь свой код ...
    if (curr != back_){
      reverse_recursive_helper(curr->next, curr);
    }else{
      front_ = curr;
    }
    if (prev == nullptr){
      back_ = curr;
    }
    curr->next = prev;
  }

}  // namespace assignment
