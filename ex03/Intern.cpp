/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:24:31 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/16 19:24:31 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << GREEN << "Constructor Intern called." << RESET << std::endl;
	this->_form[0] = new ShrubberyCreationForm("");
	this->_form[1] = new RobotomyRequestForm("");
	this->_form[2] = new PresidentialPardonForm("");
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern::~Intern()
{
	std::cout << GREEN << "Destructor Intern called." << RESET << std::endl;
	for(int i = 0; i < 3; i++)
		delete this->_form[i];
}

Intern& Intern::operator=(const Intern &change)
{
	for(int i = 0; i < 3; i++)
	{
		delete this->_form[i];
		this->_form[i] = change._form[i];
	}
	return (*this);
}

const char* Intern::FormExistException::what() const throw()
{
	return ("Form doesn't exist !");
}

AForm* Intern::makeForm(const std::string form_name, const std::string target)
{
	int i = 0;
	for(; i < 3 && this->_form[i]->getName() != form_name; i++);
	if (i < 3)
		std::cout << YELLOW << "Intern creates " << BLUE << this->_form[i]->getName()<< RESET << std::endl;
	return i < 3 ? this->_form[i]->clone(target) : throw Intern::FormExistException();
}
