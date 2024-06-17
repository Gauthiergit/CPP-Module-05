/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:05:09 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/17 11:35:44 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Intern marion;
		std::cout << "----------------------------------------------" << std::endl;
		AForm* form1 = marion.makeForm("presidential pardon", "bob");
		AForm* form2 = marion.makeForm("robotomy request", "gautier");
		AForm* form3 = marion.makeForm("shrubbery creation", "42 school");
		std::cout << "----------------------------------------------" << std::endl;
		Bureaucrat max("max", 3);
		max.signForm(*form1);
		max.executeForm(*form1);
		max.signForm(*form2);
		max.executeForm(*form2);
		max.signForm(*form3);
		max.executeForm(*form3);
		delete form1;
		delete form2;
		delete form3;
		AForm* form4 = marion.makeForm("sausage party", "flo");
		max.signForm(*form4);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	return (0);
}
