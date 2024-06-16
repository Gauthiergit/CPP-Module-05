/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:46:46 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/16 22:47:50 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :
	AForm("shrubbery creation", 145, 137), _target(target)
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

void	ShrubberyCreationForm::justDoIt() const
{
	std::string outfile_name = this->_target+"_shrubbery";
	std::ofstream outfile(outfile_name.c_str());
	if (!outfile.is_open())
	{
		std::cerr << RED << "Error to open outfile" << RESET << std::endl;
		exit(1);
	}
	const std::string tree =
		"	                                     #######,*                               \n"
		"                          /#############%%%####% ###                            \n"
		"                        ########%%%%%%%#######%%%####%########/#                \n"
		"          .*            ###%%%%%%%%####%%####%%%%%%#######%%%##.##(             \n"
		"         /######** #%## (######%%%%%%##%%%%%%%%%%%####%#%%%%%##%%#######        \n"
		"       /####%#%%%%################%%%##%%%%%##%#%%%###%%%%%%%%%%%%%%%##         \n"
		"      ,,##%%#%%%#####%%%%%%%%%%%%#########%###%############%%%#%%%##%%%         \n"
		"    *###%#%%%#%%######%%%%%%%%%%###%%%%%%%%%%%%%%%%%%%%%###%%%%%%%%######       \n"
		"      ####%%#%%%%%#####%%%%%%%%%&#%%%%%%####%%%%%%%%#######%%%%%%%%%#######     \n"
		"   (############%%%####%%%%#####%##%%#%##%%%###%%%%%%%########%###%###%%%%###   \n"
		" #######%%%%%%%%%%%%#########%%%%#####%%%%%%%#%#%%%%###%%%%%%%%######%%%####.   \n"
		" #####%%&%%%%%%%####%%%%%#####%%%%#%%%%%%%%%%%%%%%%%###%%%%%%%%%%%####%#%##     \n"
		" #.####&&&&%&%%%#%#%%%%%%%##%%%%%%%%%%%%%%%%%%%%%#&##%%#%%%%%%%%%%%&%%%%%%%##   \n"
		"  ,#####%&&&%%&%%###%%%#%%#%###%##%%%%%%%%%&%%%%%%%&%&&&%%%%%%%%%%%%%%%######## \n"
		"     #######&%%&&%&#####%%%%%%%%%%%%%%%%%%%%%%%%%%&&&&&&&&&%%%%%%%%%%&%#%%%%### \n"
		"      ###&&&&&&&&&&&&&&%###&#&%%%%%&&&&&&&&&&%%%%&%&%%%%%%&&&&&&&&&&&%%%%%%#####\n"
		"      / # ##&&&&&&&%&&&&&&%%#&&&&&&&%&&&&&&&##&&&&&&&&&&&&&&&%##%%%#%%%%######/ \n"
		"           (((###%%%%%%%%%&&%%%&&&&&&%&&&&&&&&##%%%&&&&&&&&&&%%%%%###(#         \n"
		"                ##%%%##%%#%%&&&&%&&&%&%&&&&&&%%&%%&&&&&&&%%%%#######            \n"
		"                           /%%%&%&&%%&&&%&&%&&&&&&@%,#   ..#,   .               \n"
		"                              /&%&&%%%&%&&&%%&&&                                \n"
		"                                &#&% #%%%%&%&&&                                 \n"
		"                                 %&%&&%%%&&&&&                                  \n"
		"                                    &%%%&&&&%&,                                 \n"
		"                                     %&%&%%%&&&                                 \n"
		"                                     &%#%%%&&%&                                 \n"
		"                                     &%#%%&&&&&                                 \n"
		"                                     %%%&%%&&&&                                 \n"
		"                                    %%%&%%&%&&&&%                               \n"
		"                                   %%%%%&%&%&&&&&&                              \n"
		"                                  #%%&%%%%%&&&&&&&&                             \n"
		"                                %%&%%%&#&&&%&&&&&&&&&%                          \n"
		"                           %%%%%&%%&&&%&&&&&&&&&/*,,,,....                      \n";
	outfile << tree;
	outfile.close();
	std::cout << GREEN << "Tree planted in " BLUE << this->_target << RESET << std::endl;
}

ShrubberyCreationForm*  ShrubberyCreationForm::clone(const std::string target) const
{
	return (new ShrubberyCreationForm(target));
}

ShrubberyCreationForm*  ShrubberyCreationForm::clone_wo_t() const
{
	return (new ShrubberyCreationForm(*this));
}