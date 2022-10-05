#include "FragTrap.hpp"

int	main(void)
{

	{
		std::cout << " *** Attacking until energy points are depleted *** " \
		<< std::endl;
		FragTrap	ben("Ben");
		int			N(101);
		while (N--)
			ben.attack("you");
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to attack with an unnamed FragTrap *** " \
		<< std::endl;
		FragTrap	ben;
		ben.attack("you");
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to attack after taking too much damage *** " \
		<< std::endl;
		FragTrap	ben("Ben");
		ben.takeDamage(100);
		ben.attack("you");
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to attack with a FragTrap created by copy *** " \
		<< std::endl;
		FragTrap	ben("Ben");
		FragTrap	jam(ben);
		jam.attack("you");
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to repair after taking too much damage *** " \
		<< std::endl;
		FragTrap	ben("Ben");
		ben.takeDamage(100);
		ben.beRepaired(10);
	}

	{
		std::cout << std::endl;
		std::cout << " *** Taking damage then repairing fully *** " << std::endl;
		FragTrap	ben("Ben");
		std::cout << "Current hit points: " << ben.getHit() << std::endl;
		ben.takeDamage(50);
		std::cout << "Current hit points: " << ben.getHit() << std::endl;
		ben.beRepaired(50);
		std::cout << "Current hit points: " << ben.getHit() << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to attack an empty target *** " << std::endl;
		FragTrap	ben("Ben");
		ben.attack("");
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to repair after with no energy points left *** " \
		<< std::endl;
		FragTrap	ben("Ben");
		int			N(100);
		while (N--)
			ben.attack("you");
		ben.takeDamage(50);
		ben.beRepaired(50);
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to repair when at full hit points *** " \
		<< std::endl;
		FragTrap	ben("Ben");
		ben.beRepaired(10);
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to take damage before being named *** " << \
		std::endl;
		FragTrap	ben;
		ben.takeDamage(10);
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to take damage when already dead *** " << \
		std::endl;
		FragTrap	ben("Ben");
		ben.takeDamage(100);
		ben.takeDamage(100);
	}

	{
		std::cout << std::endl;
		std::cout << " *** Trying to enter Gate keeper mode *** " << std::endl;
		FragTrap	ben("Ben");
		ben.highFiveGuys();
	}
	
	return (0);
}
