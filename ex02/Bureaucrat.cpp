/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:46:08 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/14 17:33:37 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
	std::cout << GREEN << "Default Constructor Bureaucrat called." << RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	std::cout << GREEN << "Constructor Bureaucrat " << BLUE << this->_name << GREEN << " called." << RESET << std::endl;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Implemented grade is too high !");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Implemented grade is too low !");
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << GREEN << "Destructor Bureaucrat " << BLUE << this->_name << GREEN << " called." << RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &change)
{
	this->_name = change._name;
	this->_grade = change._grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << BLUE << this->_name << YELLOW << "'s grad incremented." << RESET << std::endl;
}

void Bureaucrat::decrementGrade()
{
	this->_grade++;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << BLUE << this->_name << YELLOW << "'s grad decremented." << RESET << std::endl;
}

void		Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << BLUE << this->getName() << YELLOW << " signed " << BLUE <<
			form.getName() << RESET << std::endl;
	}
	catch (std::exception & e) 
	{
		std::cerr << BLUE << this->getName() << RED << " couldn’t sign " << 
			BLUE << form.getName() << RED << " because " << e.what() << RESET << std::endl; 
	}
}

void 	Bureaucrat::executeForm(AForm const& form)
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception & e) 
	{
		std::cerr << BLUE << this->getName() << RED << " couldn’t execute " << 
			BLUE << form.getName() << RED << " because " << e.what() << RESET << std::endl; 
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bu)
{
	os << BLUE << bu.getName() << YELLOW << ", bureaucrat grade " << BLUE << bu.getGrade() << RESET;
	return (os);
}
