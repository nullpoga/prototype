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
	//�v���C���C���X�^���X�̐���
	player = new PLAYER;

	//�w�i�C���X�^���X�̐���
	back = new BACK;
}

CONTROL::~CONTROL()
{
	//�v���C���C���X�^���X�̊J��
	delete player;
	//�w�i�C���X�^���X�̊J��
	delete back;
}

void CONTROL::All()
{
	//�w�i�C���X�^���X��All�֐����s
	back->All();

	//�v���C���N���X��All�֐����s
	player->All();

	

}