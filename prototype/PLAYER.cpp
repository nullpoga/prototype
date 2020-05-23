/*
PLAYER.cpp
�T�v�F�v���[������N���Xa
�쐬���F2020/05/23
�X�V���F
*/

#include "pch.h"
#include "player.h"

PLAYER::PLAYER()
{
	//�摜�ǂݍ���
	GrPlayerHandle = LoadGraph("img/player.png");

	if (GrPlayerHandle == -1) {
		MSG("�v���[���摜�̓ǂݍ��݂ɃG���[���������܂����B");
	}

	width = 29;
	height = 40;

	//�ړ��W���̐ݒ�
	move = 1.0f;

	//�������Əc�����̃J�E���g��
	xcount = 0;
	ycount = 0;

	//�Y�����p�ϐ�
	ix = 0, iy = 0, result = 0;

	//�����ʒu
	x = 180;
	y = 400;

	life = true;

}
void PLAYER::Move()
{
	//�ړ��W���̐ݒ�
	//�����E���������ꂽ�ꍇ
	if (key[KEY_INPUT_LEFT] == 1 || key[KEY_INPUT_RIGHT] == 1) {

		if (key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1) {
			//�ړ��W����0.71�ɐݒ�
			move = 0.71f;
		}
		else {
			//�΂߂���Ȃ����1.0�ɐݒ�
			move = 1.0f;
		}
	}
	//�ォ�����������ꂽ�ꍇ
	else if (key[key[KEY_INPUT_UP] == 1 || key[KEY_INPUT_DOWN] == 1]) {
		move = 1.0f;
	}

	//���W�̌v�Z
	//�����������ꂽ�ꍇ
	if (key[KEY_INPUT_LEFT] == 1) {
		x -= (int)PLAYER_SPEED * move;

	}
	//�E���������ꂽ�ꍇ
	if (key[KEY_INPUT_RIGHT] == 1) {
		x += (int)PLAYER_SPEED * move;
	}
	//�オ�������ꂽ�ꍇ
	if (key[KEY_INPUT_UP] == 1) {
		y -= (int)PLAYER_SPEED * move;
	}
	//�����������ꂽ�ꍇ
	if (key[KEY_INPUT_DOWN] == 1) {
		y += (int)PLAYER_SPEED * move;
	}

}

void PLAYER::Draw() 
{
	//�����Ă���Ε`��
	if (life) {
		//�`��
		DrawGraph(x - width / 2, y - height / 2, GrPlayerHandle, TRUE);
	}
}

void PLAYER::All()
{
	Move();
	Draw();
}
