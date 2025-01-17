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
int getIndexValue(const std::list<int> &sequence, int index);

void mergeInsertion(std::vector<int> &sequence, int recursion = 0);
void mergeInsertion(std::list<int> &sequence, int recursion = 0);
int binaryInsertionIndex(const std::vector<int> &sequence, int value, int recursion);

int binaryInsertionIndex(const std::list<int> &sequence, int value, int recursion);

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

template <typename T>
void insertPairs(T &sequence1, T &sequence2, int i1, int i2, int recursion)
{
    for (size_t i = 0; i < pow(2, recursion); i++)
        sequence1.insert(sequence1.begin() + i1 + i, sequence2[i2 + i]);
}

template <typename T>
void erasePairs(T &sequence, int i, int recursion)
{
    for (size_t j = 0; j < pow(2, recursion); j++)
        sequence.erase(sequence.begin() + i);
}

#endif
