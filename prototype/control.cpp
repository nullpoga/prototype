/*
PLAYER.cpp
�T�v�F�R���g���[���N���X
�쐬���F2020/05/23
�X�V���F
*/

#include "pch.h"
#include "control.h"

CONTROL::CONTROL()
{
	//�v���C���N���X�̐���
	player = new PLAYER;
}

CONTROL::~CONTROL()
{
	//�v���C���N���X�̊J��
	delete player;
}

void CONTROL::All()
{
	//�v���C���N���X��All�֐����s
	player->All();
}