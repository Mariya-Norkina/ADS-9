// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include <algorithm>
#include  "tree.h"

PMTree::PMTree(const std::vector<char>& elements) {
if (elements.empty()) {
root = nullptr;
totalPerms = 0;
return;
}
totalPerms = 1;
for (size_t i = 1; i <= elements.size(); ++i) {
totalPerms *= i;
}
root = new Noda('\0');
buildTree(root, elements);
}

PMTree::~PMTree() {
deleteTree(root);
}

void PMTree::deleteTree(Noda* node) {
if (node) {
for (Noda* child : node->child) {
deleteTree(child);
}
delete node;
}
}

void PMTree::buildTree(Noda* parent, const std::vector<char>& remain) {
if (remain.empty()) {
return;
}
for (size_t i = 0; i < remain.size(); ++i) {
Noda* child = new Noda(remain[i]);
parent->child.push_back(child);
std::vector<char> new_remaining;
for (size_t j = 0; j < remain.size(); ++j) {
if (j != i) {
new_remaining.push_back(remain[j]);
}
}
buildTree(child, new_remaining);
}
}

void collectPermutations(const PMTree::Noda* node,
std::vector<char>& current,
std::vector<std::vector<char>>& result) {
if (!node) {
return;
}
if (node->value != '\0') {
current.push_back(node->value);
}
if (node->child.empty()) {
if (!current.empty()) {
result.push_back(current);
}
} else {
for (const auto& child : node->child) {
collectPermutations(child, current, result);
}
}
if (node->value != '\0') {
current.pop_back();
}
}

std::vector<std::vector<char>> getAllPerms(const PMTree& tree) {
std::vector<std::vector<char>> result;
if (!tree.getRoot()) {
return result;
}
std::vector<char> current;
collectPermutations(tree.getRoot(), current, result);
return result;
}

std::vector<char> getPerm1(const PMTree& tree, int num) {
if (num < 1 || num > tree.getTotalPerms()) {
return {};
}
auto all_perms = getAllPerms(tree);
return all_perms[num - 1];
}

std::vector<char> getPerm2Helper(const PMTree::Noda* node,  int& remaining) {
if (!node) {
return {};
}
if (node->child.empty()) {
if (--remaining == 0) {
return { node->value };
}
return {};
}
for (const auto& child : node->child) {
auto result = getPerm2Helper(child, remaining);
if (!result.empty()) {
if (node->value != '\0') {
result.insert(result.begin(), node->value);
}
return result;
}
}
return {};
}

std::vector<char> getPerm2(const PMTree& tree, int num) {
if (num < 1 || num > tree.getTotalPerms()) {
return {};
}
int remaining = num;
return getPerm2Helper(tree.getRoot(), remaining);
}

std::vector<char> generateAlphabet(int n) {
std::vector<char> alphabet;
for (int i = 0; i < n; ++i) {
alphabet.push_back('a' + i);
}
return alphabet;
}

