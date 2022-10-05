#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap:
	public FragTrap,
	public ScavTrap
{
	public:

		DiamondTrap(void);
		DiamondTrap(const DiamondTrap &src);
		~DiamondTrap(void);
		DiamondTrap(const std::string name);

		DiamondTrap	&operator=(const DiamondTrap &rhs);

		void			whoAmI(void);
		using			ScavTrap::attack;
		virtual void	attack(const std::string &target);
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);
		virtual void	highFiveGuys(void);
		virtual void	guardGate(void);

	private:

		std::string	_name;
};

#endif
