/*
define.h
�T�v�F��`�w�b�_
�쐬���F2020/05/23
�X�V���F
*/

#pragma once
#include <windows.h>

//�v���C���̕����X�s�[�h
#define PLAYER_SPEED 4

//���b�Z�[�W�{�b�N�X
#define MSG(m){\
	MessageBox(NULL,m,"���b�Z�[�W", MB_OK);}

//extern�錾����key�z��ɂǂ�����ł��A�N�Z�X�ł���悤�ɂ���
extern char key[256];
