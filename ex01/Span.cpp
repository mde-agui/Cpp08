/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:01:23 by mde-agui          #+#    #+#             */
/*   Updated: 2025/06/16 10:30:14 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0)
{
}

Span::Span(unsigned int N) : _maxSize(N)
{
}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int num)
{
	if (_numbers.size() >= _maxSize)
		throw (std::runtime_error("Span is full"));
	_numbers.push_back(num);
}

unsigned int	Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw (std::runtime_error("Not enough numbers for span"));
	std::vector<int>	sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	unsigned int	min_diff = static_cast<unsigned int>(sorted[1] - sorted[0]);
	for (size_t i = 1; i < sorted.size() - 1; ++i)
	{
		unsigned int	diff = static_cast<unsigned int>(sorted[i + 1] - sorted[i]);
		if (diff < min_diff)
			min_diff = diff;
	}
	return (min_diff);
}

unsigned int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw (std::runtime_error("Not enough numbers for span"));
	int	min = *std::min_element(_numbers.begin(), _numbers.end());
	int	max = *std::max_element(_numbers.begin(), _numbers.end());
	return (static_cast<unsigned int>(max - min));
}

/* template <typename I>
void	Span::addNumber(I first, I last)
{
	size_t	distance = std::distance(first, last);
	if (_numbers.size() + distance > _maxSize)
		throw (std::runtime_error("Range exceeds Span capacity"));
	_numbers.insert(_numbers.end(), first, last);
} */
