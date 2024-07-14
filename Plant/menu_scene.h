#pragma once
#ifndef _MENU_SCENE_H_
#define _MENU_SCENE_H_
#include "scene.h"
#include "atlas.h"
#include "camera.h"
#include "animation.h"
#include "scene_manager.h"

#include <iostream>

//extern Atlas atlas_peashooter_run_right;
//
extern SceneManager scene_manager;

extern IMAGE img_menu_background;

class MenuScene : public Scene
{
public:
	MenuScene() = default;
	~MenuScene() = default;

	void on_enter()
	{
		////std::cout << "�������˵�" << std::endl;
		//animation_peashooter_run_right.set_atlas(&atlas_peashooter_run_right);
		//animation_peashooter_run_right.set_interval(75);
		//animation_peashooter_run_right.set_loop(true);

		////animation_peashooter_run_right.set_callback(
		////	[]()
		////	{
		////		scene_manager.switch_to(SceneManager::SceneType::Game);
		////	}
		////);// lambda�������������Ž������л���������Ϸ����

		mciSendString(_T("play bgm_menu repeat from 0"), NULL, 0, NULL);
	}

	void on_update(int delta)
	{
		////std::cout << "���˵���������" << std::endl;
		//camera.on_update(delta);
		//animation_peashooter_run_right.on_update(delta);
	}

	void on_draw(const Camera& camera)
	{
		////outtextxy(10, 10, _T("���˵���ͼ����"));
		//const Vector2& pos_camera = camera.get_position();
		//animation_peashooter_run_right.on_draw((int)(100 - pos_camera.x), (int)(100 - pos_camera.y));


		putimage(0, 0, &img_menu_background);
	}

	void on_input(const ExMessage& msg)
	{
		//if (msg.message == WM_KEYDOWN)
		//{
		//	//scene_manager.switch_to(SceneManager::SceneType::Game);// �л��ص�����Ϸ����
		//	camera.shake(10, 350);
		//}

		if (msg.message == WM_KEYUP)
		{
			mciSendString(_T("play ui_confirm from 0"), NULL, 0, NULL);
			scene_manager.switch_to(SceneManager::SceneType::Selector);// ��ת����ɫѡ�����
		}

	}

	void on_exit()
	{
		//std::cout << "���˵��˳�" << std::endl;
	}

private:
	Camera camera;
	Animation animation_peashooter_run_right;


};


#endif // !_MENU_SCENE_H_
