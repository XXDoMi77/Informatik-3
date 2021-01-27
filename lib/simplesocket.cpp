#include "simplesocket.h"

string ImprovedTCPserver::myResponse(string input)
{
	//write incoming message to _lastResponse so that Menu can read it
	for (int i = 0; i <= glset::bufferSize; i++)
	{
		//check if the character is a letter or a number or a punctuation and only write char if true
		if (isalpha(input[i]) || isdigit(input[i]) || ispunct(input[i]))
		{
			//write char one by one
			_latestMsg[i] = input[i];
		}
		else
		{
			//otherwise if char is not a digit... fill with '_'
			_latestMsg[i] = '_';
		}
	}

	//check for shoot command
	if (input[0] == 's' &&
		input[1] == 'h' &&
		input[2] == 'o' &&
		input[3] == 'o' &&
		input[4] == 't' &&
		input[5] == '(' &&
		isdigit(input[6]) && //check if x coordinate is number
		isdigit(input[7]) && //check if x coordinate is number
		input[8] == ';' &&
		isdigit(input[9]) &&  //check if y coordinate is number
		isdigit(input[10]) && //check if y coordinate is number
		input[11] == ')' &&
		(stoi(input.substr(6)) >= 0) &&	 //check if shot is withing the board, should later be checked againt value in settings
		(stoi(input.substr(6)) <= 10) && //check if shot is withing the board, should later be checked againt value in settings
		(stoi(input.substr(9)) >= 0) &&	 //check if shot is withing the board, should later be checked againt value in settings
		(stoi(input.substr(9)) <= 10)	 //check if shot is withing the board, should later be checked againt value in settings
	)
	{
		//shoots and writes result into _shootResult
		TASK3::ShootResult _shootResult = _world->shoot(stoi(input.substr(6)), stoi(input.substr(9)));

		switch (_shootResult)
		{
		case TASK3::WATER:
			return "~\n";
			break;

		case TASK3::SHIP_HIT:
			return "x\n";
			break;

		case TASK3::SHIP_DESTROYED:
			return "x\n";
			break;

		case TASK3::ALL_SHIPS_DESTROYED:
			return "f\n";
			break;

		case TASK3::GAME_OVER:
			return "f\n";
			break;
		}
	}
	//check for new_game command
	if (input[0] == 'n' &&
		input[1] == 'e' &&
		input[2] == 'w' &&
		input[3] == '_' &&
		input[4] == 'g' &&
		input[5] == 'a' &&
		input[6] == 'm' &&
		input[7] == 'e')
	{
		//delete already existing World
		delete (_world);
		//create new instance of World
		_world = new TASK3::World;
		//return new world generated
		return "new_world_generated\n";
	}
	return string("invalid_command\n");
}

string ImprovedTCPserver::get_latest_inc_msg()
{
	return _latestMsg;
}
