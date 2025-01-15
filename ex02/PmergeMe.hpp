/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samuele <samuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:50:14 by samuele           #+#    #+#             */
/*   Updated: 2025/01/16 00:46:01 by samuele          ###   ########.fr       */
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

template <typename T>
class PmergeMe
{
    private:
        T _numbers;
    
    public:
        PmergeMe() { }
        PmergeMe(T numbers) : _numbers(numbers) { }
        PmergeMe(const PmergeMe &src) { *this = src; }
        ~PmergeMe() { }
        PmergeMe &operator=(const PmergeMe &src)
        {
            if (this != &src)
                _numbers = src.getNumbers();
            return *this;
        }

        T getNumbers() const { return _numbers; }
        void setNumbers(T numbers) { _numbers = numbers; }

        void sort();
};

int jacobsthal(int i);

template <typename T>
void PmergeMe<T>::sort()
{
    
}

#endif
