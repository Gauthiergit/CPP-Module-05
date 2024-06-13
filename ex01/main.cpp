/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:05:09 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/13 14:44:42 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	std::cout << "----------------------------------------------" << std::endl;
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
	std::cout << "----------------------------------------------" << std::endl;
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
	std::cout << "----------------------------------------------" << std::endl;
	try
	{
		Form nuclear("Nuclear Code", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << "----------------------------------------------" << std::endl;
	try
	{
		Bureaucrat gauth("gauthier", 26);
		std::cout << gauth << std::endl;
		Form nuclear("Nuclear Code", 1, 1);
		Form sausage("Sausage at lunch", 120, 120);
		std::cout << std::endl;
		std::cout << nuclear << std::endl;
		std::cout << std::endl;
		std::cout << sausage << std::endl;
		sausage.beSigned(gauth);
		gauth.signForm(sausage);
		std::cout << std::endl;
		std::cout << sausage << std::endl;
		std::cout << std::endl;
		gauth.signForm(nuclear);
		nuclear.beSigned(gauth);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	return (0);
}
