// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>
class PMTree {
 public:
struct Noda {
char value;
std::vector<Noda*> child;
explicit Noda(char val) : value(val) {}
};
explicit PMTree(const std::vector<char>& elements);
~PMTree();
int getTotalPerms() const { return totalPerms; }
Noda* getRoot() const { return root; }
PMTree& operator=(const PMTree&) = delete;
PMTree(const PMTree&) = delete;

 private:
Noda* root;
int totalPerms;
void buildTree(Noda* parent, const std::vector<char>& remain);
void deleteTree(Noda* node);
};

std::vector<std::vector<char>> getAllPerms(const PMTree& tree);
std::vector<char> getPerm1(const PMTree& tree, int num);
std::vector<char> getPerm2(const PMTree& tree, int num);
std::vector<char> generateAlphabet(int n);

#endif  // INCLUDE_TREE_H_
