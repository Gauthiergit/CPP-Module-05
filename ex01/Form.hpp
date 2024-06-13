/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:51:09 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/13 14:29:25 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
	
	const std::string 	_name;
	bool 				_signed;
	const int 			_sigrade;
	const int			_exegrade;

	public:

	class GradeTooHighException : public std::exception
	{
		public:

		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:

		virtual const char* what() const throw();
	};
	
	Form(std::string name, const int sigrade, const int exegrade);
	Form(const Form &copy);
	~Form();

	Form& operator=(const Form &change);

	const std::string getName() const;
	bool		getSigned() const;
	int 		getSigrade() const;
	int			getExegrade() const;
	void		beSigned(const Bureaucrat& bu);
};

std::ostream& operator<<(std::ostream& os, Form& form);

#endif