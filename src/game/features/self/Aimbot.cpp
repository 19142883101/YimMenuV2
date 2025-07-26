#include "core/commands/BoolCommand.hpp"
#include "game/pointers/Pointers.hpp"

namespace YimMenu::Features
{
	class Aimbot : public BoolCommand
	{
		using BoolCommand::BoolCommand;

		virtual void OnEnable() override
		{
			Pointers.ShouldNotTargetEntityPatch->Apply();
			Pointers.GetAssistedAimTypePatch->Apply();
		}

		virtual void OnDisable() override
		{
			Pointers.ShouldNotTargetEntityPatch->Restore();
			Pointers.GetAssistedAimTypePatch->Restore();
		}
	};

	class AimbotAimForHead : BoolCommand
	{
		using BoolCommand::BoolCommand;

		virtual void OnEnable() override
		{
			Pointers.GetLockOnPosPatch->Apply();
		}

		virtual void OnDisable() override
		{
			Pointers.GetLockOnPosPatch->Restore();
		}
	};

	class AimbotTargetDrivers : BoolCommand
	{
		using BoolCommand::BoolCommand;

		virtual void OnEnable() override
		{
			Pointers.ShouldAllowDriverLockOnPatch->Apply();
		}

		virtual void OnDisable() override
		{
			Pointers.ShouldAllowDriverLockOnPatch->Restore();
		}
	};

	static Aimbot _Aimbot{"aimbot", "锁定", "锁定敌人和其他玩家"};
	static AimbotAimForHead _AimbotAimForHead{"aimbotaimforhead", "瞄准头部", "锁定敌人和其他玩家时瞄准头部"};
	static AimbotTargetDrivers _AimbotTargetDrivers{"aimbottargetdrivers", "目标驱动因素", "允许瞄准机器人锁定敌人和载具中的其他玩家"};
}
