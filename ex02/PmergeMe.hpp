#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <cmath>

int jacobsthal(int i, bool reset = false);
int getIndex(int i, int recursion);
size_t getSize(const std::vector<int> &sequence, int recursion);
void swapPairs(std::vector<int> &sequence, int i1, int i2);
void mergeInsertion(std::vector<int> &sequence, int recursion = 0);
void mergeInsertion(std::list<int> &sequence, int recursion = 0);

#endif
