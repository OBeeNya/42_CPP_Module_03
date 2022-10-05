#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	_name = "";
	_hit = 100;
	_energy = 50;
	_attack = 20;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
	return ;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "ScavTrap name constructor called" << std::endl;
	_name = name;
	_hit = 100;
	_energy = 50;
	_attack = 20;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap default destructor called" << std::endl;
	return ;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs)
{
	this->_name = rhs.getName();
	this->_hit = rhs.getHit();
	this->_attack = rhs.getAttack();
	this->_energy = rhs.getEnergy();
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (target.empty())
		std::cout << "ScavTrap " << this->_name << " needs a target to attack." \
		<< std::endl;
	else if (this->_energy && this->_hit && !this->_name.empty())
	{
		std::cout << "ScavTrap " << this->_name << " attacks " << target << \
		", causing " << this->_attack << " points of damage!" << std::endl;
		this->_energy--;
	}
	else if (this->_name.empty())
		std::cout << "ScavTrap cannot attack, this ClapTrap was not named " \
		"yet..." << std::endl;
	else if (!this->_hit)
		std::cout << "ScavTrap " << this->_name << " cannot attack as it is " \
		<< "already dead..." << std::endl;
	else	
		std::cout << "ScavTrap " << this->_name << " cannot attack, not " \
		<< "enough energy points..." << std::endl;
	return ;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hit && !this->_name.empty())
	{
		std::cout << "ScavTrap " << this->_name << " takes " << amount << \
		" points of damage." << std::endl;
		this->_hit -= amount;
		if (this->_hit < 0)
			this->_hit = 0;
		if (!this->_hit)
			std::cout << "ScavTrap " << this->_name << " has died." << std::endl;
	}
	else if (this->_name.empty())
		std::cout << "Nothing can happen to this ScavTrap as it was not named" \
		<< " yet..." << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " is already dead..." \
		<< std::endl;
	return ;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_energy && this->_hit && this->_hit != 100)
	{
		std::cout << "ScavTrap " << this->_name << " repairs itself for " \
		<< amount << " points." << std::endl;
		this->_hit += amount;
		if (this->_hit > 100)
			this->_hit = 100;
		this->_energy--;
	}
	else if (this->_hit == 100)
		std::cout << "ScavTrap " << this->_name << " cannot repair itself " \
		<< "as it already has full hit points." << std::endl;
	else if (!this->_energy)
		std::cout << "ScavTrap " << this->_name << " cannot repair itself," \
		<< " not enough energy points..." << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " cannot repair itself as" \
		<< " it is already dead..." << std::endl;
	return ;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " has entered Gate keeper mode." \
	<< std::endl;
	return ;
}
