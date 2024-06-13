/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:46:46 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/13 17:56:20 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << GREEN << "Constructor " << BLUE << " ShrubberyCreationForm " <<
		GREEN << "called." << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : 
	AForm(copy) {}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << GREEN << "Destructor " << BLUE << " ShrubberyCreationForm " <<
		GREEN << "called." << RESET << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &change)
{
	AForm::operator=(change);
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor)
{
	if (this->getSigned() == false)
		throw UnsignedException();
	else if (executor.getGrade() > this->getExegrade())
		throw GradeTooLowException();
	
	std::string outfile_name = this->_target+"_shrubbery";
	std::ofstream outfile(outfile_name.c_str());
	if (!outfile.is_open())
	{
		std::cerr << RED << "Error to open outfile" << RESET << std::endl;
		exit(1);
	}

}