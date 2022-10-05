#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	ben("Ben");
	int			N(11);
	
	while (N--)
		ben.attack("you");

	return (0);
}
