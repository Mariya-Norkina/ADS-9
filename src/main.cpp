// Copyright 2022 NNTU-CS
#include <iostream>
#include <vector>
#include "tree.h"

int main() {
std::vector<char> in = { '1', '2', '3' };
PMTree tree(in);
std::cout << "getAllPerms\n";
auto all = getAllPerms(tree);
for (const auto& perm : all) {
for (char c : perm)
std::cout << c;
std::cout << '\n';
}
std::cout << "\ngetPerm1 and getPerm2\n"; auto p1 = getPerm1(tree, 1);
auto p2 = getPerm2(tree, 2);
std::cout << "Permutation #1: ";
for (char c : p1)
std::cout << c;
std::cout << '\n';
std::cout << "Permutation #2: ";
for (char c : p2)
std::cout << c;
std::cout << '\n';
return 0;
}
