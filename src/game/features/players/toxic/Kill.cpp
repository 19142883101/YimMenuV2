#include "game/commands/PlayerCommand.hpp"

namespace YimMenu::Features
{
	class Kill : public PlayerCommand
	{
		using PlayerCommand::PlayerCommand;

		virtual void OnCall(Player player) override
		{
			if (auto ped = player.GetPed())
				ped.Kill();
		}
	};

	static Kill _Kill{"kill", "杀死玩家", "杀死目标玩家"};
}
