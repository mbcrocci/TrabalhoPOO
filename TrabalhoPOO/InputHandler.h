#pragma once
#include <map>
#include "Command.h"
class InputHandler
{
public:
	InputHandler ();
	~InputHandler ();

	bool isInitCommand ();
	bool isPlayCommand ();



private:
	std::map<std::string, Command> init_commands_ = {
		//{"dim", DimCommand},
		//{"moedas", CoinsCommand},
		//{"oponentes", OponentsCommand},
		//{"castelo", CastleCommand},
		//{"mkperfil", MakeProfileCommand},
		//{"addperfil", AddProfileCommand},
		//{"subperfil", RemoveTraitProfileCommand},
		//{"rmperfil", RemoveProfileCommand},
		//{"load", LoadCommand}
		//{"inicio", StartCommand }
	};
	std::map<std::string, Command> play_commands_ = {
		//{"foco",      SetViewCommand},
		//{"zoomout",   ZoomOutCommand},
		//{"setmoedas", SetCoinsCommand},
		//{"build",     Command},
		//{"list		Command},
		//{"listp		Command},
		//{"listallp",  ListAllCommand},
		//{"mkbuild     MakeBuildCommand},
		//{"repair      RepairCommand},
		//{"upgrade     UpgradeCommand},
		//{"sell		SellCommand},
		//{"ser			MakeBeeingCommand},
		//{"next		NextCommand},
		//{"nextn		NextNumCommand},
		//{"ataca		AttackCommand},
		//{"recolhe		Command},
		//{"fim			StopCommand},
		//{"save		SaveCommand},
		//{"restore		RestoreCommand},
		//{"erase		EraseCommand},
		//{"load		LoadCommand},
	};
};

