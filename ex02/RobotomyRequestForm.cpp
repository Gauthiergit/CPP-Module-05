/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:06:28 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/17 11:41:41 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << GREEN << "Constructor " << BLUE << " RobotomyRequestForm " <<
		GREEN << "called." << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : 
	AForm(copy) {}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << GREEN << "Destructor " << BLUE << " RobotomyRequestForm " <<
		GREEN << "called." << RESET << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &change)
{
	AForm::operator=(change);
	return (*this);
}

void	RobotomyRequestForm::justDoIt() const
{
	std::cout << YELLOW << "drrrrriiiiiiiiiiiiiiiiiilllll" << RESET<< std::endl;
	// srand(static_cast<unsigned int>(time(0)));
	int random_number = rand();
	if (random_number % 2 == 0)
		std::cout << BLUE << this->_target << YELLOW << " has been robotomized succesfully." << RESET << std::endl;
	else
		std::cout << YELLOW << "Robotomy failed" << RESET << std::endl;
}