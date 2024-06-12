/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:05:09 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/12 22:06:19 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat bob("bob", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try
	{
		Bureaucrat john("john", 150);
		john.decrementGrade();
		std::cout << john << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	try
	{
		Bureaucrat max("max", 5);
		for(int i = 0; i < 5; i++)
		{
			max.incrementGrade();
			std::cout << max << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	return (0);
}
