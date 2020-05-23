/*
PLAYER.cpp
概要：コントロールクラス
作成日：2020/05/23
更新日：
*/

#include "pch.h"
#include "control.h"

CONTROL::CONTROL()
{
	//プレイヤクラスの生成
	player = new PLAYER;
}

CONTROL::~CONTROL()
{
	//プレイヤクラスの開放
	delete player;
}

void CONTROL::All()
{
	//プレイヤクラスのAll関数実行
	player->All();
}