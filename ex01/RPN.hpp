/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdell-er <sdell-er@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:05:11 by samuele           #+#    #+#             */
/*   Updated: 2025/01/18 18:32:07 by sdell-er         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
    private:
        std::stack<double> _stack;
    
    public:
        RPN();
        RPN(const RPN &copy);
        ~RPN();
        RPN &operator=(const RPN &copy);
        
        void calculate(const std::string &str);
};

#endif
