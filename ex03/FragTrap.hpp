#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap:
	virtual public ClapTrap
{
	public:

		FragTrap(void);
		FragTrap(const FragTrap &src);
		FragTrap(const std::string name);
		~FragTrap(void);

		FragTrap	&operator=(const FragTrap &rhs);

		virtual void	attack(const std::string &target);
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);
		void			highFiveGuys(void);
};

#endif
