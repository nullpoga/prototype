/*
main.cpp
概要：メインクラス
作成日：2020/05/23
更新日：
*/

#include "pch.h"
#include "control.h"

//キー取得用配列
char key[256];

//プログラムはWinMainから実行
int WINAPI WinMain(HINSTANCE hINstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// ウインドウモードで起動
	ChangeWindowMode(TRUE);

	// ウインドウのサイズを手動ではできず、且つウインドウのサイズに合わせて拡大もしないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// とりあえず画面大きい方がいいので一旦大きくしておく
	SetGraphMode(1280, 1024, 32);

	if (DxLib_Init() == -1) //DXライブラリ初期化処理
	{
		return -1; //エラーが起きたら直ちに終了
	}

	//コントロール部分のインスタンス生成
	CONTROL* control = new CONTROL;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && GetHitKeyStateAll(key) == 0) {
		control->All();
	}

	DxLib_End(); //DXライブラリ仕様の終了処理
	return 0; //ソフトの終了
}