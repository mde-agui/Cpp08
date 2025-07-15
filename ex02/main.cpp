/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:09:18 by mde-agui          #+#    #+#             */
/*   Updated: 2025/06/17 11:27:58 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T, typename C>
void	printStack(const MutantStack<T, C>& stack, const std::string& testName)
{
	std::cout << testName << " (size: " << stack.size() << "): ";
	if (stack.empty())
	{
		std::cout << "Empty" << std::endl;
		return ;
	}
	for (typename MutantStack<T, C>::const_iterator it = stack.begin(); it != stack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int	main(void)
{
	std::cout << "-------Subject test-------" << std::endl;
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	printStack(mstack, "Stack contents");
	std::cout << "Size after pop: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(4);
	mstack.push(737);
	mstack.push(0);
	printStack(mstack, "Stack contents");

	std::cout << "\n-------Empty stack test-------" << std::endl;
	MutantStack<int>	emptyStack;

	printStack(emptyStack, "Empty stack");
	std::cout << "Is empty: " << (emptyStack.empty() ? "Yes" : "No") << std::endl;

	std::cout << "\n-------Single element test-------" << std::endl;
	MutantStack<int>	single;

	single.push(42);
	printStack(single, "Single element");
	std::cout << "Top: " << single.top() << std::endl;
	single.pop();
	printStack(single, "After pop");

	std::cout << "\n-------Large stack test-------" << std::endl;
	MutantStack<int>	largeStack;

	for (int i = 0; i < 1000; ++i)
		largeStack.push(i);
	std::cout << "Size: " << largeStack.size() << std::endl;
	std::cout << "Top: " << largeStack.top() << std::endl;

	MutantStack<int>::iterator it = largeStack.begin();
	std::cout << "First five elements: ";
	for (int i = 0; i < 5 && it != largeStack.end(); ++i, ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	it = largeStack.end();
	--it;
	std::cout << "Last element: " << *it << std::endl;

	std::cout << "\n-------Copy Constructor test-------" << std::endl;
	MutantStack<int>	copyStack(mstack);

	printStack(copyStack, "Copied stack");
	copyStack.push(999);
	printStack(copyStack, "Copied stack after push");
	printStack(mstack, "Original stack (unchanged)");

	std::cout << "\n-------Assignement Operator test-------" << std::endl;
	MutantStack<int>	assignStack;
	assignStack = mstack;
	printStack(assignStack, "Assigned stack");
	assignStack.pop();
	printStack(assignStack, "Assigned stack after pop");
	printStack(mstack, "Original stack (unchanged)");

	std::cout << "\n------- Const iterator-------" << std::endl;
	const MutantStack<int>	constStack(mstack);

	printStack(constStack, "Const stack");

	std::cout << "\n-------Modify via iterator test-------" << std::endl;
	MutantStack<int>	modStack;

	modStack.push(1);
	modStack.push(2);
	modStack.push(3);
	printStack(modStack, "Before mod");
	for (MutantStack<int>::iterator it = modStack.begin(); it != modStack.end(); ++it)
		*it += 10;
	printStack(modStack, "After mod");

	std::cout << "\n-------Using std::vector as container-------" << std::endl;
	MutantStack<int, std::vector<int> >	vecStack;
	vecStack.push(100);
	vecStack.push(200);
	vecStack.push(300);
	printStack(vecStack, "Vector-based stack");

	std::cout << "\n-------Stack with double test-------" << std::endl;
	MutantStack<double>	doubleStack;
	doubleStack.push(3.14);
	doubleStack.push(2.424);
	printStack(doubleStack, "Double stack");

	std::cout << "\n-------Reverse Iterator test-------" << std::endl;
	MutantStack<int>	revStack;

	revStack.push(1);
	revStack.push(2);
	revStack.push(3);
	std::cout << "Reverse order: ";
	for (MutantStack<int>::reverse_iterator it = revStack.rbegin(); it != revStack.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\n-------Stress test-------" << std::endl;
	MutantStack<int>	stressStack;
	
	for (int i = 0; i < 10000; ++i)
		stressStack.push(i);
	std::cout << "Size: " << stressStack.size() << std::endl;
	std::cout << "Top: " << stressStack.top() << std::endl;
	
	std::cout << "\n-------Using std::list as container-------" << std::endl;
	MutantStack<int, std::list<int> > listStack;

	listStack.push(400);
	listStack.push(500);
	listStack.push(600);
	printStack(listStack, "List-based stack");

	std::cout << "\n-------String stack test-------" << std::endl;
	MutantStack<std::string>	strStack;

	strStack.push("Hello");
	strStack.push("World");
	strStack.push("!");
	printStack(strStack, "String stack");

	return (0);
}