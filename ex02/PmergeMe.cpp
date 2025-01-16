/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:50:51 by samuele           #+#    #+#             */
/*   Updated: 2025/01/16 17:48:20 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int jacobsthal(int i, bool reset)
{
    static std::vector<int> sequence;

    if (reset)
        sequence.clear();

    if (i < 0)
        return -1;
    if (i < (int)sequence.size())
        return sequence[i];
    if (i == 0)
    {
        sequence.push_back(0);
        return 0;
    }
    if (i == 1)
    {
        sequence.push_back(1);
        return 1;
    }
    
    sequence.push_back(2 * jacobsthal(i - 2) + jacobsthal(i - 1));
    return sequence[i];
}

int getIndex(int i, int recursion)
{
	return i * pow(2, recursion);
}

size_t getSize(const std::vector<int> &sequence, int recursion)
{
	return (int)sequence.size() / pow(2, recursion);
}

void swapPairs(std::vector<int> &sequence, int i1, int i2)
{
	for (int i = 0; i < i2 - i1; i++)
		std::swap(sequence[i1 + i], sequence[i2 + i]);
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
	
	for (size_t i = 0; i < getSize(sequence, recursion); i += 2)
	{
		if (sequence[getIndex(i, recursion)] < sequence[getIndex(i + 1, recursion)])
			swapPairs(sequence, getIndex(i, recursion), getIndex(i + 1, recursion));
	}
	mergeInsertion(sequence, recursion + 1);

	std::vector<int> lowers;
	for (size_t i = 0; i < getSize(sequence, recursion); i += 2)
		lowers.push_back(sequence[getIndex(i + 1, recursion)]);
}

void mergeInsertion(std::list<int> &sequence, int recursion)
{
	(void)sequence;
	(void)recursion;
}
