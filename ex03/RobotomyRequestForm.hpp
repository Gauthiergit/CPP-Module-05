/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:05:05 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/16 22:05:36 by gpeyre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RRF_HPP
# define RRF_HPP

#include "AForm.hpp"

class  RobotomyRequestForm : public AForm
{
	private:

	std::string _target;

	public:
	
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm &change);

	virtual void	justDoIt() const;

	virtual RobotomyRequestForm*  clone(const std::string target) const;
	virtual RobotomyRequestForm*  clone_wo_t() const;

	void setTarget(const std::string new_target);
};

#endif