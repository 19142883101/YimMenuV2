#include "core/commands/Command.hpp"
#include "game/gta/Pools.hpp"

namespace YimMenu::Features
{
	class KillAll : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			for (auto ped : Pools::GetPeds())
			{
				if (!ped.IsPlayer())
					ped.Kill();
			}
		}
	};

	class KillAllEnemies : public Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			for (auto ped : Pools::GetPeds())
			{
				if (!ped.IsPlayer() && ped.IsEnemy())
					ped.Kill();
			}
		}
	};

	static KillAll _KillAll{"killallpeds", "杀死所有行人", "杀死游戏世界中所有行人"};
	static KillAllEnemies _KillAllEnemies{"killallenemies", "杀死所有敌人", "杀死游戏世界中所有敌人"};
}
