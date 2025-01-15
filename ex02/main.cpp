/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samuele <samuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:51:04 by samuele           #+#    #+#             */
/*   Updated: 2025/01/16 00:51:49 by samuele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
T stringToNumber(std::string str)
{
    T number;
    std::stringstream ss(str);

    ss >> number;
    return number;
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << "Error: usage: ./PmergeMe [sequence]" << std::endl;
        return 1;
    }

    std::clock_t start_v = std::clock();

    std::vector<int> numbers_v;

    for (int i = 1; i < argc; i++)
    {
        if (std::string(argv[i]).find_first_not_of("0123456789") != std::string::npos)
        {
            std::cerr << "Error: invalid sequence" << std::endl;
            return 1;
        }
        numbers_v.push_back(stringToNumber<int>(argv[i]));
    }

    PmergeMe<std::vector<int> > pmergeMe_v(numbers_v);
    pmergeMe_v.sort();
    
    double duration_v = (std::clock() - start_v) / (double) CLOCKS_PER_SEC;


    std::clock_t start_l = std::clock();

    std::list<int> numbers_l;

    for (int i = 1; i < argc; i++)
    {
        if (std::string(argv[i]).find_first_not_of("0123456789") != std::string::npos)
        {
            std::cerr << "Error: invalid sequence" << std::endl;
            return 1;
        }
        numbers_l.push_back(stringToNumber<int>(argv[i]));
    }

    PmergeMe<std::list<int> > pmergeMe_l(numbers_l);
    pmergeMe_l.sort();
    
    double duration_l = (std::clock() - start_l) / (double) CLOCKS_PER_SEC;


    std::cout << "Before:" << std::endl;
    for (size_t i = 0; i < numbers_v.size(); i++)
        std::cout << numbers_v[i] << " ";
    std::cout << std::endl;
    numbers_v = pmergeMe_v.getNumbers();
    std::cout << "After:" << std::endl;
    for (size_t i = 0; i < numbers_v.size(); i++)
        std::cout << numbers_v[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of 5 elements with std::vector: " << duration_v << "s" << std::endl;
    std::cout << "Time to process a range of 5 elements with std::list: " << duration_l << "s" << std::endl;
    
    return 0;
}
