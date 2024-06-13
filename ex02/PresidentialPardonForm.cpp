/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:09:30 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/13 17:10:48 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << GREEN << "Constructor " << BLUE << " PresidentialPardonForm " <<
		GREEN << "called." << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : 
	AForm(copy) {}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << GREEN << "Destructor " << BLUE << " PresidentialPardonForm " <<
		GREEN << "called." << RESET << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &change)
{
	AForm::operator=(change);
	return (*this);
}