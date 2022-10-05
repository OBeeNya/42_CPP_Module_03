#include "ScavTrap.hpp"

int	main(void)
{

	{
		std::cout << " *** Attacking until energy points are depleted *** " \
		<< std::endl;
		ScavTrap	ben("Ben");
		int			N(51);
		while (N--)
			ben.attack("you");
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to attack with an unnamed ScavTrap *** " \
		<< std::endl;
		ScavTrap	ben;
		ben.attack("you");
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to attack after taking too much damage *** " \
		<< std::endl;
		ScavTrap	ben("Ben");
		ben.takeDamage(100);
		ben.attack("you");
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to attack with a ScavTrap created by copy *** " \
		<< std::endl;
		ScavTrap	ben("Ben");
		ScavTrap	jam(ben);
		jam.attack("you");
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to repair after taking too much damage *** " \
		<< std::endl;
		ScavTrap	ben("Ben");
		ben.takeDamage(100);
		ben.beRepaired(10);
	}

	{
		std::cout << std::endl;
		std::cout << " *** Taking damage then repairing fully *** " << std::endl;
		ScavTrap	ben("Ben");
		std::cout << "Current hit points: " << ben.getHit() << std::endl;
		ben.takeDamage(50);
		std::cout << "Current hit points: " << ben.getHit() << std::endl;
		ben.beRepaired(50);
		std::cout << "Current hit points: " << ben.getHit() << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to attack an empty target *** " << std::endl;
		ScavTrap	ben("Ben");
		ben.attack("");
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to repair after with no energy points left *** " \
		<< std::endl;
		ScavTrap	ben("Ben");
		int			N(50);
		while (N--)
			ben.attack("you");
		ben.takeDamage(50);
		ben.beRepaired(50);
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to repair when at full hit points *** " \
		<< std::endl;
		ScavTrap	ben("Ben");
		ben.beRepaired(10);
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to take damage before being named *** " << \
		std::endl;
		ScavTrap	ben;
		ben.takeDamage(10);
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to take damage when already dead *** " << \
		std::endl;
		ScavTrap	ben("Ben");
		ben.takeDamage(100);
		ben.takeDamage(100);
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to enter Gate keeper mode *** " << std::endl;
		ScavTrap	ben("Ben");
		ben.guardGate();
	}
	
	return (0);
}
