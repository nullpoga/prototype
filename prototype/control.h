/*
control.h
�T�v�F�R���g���[���w�b�_
�쐬���F2020/05/23
�X�V���F2020/05/24
*/


#pragma once
#include "player.h"
#include "back.h"

class CONTROL {
private:
	//�v���C���N���X�̃|�C���^
	PLAYER *player;

	//�w�i�N���X�̃|�C���^
	BACK *back;

public:
	CONTROL();
	~CONTROL();
	void All();
};