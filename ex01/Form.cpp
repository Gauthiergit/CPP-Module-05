/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:01:32 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/13 14:38:23 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, const int sigrade, const int exegrade) :
	_name(name), _signed(false), _sigrade(sigrade), _exegrade(exegrade)
{
	if (_sigrade < 1 || exegrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_sigrade > 150 || _exegrade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << GREEN << "Constructor Form " << BLUE << this->_name << GREEN << 
		" called." << std::endl;
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed),
	_sigrade(copy._sigrade), _exegrade(copy._exegrade)  {}

Form::~Form()
{
	std::cout << GREEN << "Destructor Form " << BLUE << this->_name <<
		GREEN << " called." << RESET << std::endl;
}

Form& Form::operator=(const Form &change)
{
	this->_signed = change._signed;
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Implemented grade is too high !");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Implemented grade is too low !");
}

const std::string Form::getName() const
{
	return (this->_name);
}

bool		Form::getSigned() const
{
	return (this->_signed);
}

int 	Form::getSigrade() const
{
	return (this->_sigrade);
}

int	Form::getExegrade() const
{
	return (this->_exegrade);
}

void		Form::beSigned(const Bureaucrat& bu)
{
	if (bu.getGrade() > this->_sigrade)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, Form& form)
{
	std::string status;
	if (form.getSigned())
		status = "signed";
	else
		status = "unsigned";
	os << YELLOW << "Form's name: " << BLUE << form.getName() << "\n" <<
		YELLOW << "Minimum grade to sign: " << BLUE << form.getSigrade() << "\n" <<
		YELLOW << "Minimum grade to execute: " << BLUE << form.getExegrade() << "\n" <<
		YELLOW << "Form's status: " << BLUE << status << RESET << std::endl;
	return (os);
}