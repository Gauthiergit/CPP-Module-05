/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:06:28 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/16 22:47:08 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
	AForm("robotomy request", 72, 45), _target(target)
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
	int random_number = rand();
	if (random_number % 2 == 0)
		std::cout << BLUE << this->_target << YELLOW << " has been robotomized succesfully." << RESET << std::endl;
	else
		std::cout << YELLOW << "Robotomy failed" << RESET << std::endl;
}

RobotomyRequestForm*  RobotomyRequestForm::clone(const std::string target) const
{
	return (new RobotomyRequestForm(target));
}

RobotomyRequestForm*  RobotomyRequestForm::clone_wo_t() const
{
	return (new RobotomyRequestForm(*this));
}