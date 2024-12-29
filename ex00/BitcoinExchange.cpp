/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samuele <samuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:28:03 by samuele           #+#    #+#             */
/*   Updated: 2024/12/29 01:58:13 by samuele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    fillData("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange::~BitcoinExchange() { }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this == &other)
        return *this;
    _data = other._data;
    _input = other._input;
    return *this;
}

void BitcoinExchange::fillData(const std::string &filename)
{
    if (filename.find(".csv") == std::string::npos)
        throw std::invalid_argument("Error: invalid file format");
    
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::invalid_argument("Error: could not open " + filename);
    
    std::string line;
    std::string date;
    std::string rate;
    while (std::getline(file, line))
    {
        if (line.empty() || line == "date,exchange_rate")
            continue;
        
        if (line.find(',') == std::string::npos)
            throw std::invalid_argument("Error: invalid " + filename + " format");
        date = line.substr(0, line.find(','));
        if (date.empty() || !validDate(date))
            throw std::invalid_argument("Error: invalid " + filename + " format");
        
        rate = line.substr(line.find(',') + 1);
        if (rate.empty() || !validNumber(rate))
            throw std::invalid_argument("Error: invalid " + filename + " format");
        _data[date] = stringToType<double>(rate);
    }

    file.close();
}

bool BitcoinExchange::validDate(const std::string &date)
{
    if (date.size() != 10)
        return false;

    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    if (date[4] != '-' || date[7] != '-')
        return false;
    if (year.find_first_not_of("0123456789") != std::string::npos)
        return false;
    if (month.find_first_not_of("0123456789") != std::string::npos)
        return false;
    if (day.find_first_not_of("0123456789") != std::string::npos)
        return false;
    
    int maxDays;
    
    if (month == "01" || month == "03" || month == "05" || month == "07" || month == "08" || month == "10" || month == "12")
        maxDays = 31;
    else if (month == "04" || month == "06" || month == "09" || month == "11")
        maxDays = 30;
    else if (month == "02")
    {
        if ((stringToType<int>(year) % 4 == 0 && stringToType<int>(year) % 100 != 0) || stringToType<int>(year) % 400 == 0)
            maxDays = 29;
        else
            maxDays = 28;
    }
    else
        return false;
    
    if (stringToType<int>(day) > maxDays || stringToType<int>(day) < 1)
        return false;

    return true;
}

bool BitcoinExchange::validNumber(const std::string &number)
{
    if (number.find_first_not_of("0123456789.") != std::string::npos)
        return false;
    if (number.find('.') != number.rfind('.'))
        return false;
    if(number.find('.') == number.size() - 1 || number.find('.') == 0)
        return false;
    return true;
}

void BitcoinExchange::setInput(const std::string &filename)
{
    _input = filename;
}

void BitcoinExchange::printResults()
{
    std::ifstream file(_input.c_str());
    if (!file.is_open())
        throw std::invalid_argument("Error: could not open " + _input);

    std::string line;
    std::string date;
    std::string value;
    while (std::getline(file, line))
    {
        if (line.empty() || line == "date | value")
            continue;
        
        if (line.find(" | ") == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        date = line.substr(0, line.find(" | "));
        if (date.empty() || !validDate(date))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        value = line.substr(line.find(" | ") + 3);
        if (value.empty() || !validNumber(value)
            || stringToType<double>(value) < 0 || stringToType<double>(value) > 1000)
        {
            std::cout << "Error: the value must be a positive number between 0 and 1000" << std::endl;
            continue;
        }
    
        std::map<std::string, double>::iterator it = _data.find(date);
        if (it == _data.end())
        {
            it = _data.lower_bound(date);
            if (it == _data.begin())
            {
                std::cout << "No data before " << date << std::endl;
                continue;
            }
            --it;
        }
        
        std::cout << it->first << " => " << value << " = " << it->second * stringToType<double>(value) << std::endl;
    }

    file.close();
}
