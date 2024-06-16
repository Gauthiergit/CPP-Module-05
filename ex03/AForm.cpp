/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 12:01:32 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/16 20:46:27 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, const int sigrade, const int exegrade) :
	_name(name), _signed(false), _sigrade(sigrade), _exegrade(exegrade)
{
	if (_sigrade < 1 || exegrade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (_sigrade > 150 || _exegrade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << GREEN << "Constructor AForm " << BLUE << this->_name << GREEN << 
		" called." << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed),
	_sigrade(copy._sigrade), _exegrade(copy._exegrade)  {}

AForm::~AForm()
{
	std::cout << GREEN << "Destructor AForm " << BLUE << this->_name <<
		GREEN << " called." << RESET << std::endl;
}

AForm& AForm::operator=(const AForm &change)
{
	this->_signed = change._signed;
	return (*this);
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Implemented grade is too high !");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Implemented grade is too low !");
}

const char* AForm::UnsignedException::what() const throw()
{
	return ("Form unsigned !");
}

const std::string AForm::getName() const
{
	return (this->_name);
}

bool		AForm::getSigned() const
{
	return (this->_signed);
}

int 	AForm::getSigrade() const
{
	return (this->_sigrade);
}

int	AForm::getExegrade() const
{
	return (this->_exegrade);
}

void		AForm::beSigned(const Bureaucrat& bu)
{
	if (bu.getGrade() > this->_sigrade)
		throw AForm::GradeTooLowException();
	else
		this->_signed = true;
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (this->getSigned() == false)
		throw UnsignedException();
	else if (executor.getGrade() > this->getExegrade())
		throw GradeTooLowException();
	else
	{
		this->justDoIt();
		std::cout << BLUE << executor.getName() << YELLOW << " executed " << BLUE <<
			this->getName() << RESET << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, AForm& form)
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