/*
main.cpp
�T�v�F���C���N���X
�쐬���F2020/05/23
�X�V���F
*/

#include "pch.h"
#include "control.h"

//�L�[�擾�p�z��
char key[256];

//�v���O������WinMain������s
int WINAPI WinMain(HINSTANCE hINstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1) //DX���C�u��������������
	{
		return -1; //�G���[���N�����璼���ɏI��
	}

	//�R���g���[�������̃C���X�^���X����
	CONTROL* control = new CONTROL;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0) {
		control->All();
	}

	DxLib_End(); //DX���C�u�����d�l�̏I������
	return 0; //�\�t�g�̏I��
}