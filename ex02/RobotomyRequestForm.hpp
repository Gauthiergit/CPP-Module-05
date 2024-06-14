/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeyre <gpeyre@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:05:05 by gpeyre            #+#    #+#             */
/*   Updated: 2024/06/14 17:33:58 by gpeyre           ###   ########.fr       */
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
};

#endif