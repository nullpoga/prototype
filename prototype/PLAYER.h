/*
PLAYER.h
�T�v�F�v���[���w�b�_
�쐬���F2020/05/23
�X�V���F
*/

#pragma once
class PLAYER {
private:
	//X���W Y���W
	double x, y;

	//�摜��
	int width, height;

	//�O���t�B�b�N�n���h���i�[�p�z��
	int gh[12];

	//�ړ��W��
	float move;

	//�������Əc�����̃J�E���g��
	int xcount, ycount;
	//�Y�����p�ϐ�
	int ix, iy, result;
	//�����t���O
	bool life;

	//�v���C���摜
	int GrPlayerHandle;

private:
	void Move();
	void Draw();

public:
	PLAYER();
	void All();

};