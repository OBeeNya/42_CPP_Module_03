#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):
	_name(""),
	_hit(10),
	_energy(10),
	_attack(0)
{
	std::cout << "Default constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string name):
	_name(name),
	_hit(10),
	_energy(10),
	_attack(0)
{
	std::cout << "Name constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Default destructor called" << std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	this->_name = rhs.getName();
	this->_hit = rhs.getHit();
	this->_attack = rhs.getAttack();
	this->_energy = rhs.getEnergy();
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (target.empty())
		std::cout << "ClapTrap " << this->_name << " needs a target to attack." \
		<< std::endl;
	else if (this->_energy && this->_hit && !this->_name.empty())
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << \
		", causing " << this->_attack << " points of damage!" << std::endl;
		this->_energy--;
	}
	else if (this->_name.empty())
		std::cout << "ClapTrap cannot attack, this ClapTrap was not named " \
		"yet..." << std::endl;
	else if (!this->_hit)
		std::cout << "ClapTrap " << this->_name << " cannot attack as it is " \
		<< "already dead..." << std::endl;
	else	
		std::cout << "ClapTrap " << this->_name << " cannot attack, not " \
		<< "enough energy points..." << std::endl;
	return ;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit && !this->_name.empty())
	{
		std::cout << "ClapTrap " << this->_name << " takes " << amount << \
		" points of damage." << std::endl;
		this->_hit -= amount;
		if (this->_hit < 0)
			this->_hit = 0;
		if (!this->_hit)
			std::cout << "ClapTrap " << this->_name << " has died." << std::endl;
	}
	else if (this->_name.empty())
		std::cout << "Nothing can happen to this ClapTrap as it was not named" \
		<< " yet..." << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " is already dead..." \
		<< std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy && this->_hit && this->_hit != 10)
	{
		std::cout << "ClapTrap " << this->_name << " repairs itself for " \
		<< amount << " points." << std::endl;
		this->_hit += amount;
		if (this->_hit > 10)
			this->_hit = 10;
		this->_energy--;
	}
	else if (this->_hit == 10)
		std::cout << "ClapTrap " << this->_name << " cannot repair itself " \
		<< "as it already has full hit points." << std::endl;
	else if (!this->_energy)
		std::cout << "ClapTrap " << this->_name << " cannot repair itself," \
		<< " not enough energy points..." << std::endl;
	else
		std::cout << "ClapTrap " << this->_name << " cannot repair itself as" \
		<< " it is already dead..." << std::endl;
	return ;
}

std::string	ClapTrap::getName(void) const
{
	return (this->_name);
}

int	ClapTrap::getHit(void) const
{
	return (this->_hit);
}

int	ClapTrap::getEnergy(void) const
{
	return (this->_energy);
}

int	ClapTrap::getAttack(void) const
{
	return (this->_attack);
}
