/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:08:21 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/16 22:04:50 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PPF_HPP
# define PPF_HPP

#include "AForm.hpp"

class  PresidentialPardonForm : public AForm
{
	private:

	std::string _target;

	public:
	
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=(const PresidentialPardonForm &change);

	virtual void	justDoIt() const;
	virtual PresidentialPardonForm*  clone(const std::string target) const;
	virtual PresidentialPardonForm*  clone_wo_t() const;
};


#endif