/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samuele <samuele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:10:06 by samuele           #+#    #+#             */
/*   Updated: 2024/12/29 15:25:38 by samuele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : _stack() { }

RPN::RPN(const RPN &copy) : _stack(copy._stack) { }

RPN::~RPN() { }

RPN &RPN::operator=(const RPN &copy)
{
    if (this != &copy)
        _stack = copy._stack;
    return (*this);
}

void RPN::calculate(const std::string &str)
{
    if (str.find_first_not_of("0123456789+-/* ") != std::string::npos)
        throw std::invalid_argument("Error: invalid character in string");

    std::string::const_iterator it = str.begin();
    while (it != str.end())
    {
        if (std::isspace(*it))
        { }
        else if (std::isdigit(*it))
            _stack.push(*it - '0');
        else
        {
            if (_stack.size() < 2)
                throw std::invalid_argument("Error: invalid number of operands");
            
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();
            
            switch (*it)
            {
                case '+':
                    _stack.push(a + b);
                    break;
                case '-':
                    _stack.push(a - b);
                    break;
                case '*':
                    _stack.push(a * b);
                    break;
                case '/':
                    _stack.push(a / b);
                    break;
                default:
                    throw std::invalid_argument("Error: invalid operator");
            }
        }
        it++;
    }

    if (_stack.size() != 1)
        throw std::invalid_argument("Error: invalid number of operands");

    std::cout << _stack.top() << std::endl;
}
