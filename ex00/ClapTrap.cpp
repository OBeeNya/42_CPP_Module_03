#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):
	_name(NULL),
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
	if (this->_energy && this->_hit)
	{
		std::cout << "Claptrap " << this->_name << " attacks " << target << \
		", causing " << this->_attack << " points of damage!" << std::endl;
		this->_energy--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " cannot attack, not " \
		<< "enough energy or hit points..." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " takes " << amount << \
	" points of damage." << std::endl;
	this->_hit -= amount;
	if (this->_hit < 0)
		this->_hit = 0;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy && this->_hit)
	{
		std::cout << "ClapTrap " << this->_name << " repairs itself for " \
		<< amount << " points." << std::endl;
		this->_hit += amount;
		if (this->_hit > 10)
			this->_hit = 10;
		this->_energy--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " cannot repairs itself," \
		<< " not enough energy or hit points..." << std::endl;

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
