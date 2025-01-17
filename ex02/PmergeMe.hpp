#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <cmath>

size_t jacobsthal(int i, bool reset = false);
int getIndex(int i, int recursion);
int &getIndexValue(std::list<int>& sequence, int index);

void erasePairs(std::vector<int> &sequence, int i, int recursion);
void swapPairs(std::vector<int> &sequence, int i1, int i2);
void insertPairs(std::vector<int> &sequence1, std::vector<int> &sequence2, int i1, int i2, int recursion);
int binaryInsertionIndex(const std::vector<int> &sequence, int value, int recursion);
void mergeInsertion(std::vector<int> &sequence, int recursion = 0);

void erasePairs(std::list<int> &sequence, int i, int recursion);
void swapPairs(std::list<int> &sequence, int i1, int i2);
void insertPairs(std::list<int> &sequence1, std::list<int> &sequence2, int i1, int i2, int recursion);
int binaryInsertionIndex(const std::list<int> &sequence, int value, int recursion);
void mergeInsertion(std::list<int> &sequence, int recursion = 0);

template <typename T>
size_t getSize(const T &sequence, int recursion)
{
	return (int)sequence.size() / pow(2, recursion);
}

#endif
