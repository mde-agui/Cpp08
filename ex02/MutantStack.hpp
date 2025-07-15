#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <vector>
# include <list>
# include <exception>

//T = Type, C = Container
template <typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
public:
	typedef typename C::iterator			iterator;
	typedef typename C::const_iterator		const_iterator;
	typedef typename C::reverse_iterator	reverse_iterator;

	MutantStack() : std::stack<T, C>()
	{
	}

	MutantStack(const MutantStack& other) : std::stack<T, C>(other)
	{
	}

	MutantStack&	operator=(const MutantStack& other)
	{
		std::stack<T, C>::operator=(other);
		return (*this);
	}

	~MutantStack()
	{
	}

	iterator	begin()
	{
		return (this->c.begin());
	}

	iterator	end()
	{
		return (this->c.end());
	}

	const_iterator	begin() const
	{
		return (this->c.begin());
	}

	const_iterator	end() const
	{
		return (this->c.end());
	}

	reverse_iterator	rbegin()
	{
		return (this->c.rbegin());
	}

	reverse_iterator	rend()
	{
		return (this->c.rend());
	}
};

#endif