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

void mergeInsertion(std::vector<int> &sequence, int recursion = 0);
void mergeInsertion(std::list<int> &sequence, int recursion = 0);
void insertPairs(std::vector<int> &sequence1, std::vector<int> &sequence2, int i1, int i2, int recursion);
void erasePairs(std::vector<int> &sequence, int i, int recursion);
int binaryInsertionIndex(const std::vector<int> &sequence, int value, int recursion);

template <typename T>
size_t getSize(const T &sequence, int recursion)
{
	return (int)sequence.size() / pow(2, recursion);
}

template <typename T>
void swapPairs(T &sequence, int i1, int i2)
{
	for (int i = 0; i < i2 - i1; i++)
		std::swap(sequence[i1 + i], sequence[i2 + i]);
}

#endif
