//===----------------------------------------------------------------------===//
//
//                         BusTub
//
// trie.cpp
//
// Identification: src/primer/trie.cpp
//
// Copyright (c) 2015-2025, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include "primer/trie.h"
#include <string_view>
#include "common/exception.h"
#include "fmt/chrono.h"

namespace bustub {

/**
 * @brief Get the value associated with the given key.
 * 1. If the key is not in the trie, return nullptr.
 * 2. If the key is in the trie but the type is mismatched, return nullptr.
 * 3. Otherwise, return the value.
 */
template <class T>
auto Trie::Get(std::string_view key) const -> const T * {
  // You should walk through the trie to find the node corresponding to the key. If the node doesn't exist, return
  // nullptr. After you find the node, you should use `dynamic_cast` to cast it to `const TrieNodeWithValue<T> *`. If
  // dynamic_cast returns `nullptr`, it means the type of the value is mismatched, and you should return nullptr.
  // Otherwise, return the value.

  std::shared_ptr<const TrieNode> current = root_;
  for (char c : key) {
    if (current == nullptr) {
      return nullptr;
    }

    auto it = current->children_.find(c);
    if (it == current->children_.end()) {
      return nullptr;
    } else {
      current = it->second;
    }
  }

  if (current == nullptr) {
    return nullptr;
  }

  std::shared_ptr<const TrieNodeWithValue<T>> leaf_node =
      std::dynamic_pointer_cast<const TrieNodeWithValue<T>>(current);
  if (leaf_node == nullptr) {
    return nullptr;
  }
  return leaf_node->value_.get();
}

/**
 * @brief Put a new key-value pair into the trie. If the key already exists, overwrite the value.
 * @return the new trie.
 */
template <class T>
auto Trie::Put(std::string_view key, T value) const -> Trie {
  // Note that `T` might be a non-copyable type. Always use `std::move` when creating `shared_ptr` on that value.
  throw NotImplementedException("Trie::Put is not implemented.");

  // You should walk through the trie and create new nodes if necessary. If the node corresponding to the key already
  // exists, you should create a new `TrieNodeWithValue`.

  // auto value_ptr = std::make_shared<T>(std::move(value));
  //
  // if (key.empty()) {
  //   std::map<char, std::shared_ptr<const TrieNode>> new_children;
  //
  //   if (root_ != nullptr) {
  //     new_children = root_->children_;
  //   }
  //
  //   auto new_root = std::make_shared<TrieNodeWithValue<T>>(std::move(new_children), std::move(value_ptr));
  //
  //   return Trie(std::move(new_root));
  // }
  //
  // std::function<std::shared_ptr<const TrieNode>(std::shared_ptr<const TrieNode>, size_t)> put_helper;
  //
  //
  //
  // put_helper = [&](std::shared_ptr<const TrieNode> node, size_t idx) -> std::shared_ptr<const TrieNode> {
  //   // usage: put_helper(root, len(char))
  //   // `[&]` allow the function to access outer domain variable
  //   char c = key[idx];
  //
  //   if (idx == key.size() - 1) {
  //     // if (node == nullptr) {
  //     // return std::make_shared<TrieNodeWithValue<T>>(std::move(value_ptr));
  //     // }
  //     std::map<char, std::shared_ptr<const TrieNode>> new_children;
  //
  //     if (node != nullptr) {
  //       new_children = node->children_;
  //     }
  //     new_children[c] = std::make_shared<TrieNodeWithValue<T>>(std::move(value_ptr));
  //     if (node == nullptr) {
  //       return std::make_shared<TrieNode>(std::move(new_children));
  //     } else {
  //       auto new_node = node->Clone();
  //       new_node->children_ = std::move(new_children);
  //       return new_node;
  //     }
  //   }
  //
  //   std::shared_ptr<const TrieNode> child_node;
  //   if (node == nullptr) {
  //     child_node = nullptr;
  //   } else {
  //     auto it = node->children_.find(c);
  //     child_node = it->second;
  //   }
  //
  //   auto new_child = put_helper(child_node, idx + 1);
  //
  // }
  //




}

/**
 * @brief Remove the key from the trie.
 * @return If the key does not exist, return the original trie. Otherwise, returns the new trie.
 */
auto Trie::Remove(std::string_view key) const -> Trie {
  throw NotImplementedException("Trie::Remove is not implemented.");

  // You should walk through the trie and remove nodes if necessary. If the node doesn't contain a value anymore,
  // you should convert it to `TrieNode`. If a node doesn't have children anymore, you should remove it.
}

// Below are explicit instantiation of template functions.
//
// Generally people would write the implementation of template classes and functions in the header file. However, we
// separate the implementation into a .cpp file to make things clearer. In order to make the compiler know the
// implementation of the template functions, we need to explicitly instantiate them here, so that they can be picked up
// by the linker.

template auto Trie::Put(std::string_view key, uint32_t value) const -> Trie;
template auto Trie::Get(std::string_view key) const -> const uint32_t *;

template auto Trie::Put(std::string_view key, uint64_t value) const -> Trie;
template auto Trie::Get(std::string_view key) const -> const uint64_t *;

template auto Trie::Put(std::string_view key, std::string value) const -> Trie;
template auto Trie::Get(std::string_view key) const -> const std::string *;

// If your solution cannot compile for non-copy tests, you can remove the below lines to get partial score.

using Integer = std::unique_ptr<uint32_t>;

template auto Trie::Put(std::string_view key, Integer value) const -> Trie;
template auto Trie::Get(std::string_view key) const -> const Integer *;

template auto Trie::Put(std::string_view key, MoveBlocked value) const -> Trie;
template auto Trie::Get(std::string_view key) const -> const MoveBlocked *;

}  // namespace bustub
