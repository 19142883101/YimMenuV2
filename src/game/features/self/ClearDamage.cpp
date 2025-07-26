#include "core/commands/Command.hpp"
#include "game/backend/Self.hpp"

namespace YimMenu::Features
{
	class ClearDamage : Command
	{
		using Command::Command;

		virtual void OnCall() override
		{
			Self::GetPed().ClearDamage();
		}
	};

	static ClearDamage _ClearDamage{"cleardamage", "清除损坏", "清除你身上所有的污垢和血迹"};
}
