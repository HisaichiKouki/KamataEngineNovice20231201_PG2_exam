#include <Novice.h>
#include "Game.h"
#include "Title.h"
const char kWindowTitle[] = "LC1A_20_ヒサイチ_コウキ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	int windowX = 1280;
	int windowY = 720;
	Novice::Initialize(kWindowTitle, windowX, windowY);

	Game* game=nullptr;
	Title* title=new Title;

	bool change = false;
	bool isStart = false;

	float easeColorT = 0;
	int easeColor = 0;
	float easeColorC = 1;
	float easeColorMax = 120;

	bool easeStart = false;

	bool assignment = false;

	//bool True = true;
	//bool False = false;

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	InputManager::GetInstance()->Init();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		/*memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);*/
		InputManager::Update();
		///------------------///
		/// ↓更新処理ここから
		///------------------///
		if (InputManager::GetIsTriggerKey(DIK_RETURN))
		{
			
				isStart = true;
			
		}
		

		if (change == false)
		{
			title->Update();
			if (title->titleLetter->GetCurrentHP()<=0)
			{
			
					isStart = true;
				
				
			}

			
		}
		else if (change == true)
		{
			game->Update();
		}

		if (isStart)
		{
			if (easeColorT == easeColorMax / 2)
			{
				easeColorC = -1;
				assignment = true;
			}
			if (easeColorT < easeColorMax&& easeColorT>=0)
			{
				easeColorT += easeColorC * 2;
			}
			else if(easeColorT<0)
			{
				easeColorT = 0;
				easeColorC = 1;
				isStart = false;
				easeStart = false;
				easeColor = 0;
			}


			easeColor = (int)Easing::OutQuad(easeColorT, easeColorMax, 0, 315);
			if (easeColor>255)
			{
				easeColor = 255;
			}
		}
		if (assignment)
		{
			if (change == false)
			{

				delete title;
				title = nullptr;

				game = new Game;

			}
			else if (change == true)
			{

				delete game;
				game = nullptr;
				title = new Title;


			}

			change = !change;
			assignment = false;
			InputManager::GetInstance()->Init();

		}
		/*Novice::ScreenPrintf(0, 220, "easeColorT=%f", easeColorT);
		Novice::ScreenPrintf(0, 240, "easeColorC=%f", easeColorC);
		Novice::ScreenPrintf(0, 260, "isStart=%d", isStart);
		Novice::ScreenPrintf(0, 280, "easeColor=%d", easeColor);*/
		///------------------///
		/// ↑更新処理ここまで
		///------------------///

		///------------------///
		/// ↓描画処理ここから
		///------------------///

		if (change == false)
		{
			title->Draw();
		}
		else if (change == true)
		{
			game->Draw();
		}

		Novice::DrawBox(0, 0, windowX, windowY, 0, 0xffffff00 + easeColor, kFillModeSolid);

		///------------------///
		/// ↑描画処理ここまで
		///------------------///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
