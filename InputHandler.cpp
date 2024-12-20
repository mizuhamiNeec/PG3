#include "InputHandler.h"
#include "Command.h"
#include "Input.h"

ICommand* InputHandler::HandleInput() const {
	if (Input::GetInstance()->PushKey(DIK_D)) {
		return pressKeyD_;
	}
	if (Input::GetInstance()->PushKey(DIK_A)) {
		return pressKeyA_;
	}
	return nullptr;
}

void InputHandler::AssignMoveLeftCommand2PressKeyA() {
	ICommand* command = new MoveLeftCommand();
	pressKeyA_ = command;
}

void InputHandler::AssignMoveRightCommand2PressKeyD() {
	ICommand* command = new MoveRightCommand();
	pressKeyD_ = command;
}
