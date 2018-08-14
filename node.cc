// Copyright 2018 <Author>

#include "node.h"

Node::Node(char data) : data_(data), prev_(nullptr), next_(nullptr) {
  return;
}

char Node::GetData() {
  return data_;
}

Node* Node::GetPreviousNode() {
  return prev_;
}

Node* Node::GetNextNode() {
  return next_;
}

Node* Node::InsertPreviousNode(char data) {
  Node* new_node = new Node(data);
  new_node->prev_ = prev_;
  new_node->next_ = this;
  if (prev_ != nullptr)
    prev_->next_ = new_node;
  prev_ = new_node;
  return new_node;
}

Node* Node::InsertNextNode(char data) {
  Node* new_node = new Node(data);
  new_node->next_ = next_;
  new_node->prev_ = this;
  if (next_ != nullptr)
    next_->prev_ = new_node;
  next_ = new_node;
  return new_node;
}

bool Node::ErasePreviousNode() {
  if (prev_ == nullptr)
    return false;

  Node* prev_node = prev_;
  prev_ = prev_node->prev_;
  if (prev_ != nullptr)
    prev_->next_ = this;
  delete prev_node;

  return true;
}

bool Node::EraseNextNode() {
  if (next_ == nullptr)
    return false;

  Node* next_node = next_;
  next_ = next_node->next_;
  if (next_ != nullptr)
    next_->prev_ = this;
  delete next_node;

  return true;
}
