/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 23:51:04 by samuele           #+#    #+#             */
/*   Updated: 2025/01/18 18:56:36 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <ctime>
#include "PmergeMe.hpp"

template <typename T>
T stringToNumber(std::string str);
template <typename T>
void fillContainer(T &container, char **argv, int argc);

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << "Error: usage: ./PmergeMe [sequence]" << std::endl;
        return 1;
    }

    std::clock_t start_v = std::clock();

    std::vector<int> numbers_v;
    fillContainer(numbers_v, argv, argc);

    mergeInsertion(numbers_v);
    
    double duration_v = (std::clock() - start_v) / (double) CLOCKS_PER_SEC;

    jacobsthal(-1, true);

    std::clock_t start_l = std::clock();

    std::list<int> numbers_l;
    fillContainer(numbers_l, argv, argc);

    mergeInsertion(numbers_l);
    
    double duration_l = (std::clock() - start_l) / (double) CLOCKS_PER_SEC;

    std::vector<int> original;
    fillContainer(original, argv, argc);
    std::cout << "Before:" << std::endl;
    for (size_t i = 0; i < original.size(); i++)
        std::cout << original[i] << " ";
    std::cout << std::endl;
    std::cout << "After:" << std::endl;
    for (size_t i = 0; i < numbers_v.size(); i++)
        std::cout << numbers_v[i] << " ";
    std::cout << std::endl;
    std::cout << std::fixed << "Time to process a range of " << numbers_v.size() << " elements with std::vector: " << duration_v << "s" << std::endl;
    std::cout << std::fixed << "Time to process a range of " << numbers_l.size() << " elements with std::list:   " << duration_l << "s" << std::endl;
    
    return 0;
}

template <typename T>
void fillContainer(T &container, char **argv, int argc)
{
	for (int i = 1; i < argc; i++)
	{
		if (std::string(argv[i]).find_first_not_of("0123456789") != std::string::npos)
		{
			std::cerr << "Error: invalid sequence" << std::endl;
			exit(1);
		}
		container.push_back(stringToNumber<int>(argv[i]));
	}
}

template <typename T>
T stringToNumber(std::string str)
{
    T number;
    std::stringstream ss(str);

    ss >> number;
    return number;
}
