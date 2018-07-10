/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Loop.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-jage   <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 08/24/37 by lde-jage          #+#    #+#             */
/*   Updated: 2018/07/04 08/24/37 by lde-jage         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		LOOP_HPP
# define	LOOP_HPP

#include "IFunctions.hpp"

class Loop
{
	public:
		Loop();
		Loop(Loop const & src);
		~Loop();
		Loop & operator=(Loop const & src);

		void GameLoop(void);
		void LibError(void);
		void LibError(std::string & s);
	private:

	protected:

};

#endif
