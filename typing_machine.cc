// Copyright 2018 <Author>

#include "typing_machine.h"

TypingMachine::TypingMachine() : cursor_(new Node(0)) {
}

TypingMachine::~TypingMachine()
{
  while (cursor_->ErasePreviousNode());
  while (cursor_->EraseNextNode());
  delete cursor_;
}

void TypingMachine::HomeKey() {
  Node* cur = cursor_;
  Node* prev = cur->GetPreviousNode();
  
  if (prev == nullptr)
    return;

  prev->EraseNextNode();
  while (prev != nullptr) {
    cur = prev;
    prev = cur->GetPreviousNode();
  }

  cursor_ = cur->InsertPreviousNode(0);
}

void TypingMachine::EndKey() {
  Node* cur = cursor_;
  Node* next = cur->GetNextNode();

  if (next == nullptr)
    return;

  next->ErasePreviousNode();
  while (next) {
    cur = next;
    next = cur->GetNextNode();
  }

  cursor_ = cur->InsertNextNode(0);
}

void TypingMachine::LeftKey() {
  Node* prev = cursor_->GetPreviousNode();

  if (prev == nullptr)
    return;
  prev->EraseNextNode();
  cursor_ = prev->InsertPreviousNode(0);
}

void TypingMachine::RightKey() {
  Node* next = cursor_->GetNextNode();

  if (next == nullptr)
    return;
  next->ErasePreviousNode();
  cursor_ = next->InsertNextNode(0);
}

bool TypingMachine::TypeKey(char key) {
  if (len_ >= 100 || key < 32 || key > 126)
    return false;
  cursor_->InsertPreviousNode(key);
  len_++;
  return true;
}

bool TypingMachine::EraseKey() {
  bool ret = cursor_->ErasePreviousNode();
  if (ret == true)
    len_--;
  return ret;
}

std::string TypingMachine::Print(char separator) {
  std::string msg;

  if (separator != 0)
    msg.insert(0, 1, separator);

  Node* trail = cursor_->GetPreviousNode();
  while (trail != nullptr) {
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