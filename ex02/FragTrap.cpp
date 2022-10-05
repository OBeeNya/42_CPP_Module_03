#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_name = "";
	_hit = 100;
	_energy = 100;
	_attack = 30;
	return ;
}

FragTrap::FragTrap(const FragTrap &src)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
	return ;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap name constructor called" << std::endl;
	_name = name;
	_hit = 100;
	_energy = 100;
	_attack = 20;
	return ;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap default destructor called" << std::endl;
	return ;
}

FragTrap	&FragTrap::operator=(const FragTrap &rhs)
{
	this->_name = rhs.getName();
	this->_hit = rhs.getHit();
	this->_attack = rhs.getAttack();
	this->_energy = rhs.getEnergy();
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (target.empty())
		std::cout << "FragTrap " << this->_name << " needs a target to attack." \
		<< std::endl;
	else if (this->_energy && this->_hit && !this->_name.empty())
	{
		std::cout << "FragTrap " << this->_name << " attacks " << target << \
		", causing " << this->_attack << " points of damage!" << std::endl;
		this->_energy--;
	}
	else if (this->_name.empty())
		std::cout << "FragTrap cannot attack, this ClapTrap was not named " \
		"yet..." << std::endl;
	else if (!this->_hit)
		std::cout << "FragTrap " << this->_name << " cannot attack as it is " \
		<< "already dead..." << std::endl;
	else	
		std::cout << "FragTrap " << this->_name << " cannot attack, not " \
		<< "enough energy points..." << std::endl;
	return ;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hit && !this->_name.empty())
	{
		std::cout << "FragTrap " << this->_name << " takes " << amount << \
		" points of damage." << std::endl;
		this->_hit -= amount;
		if (this->_hit < 0)
			this->_hit = 0;
		if (!this->_hit)
			std::cout << "FragTrap " << this->_name << " has died." << std::endl;
	}
	else if (this->_name.empty())
		std::cout << "Nothing can happen to this FragTrap as it was not named" \
		<< " yet..." << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " is already dead..." \
		<< std::endl;
	return ;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (this->_energy && this->_hit && this->_hit != 100)
	{
		std::cout << "FragTrap " << this->_name << " repairs itself for " \
		<< amount << " points." << std::endl;
		this->_hit += amount;
		if (this->_hit > 100)
			this->_hit = 100;
		this->_energy--;
	}
	else if (this->_hit == 100)
		std::cout << "FragTrap " << this->_name << " cannot repair itself " \
		<< "as it already has full hit points." << std::endl;
	else if (!this->_energy)
		std::cout << "FragTrap " << this->_name << " cannot repair itself," \
		<< " not enough energy points..." << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " cannot repair itself as" \
		<< " it is already dead..." << std::endl;
	return ;
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << this->_name << " is asking for your best high five." \
	<< std::endl;
	return ;
}
