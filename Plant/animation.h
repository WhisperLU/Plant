#pragma once
#ifndef _ANIMATION_H_
#define _ANIMATION_H_
#include "atlas.h"
#include "util.h"
#include "camera.h"

#include <functional>
#include <graphics.h>

class Animation
{
public:
	Animation() = default;
	~Animation() = default;

	void reset()
	{
		timer = 0;
		idx_frame = 0;
	}

	void set_atlas(Atlas* new_atlas)
	{
		reset();
		atlas = new_atlas;
	}

	void set_loop(bool flag)
	{
		is_loop = flag;
	}

	void set_interval(int ms)
	{
		interval = ms;
	}

	int get_idx_frame()
	{
		return idx_frame;
	}

	IMAGE* get_frame()
	{
		return atlas->get_image(idx_frame);
	}

	bool check_finished()// 是否动画播放结束
	{
		if (is_loop) return false;

		return (idx_frame == atlas->get_size() - 1);
	}

	void set_callback(std::function<void()> callback)
	{
		this->callback = callback;
	}

	void on_update(int delta)// 更新动画
	{
		timer += delta;
		if (timer > interval)
		{
			timer = 0;
			idx_frame++;
			if (idx_frame >= atlas->get_size())
			{
				idx_frame = is_loop ? 0 : atlas->get_size() - 1;

				if (!is_loop && callback)
				{
					callback();
				}
			}
		}
	}

	void on_draw(const Camera& camera, int x, int y) const // 绘制动画
	{
		putimage_alpha(camera, x, y, atlas->get_image(idx_frame));
	}



private:
	int timer = 0;       // 计时器 
	int interval = 0;    // 帧间隔
	int idx_frame = 0;   // 帧索引
	bool is_loop = true; // 是否循环
	Atlas* atlas = nullptr;
	std::function<void()> callback;// 动画结束回调
};

#endif // !_ANIMATION_H_
