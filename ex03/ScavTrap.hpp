#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap:
	virtual public ClapTrap
{
	public:

		ScavTrap(void);
		ScavTrap(const ScavTrap &src);
		ScavTrap(const std::string name);
		~ScavTrap(void);

		ScavTrap	&operator=(const ScavTrap &rhs);

		virtual void	attack(const std::string &target);
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);
		void			guardGate(void);
};

#endif
