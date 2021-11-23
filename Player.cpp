#include <iostream>

#include "Player.h"

bool Player::isHitting() const {
	std::string answer;
	std::cout << "Do you need one more card ?\n";
	std::cin >> answer;

	/*while (answer != "y" || answer != "yes" || answer != "Yes" || answer != "+" || answer != "1" || answer != "n" || answer != "no" || answer != "No" || answer != "-" || answer != "0") {
		std::cout << "Please, enter your answer Yes or No:\n";
		std::cin >> answer;
		std::cout << "You entered " << answer << std::endl;
	}*/
	if (answer == "yes" || answer == "Yes" || answer == "+" || answer == "1") {
		return true;
	}
	else
	{
		return false;
	}
};

void Player::Win() const {
	std::cout << "Congratulations !!! You, " << getName() << ", won ! :)";
};

void Player::Lose() const {
	std::cout << "So sorry, but, " << getName() << ", you loose at this time :(";
};

void Player::Push() const {
	std::cout << "Not so bad. You, " << getName() << "played a draw. Will luck next time.";
};
