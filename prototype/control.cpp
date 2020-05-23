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
	//プレイヤインスタンスの生成
	player = new PLAYER;

	//背景インスタンスの生成
	back = new BACK;
}

CONTROL::~CONTROL()
{
	//プレイヤインスタンスの開放
	delete player;
	//背景インスタンスの開放
	delete back;
}

void CONTROL::All()
{
	//背景インスタンスのAll関数実行
	back->All();

	//プレイヤクラスのAll関数実行
	player->All();

	

}