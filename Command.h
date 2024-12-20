#pragma once

class Player;

class ICommand {
public:
	virtual ~ICommand() = default;
	virtual void Exec(Player& player) = 0;
};

class MoveRightCommand : public ICommand {
public:
	~MoveRightCommand() override = default;
	void Exec(Player& player) override;
};

class MoveLeftCommand : public ICommand {
public:
	~MoveLeftCommand() override = default;
	void Exec(Player& player) override;
};
