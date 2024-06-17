/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:00:03 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/17 11:36:24 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <cstdlib>
#include <fstream>
#include <ctime>

class Bureaucrat;

class AForm
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

	class UnsignedException : public std::exception
	{
		public:

		virtual const char* what() const throw();
	};
	
	AForm(std::string name, const int sigrade, const int exegrade);
	AForm(const AForm &copy);
	virtual ~AForm();

	AForm& operator=(const AForm &change);

	const std::string getName() const;
	bool		getSigned() const;
	int 		getSigrade() const;
	int			getExegrade() const;
	void		beSigned(const Bureaucrat& bu);

	void	execute(Bureaucrat const& executor) const;
	virtual void justDoIt() const = 0;
	virtual AForm*  clone(const std::string target) const = 0;
	virtual AForm*  clone_wo_t() const = 0;
};

std::ostream& operator<<(std::ostream& os, AForm& form);

#endif