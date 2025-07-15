/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:01:14 by mde-agui          #+#    #+#             */
/*   Updated: 2025/06/16 10:30:04 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
try
{
Span	sp = Span(5);

sp.addNumber(7);
sp.addNumber(7);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Span			large(10000);
		std::list<int>	numbers;

		for (int i = 0; i < 10000; ++i)
			numbers.push_back(i * 2);
		large.addNumber(numbers.begin(), numbers.end());
		std::cout << "Shortest span (large): " << large.shortestSpan() << std::endl;
		std::cout << "Longest span (large): " << large.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Span	empty(1);

		empty.addNumber(1);
		empty.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
