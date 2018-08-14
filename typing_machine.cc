// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() : head_(new Node(0)) {
  cursor_ = head_;
}

TypingMachine::~TypingMachine()
{
  while (head_->EraseNextNode());
  delete head_;
}

void TypingMachine::HomeKey() {
  cursor_ = head_;
}

void TypingMachine::EndKey() {
  Node* cur = cursor_;
  Node* next = cur->GetNextNode();

  if (next == nullptr)
    return;

  while (next) {
    cur = next;
    next = cur->GetNextNode();
  }

  cursor_ = cur;
}

void TypingMachine::LeftKey() {
  Node* prev = cursor_->GetPreviousNode();

  if (prev == nullptr)
    return;
  cursor_ = prev;
}

void TypingMachine::RightKey() {
  Node* next = cursor_->GetNextNode();

  if (next == nullptr)
    return;
  cursor_ = next;
}

bool TypingMachine::TypeKey(char key) {
  if (len_ >= 100 || key < 32 || key > 126)
    return false;
  Node *new_node = cursor_->InsertNextNode(key);
  if (new_node == nullptr)
    return false;
  cursor_ = new_node;
  len_++;
  return true;
}

bool TypingMachine::EraseKey() {
  if (cursor_ == head_)
    return false;

  Node *prev = cursor_->GetPreviousNode();
  if (prev == nullptr)
    return false;

  cursor_ = prev;
  bool ret = cursor_->EraseNextNode();
  if (ret == true)
    len_--;
  return ret;
}

std::string TypingMachine::Print(char separator) {
  std::string msg;

  if (separator != 0)
    msg.insert(0, 1, separator);

  Node* trail = cursor_;
  while (trail != head_) {
    msg.insert(0, 1, trail->GetData());
    trail = trail->GetPreviousNode();
  }

  trail = cursor_->GetNextNode();
  while (trail != nullptr) {
    msg.push_back(trail->GetData());
    trail = trail->GetNextNode();
  }
  return msg;
}
