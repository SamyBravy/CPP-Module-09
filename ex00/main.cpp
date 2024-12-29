/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samuele <samuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:28:44 by samuele           #+#    #+#             */
/*   Updated: 2024/12/29 01:12:53 by samuele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: usage: ./btc <filename>" << std::endl;
        return 1;
    }
    if (std::string(argv[1]).find(".csv") == std::string::npos)
    {
        std::cerr << "Error: invalid file format" << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange exchange;
        exchange.setInput(argv[1]);
        
        exchange.printResults();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
