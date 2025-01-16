/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samuele <samuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:50:14 by samuele           #+#    #+#             */
/*   Updated: 2025/01/16 10:07:57 by samuele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm>

int jacobsthal(int i, bool reset = false);
int &getFirst(int &elem);

template <typename T>
int &getFirst(std::pair<T, T> &elem)
{
    return getFirst(elem.first);
}

template <typename T>
void mergeInsertion(std::vector<T> &sequence)
{
    if (sequence.size() < 2)
        return;
    if (sequence.size() == 2)
    {
        if (getFirst(sequence[0]) > getFirst(sequence[1]))
            std::swap(getFirst(sequence[0]), getFirst(sequence[1]));
        return;
    }

    std::vector<std::pair<T, T> > pairs;
    for (size_t i = 0; i < sequence.size() - (sequence.size() % 2); i += 2)
    {
        pairs.push_back(std::make_pair(sequence[i], sequence[i + 1]));
        if (getFirst(pairs.back().first) < getFirst(pairs.back().second))
            std::swap(getFirst(pairs.back().first), getFirst(pairs.back().second));
    }
    mergeInsertion<std::vector<std::pair<T, T> > >(pairs);
}

template <typename T>
void mergeInsertion(std::list<T> &sequence)
{
    (void)sequence;
}

#endif
