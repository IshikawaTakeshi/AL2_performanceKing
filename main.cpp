#include <Novice.h>
#include "Player.h"
#include "PlayerParticle.h"
#include "Cloud.h"
#include "Rain.h"
#include "ShockWave.h"

const char kWindowTitle[] = "AL2_02_イシカワタケシ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player *player = new Player({ 640,400 }, { 70,70 }, { 255,255,255,255 }, true);

	PlayerParticle *pParticle[10];
	for (int i = 0; i < 10; i++) {
		pParticle[i] = new PlayerParticle(player);
	}

	ShockWave *shockWaveLeft[5];
	for (int i = 0; i < 5; i++) {
		shockWaveLeft[i] = new ShockWave({ 5,0 });
	}

	Cloud *cloud[5];
	cloud[0] = new Cloud({ 640,100 }, { 70,50 }, { 255,255,255,255 });
	cloud[1] = new Cloud({ 590,100 }, { 70,50 }, { 255,255,255,255 });
	cloud[2] = new Cloud({ 690,100 }, { 70,50 }, { 255,255,255,255 });
	cloud[3] = new Cloud({ 620,70 }, { 70,50 }, { 255,255,255,255 });
	cloud[4] = new Cloud({ 680,70 }, { 70,50 }, { 255,255,255,255 });

	Rain *rain[100];
	for (int i = 0; i < 100; i++) {
		rain[i] = new Rain();
	}


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		//Rキーを入力時初期化
		if (keys[DIK_R] && preKeys[DIK_R] == 0) {
			player = new Player({ 640,400 }, { 70,70 }, { 255,255,255,255 }, true);
			cloud[0] = new Cloud({ 640,100 }, { 70,50 }, { 255,255,255,255 });
			cloud[1] = new Cloud({ 590,100 }, { 70,50 }, { 255,255,255,255 });
			cloud[2] = new Cloud({ 690,100 }, { 70,50 }, { 255,255,255,255 });
			cloud[3] = new Cloud({ 620,70 }, { 70,50 }, { 255,255,255,255 });
			cloud[4] = new Cloud({ 680,70 }, { 70,50 }, { 255,255,255,255 });
			for (int i = 0; i < 10; i++) {
				pParticle[i] = new PlayerParticle(player);
			}
		}


		//プレイヤーの更新処理
		player->Update(keys);

		//プレイヤーの残像の更新処理
		for (int i = 0; i < 10; i++) {
			if (pParticle[i]->GetIsAlive() == false) {
				pParticle[i]->Spawn();
				break;
			}
		}
		
		for (int i = 0; i < 10; i++) {
			pParticle[i]->Update();
		}
		//雲の更新処理
		for (int i = 0; i < 5; i++) {
			cloud[i]->Update();
		}
		//雨の更新処理
		for (int i = 0; i < 100; i++) {
			if (rain[i]->GetIsAlive() == false) {
				rain[i]->Spawn(*cloud[i % 5]);
				break;
			}
		}

		for (int i = 0; i < 100; i++) {
			rain[i]->Update();
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		Novice::DrawBox(0, 0, 1280, 720, 0.0f, 0xf7b977ff, kFillModeSolid);
		Novice::DrawLine(0, 470, 1280, 470, 0x000000ff);

		for (int i = 0; i < 10; i++) {
			pParticle[i]->Draw();
		}

		player->Draw();

		for (int i = 0; i < 5; i++) {
			cloud[i]->Draw();
		}

		for (int i = 0; i < 100; i++) {
			rain[i]->Draw();
		}

		///
		/// ↑描画処理ここまで
		///

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
