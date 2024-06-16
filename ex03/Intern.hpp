/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 19:19:21 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/16 19:19:21 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	private:

	AForm* _form[3];

	public:

	Intern();
	Intern(const Intern &copy);
	~Intern();

	Intern& operator=(const Intern &change);

	AForm* makeForm(const std::string form_name, const std::string target);

	class FormExistException : public std::exception
	{
		public:

		virtual const char* what() const throw();
	};
};

#endif