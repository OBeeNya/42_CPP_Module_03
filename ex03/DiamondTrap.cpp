#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
	FragTrap	frag;
	ScavTrap	scav;
	std::cout << "DiamondTrap default constructor called" << std::endl;
	_name = "";
	_hit = frag.getHit();
	_energy = scav.getEnergy();
	_attack = frag.getAttack();
	return ;
}

DiamondTrap::DiamondTrap(const std::string name)
{
	FragTrap	frag;
	ScavTrap	scav;
	std::cout << "DiamondTrap name constructor called" << std::endl;
	_name = name;
	_hit = frag.getHit();
	_energy = scav.getEnergy();
	_attack = frag.getAttack();
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = src;
	return ;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap default destructor called" << std::endl;
	return ;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &rhs)
{
	this->_name = rhs.getName();
	this->_hit = rhs.getHit();
	this->_attack = rhs.getAttack();
	this->_energy = rhs.getEnergy();
	return (*this);
}

void	DiamondTrap::attack(const std::string &target)
{
	if (target.empty())
		std::cout << "DiamondTrap " << this->_name << " needs a target to attack." \
		<< std::endl;
	else if (this->_energy && this->_hit && !this->_name.empty())
	{
		std::cout << "DiamondTrap " << this->_name << " attacks " << target << \
		", causing " << this->_attack << " points of damage!" << std::endl;
		this->_energy--;
	}
	else if (this->_name.empty())
		std::cout << "DiamondTrap cannot attack, this ClapTrap was not named " \
		"yet..." << std::endl;
	else if (!this->_hit)
		std::cout << "DiamondTrap " << this->_name << " cannot attack as it is " \
		<< "already dead..." << std::endl;
	else	
		std::cout << "DiamondTrap " << this->_name << " cannot attack, not " \
		<< "enough energy points..." << std::endl;
	return ;
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	if (this->_hit && !this->_name.empty())
	{
		std::cout << "DiamondTrap " << this->_name << " takes " << amount << \
		" points of damage." << std::endl;
		this->_hit -= amount;
		if (this->_hit < 0)
			this->_hit = 0;
		if (!this->_hit)
			std::cout << "DiamondTrap " << this->_name << " has died." << std::endl;
	}
	else if (this->_name.empty())
		std::cout << "Nothing can happen to this DiamondTrap as it was not named" \
		<< " yet..." << std::endl;
	else
		std::cout << "DiamondTrap " << this->_name << " is already dead..." \
		<< std::endl;
	return ;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (this->_energy && this->_hit && this->_hit != 100)
	{
		std::cout << "DiamondTrap " << this->_name << " repairs itself for " \
		<< amount << " points." << std::endl;
		this->_hit += amount;
		if (this->_hit > 100)
			this->_hit = 100;
		this->_energy--;
	}
	else if (this->_hit == 100)
		std::cout << "DiamondTrap " << this->_name << " cannot repair itself " \
		<< "as it already has full hit points." << std::endl;
	else if (!this->_energy)
		std::cout << "DiamondTrap " << this->_name << " cannot repair itself," \
		<< " not enough energy points..." << std::endl;
	else
		std::cout << "DiamondTrap " << this->_name << " cannot repair itself as" \
		<< " it is already dead..." << std::endl;
	return ;
}

void	DiamondTrap::highFiveGuys(void)
{
	std::cout << "DiamondTrap " << this->_name << " is asking for your best high five." \
	<< std::endl;
	return ;
}

void	DiamondTrap::guardGate(void)
{
	std::cout << "DiamondTrap " << this->_name << " has entered Gate keeper mode." \
	<< std::endl;
	return ;
}