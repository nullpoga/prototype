/*
back.cpp
概要：背景クラス
作成日：2020/05/23
更新日：2020/05/24
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

