#include "ClapTrap.hpp"

int	main(void)
{

	{
		std::cout << " *** Attacking until energy points are depleted *** " \
		<< std::endl;
		ClapTrap	ben("Ben");
		int			N(11);
		while (N--)
			ben.attack("you");
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to attack with an unnamed ClapTrap *** " \
		<< std::endl;
		ClapTrap	ben;
		ben.attack("you");
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to attack after taking too much damage *** " \
		<< std::endl;
		ClapTrap	ben("Ben");
		ben.takeDamage(10);
		ben.attack("you");
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to attack with a ClapTrap created by copy *** " \
		<< std::endl;
		ClapTrap	ben("Ben");
		ClapTrap	jam(ben);
		jam.attack("you");
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to repair after taking too much damage *** " \
		<< std::endl;
		ClapTrap	ben("Ben");
		ben.takeDamage(10);
		ben.beRepaired(10);
	}

	{
		std::cout << std::endl;
		std::cout << " *** Taking damage then repairing fully *** " << std::endl;
		ClapTrap	ben("Ben");
		std::cout << "Current hit points: " << ben.getHit() << std::endl;
		ben.takeDamage(5);
		std::cout << "Current hit points: " << ben.getHit() << std::endl;
		ben.beRepaired(5);
		std::cout << "Current hit points: " << ben.getHit() << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to attack an empty target *** " << std::endl;
		ClapTrap	ben("Ben");
		ben.attack("");
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to repair after with no energy points left *** " \
		<< std::endl;
		ClapTrap	ben("Ben");
		int			N(10);
		while (N--)
			ben.attack("you");
		ben.takeDamage(5);
		ben.beRepaired(5);
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to repair when at full hit points *** " \
		<< std::endl;
		ClapTrap	ben("Ben");
		ben.beRepaired(1);
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to take damage before being named *** " << \
		std::endl;
		ClapTrap	ben;
		ben.takeDamage(1);
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to take damage when already dead *** " << \
		std::endl;
		ClapTrap	ben("Ben");
		ben.takeDamage(10);
		ben.takeDamage(10);
	}
	
	return (0);
}
