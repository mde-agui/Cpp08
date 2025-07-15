#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <list>
# include <stdexcept>
# include <algorithm>
# include <iterator>

class Span
{
private:
	unsigned int		_maxSize;
	std::vector<int>	_numbers;

public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span&	operator=(const Span& other);
	~Span();

	void			addNumber(int num);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	template <typename I>
	void	addNumber(I first, I last)
	{
		size_t	distance = std::distance(first, last);

		if (_numbers.size() + distance > _maxSize)
			throw (std::runtime_error("Range exceeds Span capacity"));
		_numbers.insert(_numbers.end(), first, last);
	}
};

//# include "Span.cpp"

#endif