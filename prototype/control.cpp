/*
PLAYER.cpp
概要：コントロールクラス
作成日：2020/05/23
更新日：2020/05/25
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
	//描画領域を指定
	SetDrawArea(BACKGROUND_MARGIN, BACKGROUND_MARGIN, BACKGROUND_MARGIN + 600, BACKGROUND_MARGIN + 800);

	//背景インスタンスのAll関数実行
	back->All();

	//プレイヤクラスのAll関数実行
	player->All();

	

}