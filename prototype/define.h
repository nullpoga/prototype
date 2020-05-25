/*
define.h
�T�v�F��`�w�b�_
�쐬���F2020/05/23
�X�V���F2020/05/24
*/

#pragma once
#include <windows.h>

//�v���C���̕����X�s�[�h
#define PLAYER_SPEED 4

//���b�Z�[�W�{�b�N�X
#define MSG(m){\
	MessageBox(NULL,m,"���b�Z�[�W", MB_OK);}

#define WINDOW_SIZE_X 600
#define WINDOW_SIZE_Y 800

#define PLAYER_MARGIN_X 32
#define PLAYER_MARGIN_Y 0

#define BACKGROUND_MARGIN 0

#define PSHOT_NUM 20 //���@�e�̍ő吔
#define PSHOT_SPEED 18 //���@�e�̈ړ����x

//extern�錾����key�z��ɂǂ�����ł��A�N�Z�X�ł���悤�ɂ���
extern char key[256];

struct SHOT {
	bool flag; //�e�����˒����ǂ���
	double x; //x���W
	double y; //y���W
	int gh; //�O���t�B�b�N�n���h��
	int width, height; //�摜�̕��ƍ���
};

