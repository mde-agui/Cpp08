/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-agui <mde-agui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 12:33:38 by mde-agui          #+#    #+#             */
/*   Updated: 2025/06/14 13:09:09 by mde-agui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>	vct;
	vct.push_back(1);
	vct.push_back(2);
	vct.push_back(3);
	vct.push_back(2);

	try
	{
		std::vector<int>::iterator it = easyfind(vct, 2);
		std::cout	<< "Found: " << *it << " at position "
					<< (it - vct.begin()) << std::endl;
		it = easyfind(vct, 5);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::list<int>	lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	try
	{
		std::list<int>::iterator it = easyfind(lst,20);
		std::cout << "Found: " << *it << std::endl;
		it = easyfind(lst, 40);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
