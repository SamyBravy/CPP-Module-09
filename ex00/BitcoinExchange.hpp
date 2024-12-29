/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samuele <samuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:28:24 by samuele           #+#    #+#             */
/*   Updated: 2024/12/29 01:28:40 by samuele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <map>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _data;
        std::string _input;

        void fillData(const std::string &filename);
        bool validDate(const std::string &date);
        bool validNumber(const std::string &number);
    
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        ~BitcoinExchange();
        BitcoinExchange &operator=(const BitcoinExchange &other);
        
        void setInput(const std::string &input);
        void printResults();
};

template <typename T>
T stringToType(const std::string &str)
{
    std::stringstream ss(str);

    T result;

    ss >> result;

    return result;
}

#endif
