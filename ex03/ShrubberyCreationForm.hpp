/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 15:27:41 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/16 22:06:18 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCF_HPP
# define SCF_HPP

#include "AForm.hpp"

class  ShrubberyCreationForm : public AForm
{
	private:

	std::string _target;

	public:
	
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm &change);

	virtual void	justDoIt() const;

	virtual ShrubberyCreationForm*  clone(const std::string target) const;
	virtual ShrubberyCreationForm*  clone_wo_t() const;

	void setTarget(const std::string new_target);
};


#endif