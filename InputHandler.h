#pragma once

class ICommand;

class InputHandler {
public:
	ICommand* HandleInput() const;

	void AssignMoveLeftCommand2PressKeyA();
	void AssignMoveRightCommand2PressKeyD();

private:
	ICommand* pressKeyD_ = nullptr;
	ICommand* pressKeyA_ = nullptr;
};
