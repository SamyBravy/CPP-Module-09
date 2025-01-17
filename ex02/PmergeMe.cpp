/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samuele <samuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:41:05 by samuele           #+#    #+#             */
/*   Updated: 2025/01/17 22:08:02 by samuele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

size_t jacobsthal(int i, bool reset)
{
    static std::vector<int> sequence;

    if (reset)
        sequence.clear();

    if (sequence.empty())
    {
        sequence.push_back(0);
        sequence.push_back(1);
    }
    if (i < 0)
        return -1;
    if (i < (int)sequence.size())
        return sequence[i];
        
    sequence.push_back(2 * jacobsthal(i - 2) + jacobsthal(i - 1));
    return sequence[i];
}

int getIndex(int i, int recursion)
{
	return i * pow(2, recursion);
}

void swapPairs(std::vector<int> &sequence, int i1, int i2)
{
	for (int i = 0; i < i2 - i1; i++)
		std::swap(sequence[i1 + i], sequence[i2 + i]);
}

void insertPairs(std::vector<int> &sequence1, std::vector<int> &sequence2, int i1, int i2, int recursion)
{
    for (size_t i = 0; i < pow(2, recursion); i++)
        sequence1.insert(sequence1.begin() + i1 + i, sequence2[i2 + i]);
}

int binaryInsertionIndex(const std::vector<int> &sequence, int value, int recursion)
{
    int l = 0;
    int r = getSize(sequence, recursion);

    while (l < r)
	{
        int mid = (l + r) / 2;
		
        if (sequence[getIndex(mid, recursion)] < value)
            l = mid + 1;
        else
            r = mid;
    }
    return getIndex(l, recursion);
}

void erasePairs(std::vector<int> &sequence, int i, int recursion)
{
    for (size_t j = 0; j < pow(2, recursion); j++)
        sequence.erase(sequence.begin() + i);
}

void mergeInsertion(std::vector<int> &sequence, int recursion)
{
	if (sequence.size() < 2)
		return;
	if (getSize(sequence, recursion) == 2)
	{
		if (sequence[0] > sequence[getIndex(1, recursion)])
			swapPairs(sequence, 0, getIndex(1, recursion));
		return;
	}

    std::vector<int> struggler;
    if (getSize(sequence, recursion) % 2)
    {
        insertPairs(struggler, sequence, 0, getIndex(getSize(sequence, recursion) - 1, recursion), recursion);
        erasePairs(sequence, getIndex(getSize(sequence, recursion) - 1, recursion), recursion);
    }
	
	for (size_t i = 0; i < getSize(sequence, recursion); i += 2)
	{
		if (sequence[getIndex(i, recursion)] < sequence[getIndex(i + 1, recursion)])
			swapPairs(sequence, getIndex(i, recursion), getIndex(i + 1, recursion));
	}
	
	if (getSize(sequence, recursion) == 2)
	{
		if (sequence[0] > sequence[getIndex(1, recursion)])
			swapPairs(sequence, 0, getIndex(1, recursion));
        insertPairs(sequence, struggler, binaryInsertionIndex(sequence, struggler[0], recursion), 0, recursion);
		return ;
	}
	mergeInsertion(sequence, recursion + 1);

	std::vector<int> lowers;
	for (size_t i = 0; i < getSize(sequence, recursion); i += 2)
        insertPairs(lowers, sequence, lowers.size(), getIndex(i + 1, recursion), recursion);
    for (size_t i = 0; i < getSize(sequence, recursion); i++)
		erasePairs(sequence, getIndex(i + 1, recursion), recursion);
	insertPairs(sequence, lowers, 0, 0, recursion);
        
    size_t jacob = 0;
    for (size_t i = 1; i < getSize(lowers, recursion);)
    {
        for (size_t j = jacobsthal(jacob + 1); j > jacobsthal(jacob); j--)
        {
            if (j >= getSize(lowers, recursion))
                continue;
			insertPairs(sequence, lowers, binaryInsertionIndex(sequence, lowers[getIndex(j, recursion)], recursion), getIndex(j, recursion), recursion);
            i++;
        }
        jacob++;
    }

    if (!struggler.empty())
        insertPairs(sequence, struggler, binaryInsertionIndex(sequence, struggler[0], recursion), 0, recursion);
}

int &getIndexValue(std::list<int>& sequence, int index)
{
    std::list<int>::iterator it = sequence.begin();
    std::advance(it, index);
    return *it;
}

void swapPairs(std::list<int> &sequence, int i1, int i2)
{
	for (int i = 0; i < i2 - i1; i++)
		std::swap(getIndexValue(sequence, i1 + i), getIndexValue(sequence, i2 + i));
}

void insertPairs(std::list<int> &sequence1, std::list<int> &sequence2, int i1, int i2, int recursion)
{
    for (size_t i = 0; i < pow(2, recursion); i++)
    {
        std::list<int>::iterator it = sequence1.begin();
        std::advance(it, i1 + i);
        sequence1.insert(it, getIndexValue(sequence2, i2 + i));
    }
}

void erasePairs(std::list<int> &sequence, int i, int recursion)
{
    for (size_t j = 0; j < pow(2, recursion); j++)
    {
        std::list<int>::iterator it = sequence.begin();
        std::advance(it, i);
        sequence.erase(it);
    }
}

int binaryInsertionIndex(std::list<int> &sequence, int value, int recursion)
{
    int l = 0;
    int r = getSize(sequence, recursion);

    while (l < r)
	{
        int mid = (l + r) / 2;
		
        if (getIndexValue(sequence, getIndex(mid, recursion)) < value)
            l = mid + 1;
        else
            r = mid;
    }
    return getIndex(l, recursion);
}

void mergeInsertion(std::list<int> &sequence, int recursion)
{
	if (sequence.size() < 2)
		return;
	if (getSize(sequence, recursion) == 2)
	{
		if (getIndexValue(sequence, 0) > getIndexValue(sequence, getIndex(1, recursion)))
			swapPairs(sequence, 0, getIndex(1, recursion));
		return;
	}

    std::list<int> struggler;
    if (getSize(sequence, recursion) % 2)
    {
        insertPairs(struggler, sequence, 0, getIndex(getSize(sequence, recursion) - 1, recursion), recursion);
        erasePairs(sequence, getIndex(getSize(sequence, recursion) - 1, recursion), recursion);
    }
	
	for (size_t i = 0; i < getSize(sequence, recursion); i += 2)
	{
		if (getIndexValue(sequence, getIndex(i, recursion)) < getIndexValue(sequence, getIndex(i + 1, recursion)))
			swapPairs(sequence, getIndex(i, recursion), getIndex(i + 1, recursion));
	}
	
	if (getSize(sequence, recursion) == 2)
	{
		if (getIndexValue(sequence, 0) > getIndexValue(sequence, getIndex(1, recursion)))
			swapPairs(sequence, 0, getIndex(1, recursion));
        insertPairs(sequence, struggler, binaryInsertionIndex(sequence, getIndexValue(struggler, 0), recursion), 0, recursion);
		return ;
	}
	mergeInsertion(sequence, recursion + 1);

	std::list<int> lowers;
	for (size_t i = 0; i < getSize(sequence, recursion); i += 2)
        insertPairs(lowers, sequence, lowers.size(), getIndex(i + 1, recursion), recursion);
    for (size_t i = 0; i < getSize(sequence, recursion); i++)
		erasePairs(sequence, getIndex(i + 1, recursion), recursion);
	insertPairs(sequence, lowers, 0, 0, recursion);
        
    size_t jacob = 0;
    for (size_t i = 1; i < getSize(lowers, recursion);)
    {
        for (size_t j = jacobsthal(jacob + 1); j > jacobsthal(jacob); j--)
        {
            if (j >= getSize(lowers, recursion))
                continue;
			insertPairs(sequence, lowers, binaryInsertionIndex(sequence, getIndexValue(lowers, getIndex(j, recursion)), recursion), getIndex(j, recursion), recursion);
            i++;
        }
        jacob++;
    }

    if (!struggler.empty())
        insertPairs(sequence, struggler, binaryInsertionIndex(sequence, getIndexValue(struggler, 0), recursion), 0, recursion);
}
