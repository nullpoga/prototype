/*
back.cpp
�T�v�F�w�i�N���X
�쐬���F2020/05/23
�X�V���F2020/05/24
*/

#include "pch.h"
#include "back.h"

BACK::BACK() {
	gh = LoadGraph("img/back.png");
	x = y = BACKGROUND_MARGIN;
}

void BACK::Draw()
{
	DrawGraph(x, y, gh, FALSE);
}

void BACK::All()
{
	Draw();
}

