/*
PLAYER.cpp
�T�v�F�v���[������N���X
�쐬���F2020/05/23
�X�V���F2020/05/26
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

	width = 64;
	height = 64;

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

	//�����Ă��邩�ǂ���
	life = true;

	//�e������
	memset(shot, 0, sizeof(shot));

	//�e�摜�ǂݍ���
	int shotImg = LoadGraph("img/shot.png");
	int w, h;
	GetGraphSize(shotImg, &w, &h);

	//�t���O��S��false�ɂ��Ƃ�
	//�O���t�B�b�N�n���h���Ɖ摜�̃T�C�Y�������Ƃ�
	for (int i = 0; i < PSHOT_NUM; ++i) {
		shot[i].flag = false;
		shot[i].gh = shotImg;
		shot[i].width = w;
		shot[i].height = h;
	}

	count = 0;

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

	//�L�����̈ړ�����
	if (x > WINDOW_SIZE_X - PLAYER_MARGIN_X) {
		x = WINDOW_SIZE_X - PLAYER_MARGIN_X;
	}
	else if (x < PLAYER_MARGIN_X) {
		x = PLAYER_MARGIN_X;
	}

	if (y > 800 - height / 2 - PLAYER_MARGIN_Y) {
		y = 800 - height / 2 - PLAYER_MARGIN_Y;
	}
	else if(y<height/2+PLAYER_MARGIN_Y){
		y = height / 2 + PLAYER_MARGIN_Y;
	}

}

void PLAYER::Draw() 
{
	//���@�e�̕`��
	for (int i = 0; i < PSHOT_NUM; ++i) {
		//���@�e���������Ă���ꍇ�`����s���B
		if (shot[i].flag) {
			DrawGraph(shot[i].x - shot[i].width / 2, shot[i].y - shot[i].height / 2, shot[i].gh, TRUE);
		}
	}

	//�����Ă���Ε`��
	if (life) {
		//�`��
		DrawGraph(x - width / 2, y - height / 2, GrPlayerHandle, TRUE);
	}
}

void PLAYER::Shot()
{
	//�L�[����������Ă��邩�A6���[�v��1�񔭎�
	if (key[KEY_INPUT_Z] == 1 && count % 4 == 0) {
		for (int i = 0; i < PSHOT_NUM; ++i) {
			//shot[i]����ʓ��ɂ��Ȃ��ꍇ
			if (shot[i].flag == false) {
				shot[i].flag = true;
				shot[i].x = x;
				shot[i].y = y;
				break;
			}
		}
	}

	//�e���ړ������鏈��
	for (int i = 0; i < PSHOT_NUM; ++i) {
		//���˂��Ă���e����������
		if (shot[i].flag) {
			shot[i].y -= PSHOT_SPEED;

			//��ʊO�ɂ݂͂�������t���O��߂�
			if (shot[i].y < -10) {
				shot[i].flag = false;
			}
		}

	}

}

void PLAYER::All()
{
	Move();
	Shot();
	Draw();

	++count;
}
