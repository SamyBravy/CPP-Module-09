/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samuele <samuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:50:51 by samuele           #+#    #+#             */
/*   Updated: 2025/01/16 10:06:35 by samuele          ###   ########.fr       */
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

int &getFirst(int &elem)
{
    return elem;
}
